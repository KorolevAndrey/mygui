/*!
	@file
	@author		Albert Semenov
	@date		05/2009
*/

#include "Precompiled.h"
#include "BaseManager.h"
#include <MyGUI_DummyPlatform.h>

#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
#	include <windows.h>
#	include <winuser.h>
#endif

const char* WND_CLASS_NAME = "MyGUIBaseManagerWndClass";

LRESULT CALLBACK DXWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_CREATE:
		{
			SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)((LPCREATESTRUCT)lParam)->lpCreateParams);
			break;
		}

		case WM_SIZE:
		{
			if (wParam != SIZE_MINIMIZED)
			{
				base::BaseManager* baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
				if (baseManager)
					baseManager->_windowResized();
			}
			break;
		}

		case WM_CLOSE:
		{
			base::BaseManager* baseManager = (base::BaseManager*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
			if (baseManager)
				baseManager->quit();
		}

		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}

		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
	return 0;
}

namespace base
{
	BaseManager::BaseManager() :
		mGUI(nullptr),
		mPlatform(nullptr),
		hWnd(0),
		hInstance(nullptr),
		mExit(false)
	{
	}

	void BaseManager::_windowResized()
	{
		RECT rect = { 0, 0, 0, 0 };
		GetClientRect(hWnd, &rect);
		int width = rect.right - rect.left;
		int height = rect.bottom - rect.top;

		if (mPlatform)
			MyGUI::RenderManager::getInstance().setViewSize(width, height);

		setInputViewSize(width, height);
	}

	bool BaseManager::create(int _width, int _height)
	{
		const unsigned int width = _width;
		const unsigned int height = _height;

		// регистрируем класс окна
		WNDCLASS wc =
		{
			0, (WNDPROC)DXWndProc, 0, 0, GetModuleHandle(nullptr), LoadIcon(nullptr, MAKEINTRESOURCE(1001)),
			LoadCursor(nullptr, IDC_ARROW), (HBRUSH)GetStockObject(BLACK_BRUSH), nullptr, TEXT(WND_CLASS_NAME),
		};
		RegisterClass(&wc);

		// создаем главное окно
		hWnd = CreateWindow(wc.lpszClassName, TEXT("Dummy Render Window"), WS_OVERLAPPED | WS_SYSMENU,
			(GetSystemMetrics(SM_CXSCREEN) - width) / 2, (GetSystemMetrics(SM_CYSCREEN) - height) / 2, width, height, GetDesktopWindow(), nullptr, wc.hInstance, this);
		if (!hWnd)
		{
			return false;
		}

		ShowWindow(hWnd, SW_NORMAL);

	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		char buf[MAX_PATH];
		::GetModuleFileNameA(0, (LPCH)&buf, MAX_PATH);
		HINSTANCE instance = ::GetModuleHandleA(buf);
		HICON hIconSmall = static_cast<HICON>(LoadImage(instance, MAKEINTRESOURCE(1001), IMAGE_ICON, 32, 32, LR_DEFAULTSIZE));
		HICON hIconBig = static_cast<HICON>(LoadImage(instance, MAKEINTRESOURCE(1001), IMAGE_ICON, 256, 256, LR_DEFAULTSIZE));
		if (hIconSmall)
			::SendMessageA(hWnd, WM_SETICON, 0, (LPARAM)hIconSmall);
		if (hIconBig)
			::SendMessageA(hWnd, WM_SETICON, 1, (LPARAM)hIconBig);
	#endif

		hInstance = wc.hInstance;

		createGui();

		createInput((size_t)hWnd);

		createPointerManager((size_t)hWnd);

		createScene();

		_windowResized();

		return true;
	}

	void BaseManager::run()
	{
		MSG msg;
		while (true)
		{
			while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			if (mExit)
				break;
			else if (msg.message == WM_QUIT)
				break;

			captureInput();

			if (GetActiveWindow() != hWnd)
				::Sleep(50);
		}
	}

	void BaseManager::destroy()
	{
		destroyScene();

		destroyPointerManager();

		destroyInput();

		destroyGui();

		if (hWnd)
		{
			DestroyWindow(hWnd);
			hWnd = 0;
		}

		UnregisterClass(WND_CLASS_NAME, hInstance);
	}

	void BaseManager::setupResources()
	{
	}

	void BaseManager::createGui()
	{
		mPlatform = new MyGUI::DummyPlatform();
		mPlatform->initialise();

		setupResources();

		mGUI = new MyGUI::Gui();
		mGUI->initialise("");
	}

	void BaseManager::destroyGui()
	{
		if (mGUI)
		{
			mGUI->shutdown();
			delete mGUI;
			mGUI = nullptr;
		}

		if (mPlatform)
		{
			mPlatform->shutdown();
			delete mPlatform;
			mPlatform = nullptr;
		}
	}
    
    void BaseManager::setWindowMaximized(bool _value)
	{
	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		if (_value)
		{
			size_t handle = getWindowHandle();
			::ShowWindow((HWND)handle, SW_SHOWMAXIMIZED);
		}
	#endif
	}
    
    bool BaseManager::getWindowMaximized()
	{
		bool result = false;
	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		size_t handle = getWindowHandle();
		result = ::IsZoomed((HWND)handle) != 0;
	#endif
		return result;
	}

	void BaseManager::setWindowCoord(const MyGUI::IntCoord& _value)
	{
	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		if (_value.empty())
			return;

		MyGUI::IntCoord coord = _value;
		if (coord.left < 0)
			coord.left = 0;
		if (coord.top < 0)
			coord.top = 0;
		if (coord.width < 640)
			coord.width = 640;
		if (coord.height < 480)
			coord.height = 480;
		if (coord.width > GetSystemMetrics(SM_CXSCREEN))
			coord.width = GetSystemMetrics(SM_CXSCREEN);
		if (coord.height > GetSystemMetrics(SM_CYSCREEN))
			coord.height = GetSystemMetrics(SM_CYSCREEN);
		if (coord.right() > GetSystemMetrics(SM_CXSCREEN))
			coord.left = GetSystemMetrics(SM_CXSCREEN) - coord.width;
		if (coord.bottom() > GetSystemMetrics(SM_CYSCREEN))
			coord.top = GetSystemMetrics(SM_CYSCREEN) - coord.height;

		size_t handle = getWindowHandle();
		::MoveWindow((HWND)handle, coord.left, coord.top, coord.width, coord.height, true);
	#endif
	}

	MyGUI::IntCoord BaseManager::getWindowCoord()
	{
		MyGUI::IntCoord result;
	#if MYGUI_PLATFORM == MYGUI_PLATFORM_WIN32
		size_t handle = getWindowHandle();
		::RECT rect;
		::GetWindowRect((HWND)handle, &rect);
		result.left = rect.left;
		result.top = rect.top;
		result.width = rect.right - rect.left;
		result.height = rect.bottom - rect.top;
	#endif
		return result;
	}
    
	size_t BaseManager::getWindowHandle()
	{
		return (size_t)hWnd;
	}

	void BaseManager::setWindowCaption(const std::wstring& _text)
	{
		SetWindowTextW(hWnd, _text.c_str());
	}

	void BaseManager::prepare()
	{
	}

	void BaseManager::addResourceLocation(const std::string& _name, bool _recursive)
	{
	}

	void BaseManager::injectMouseMove(int _absx, int _absy, int _absz)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMouseMove(_absx, _absy, _absz);
	}

	void BaseManager::injectMousePress(int _absx, int _absy, MyGUI::MouseButton _id)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMousePress(_absx, _absy, _id);
	}

	void BaseManager::injectMouseRelease(int _absx, int _absy, MyGUI::MouseButton _id)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectMouseRelease(_absx, _absy, _id);
	}

	void BaseManager::injectKeyPress(MyGUI::KeyCode _key, MyGUI::Char _text)
	{
		if (!mGUI)
			return;

		if (_key == MyGUI::KeyCode::Escape)
		{
			mExit = true;
			return;
		}

		MyGUI::InputManager::getInstance().injectKeyPress(_key, _text);
	}

	void BaseManager::injectKeyRelease(MyGUI::KeyCode _key)
	{
		if (!mGUI)
			return;

		MyGUI::InputManager::getInstance().injectKeyRelease(_key);
	}

	void BaseManager::quit()
	{
		mExit = true;
	}

	const std::string& BaseManager::getRootMedia()
	{
		static std::string result;
		return result;
	}

	void BaseManager::setResourceFilename(const std::string& _flename)
	{
	}

} // namespace base
