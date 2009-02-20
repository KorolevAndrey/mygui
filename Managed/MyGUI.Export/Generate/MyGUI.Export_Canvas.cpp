﻿/*!
	@file
	@author		Generate utility by Albert Semenov
	@date		01/2009
	@module
*/

#include "../ExportDefine.h"
#include "../ExportMarshaling.h"
#include <MyGUI.h>

namespace Export
{

	//InsertPoint





   	namespace ScopeCanvasProperty_TextureManaged
	{
		MYGUIEXPORT Convert<bool>::Type MYGUICALL ExportCanvas_IsTextureManaged( MyGUI::Widget* _native )
		{
			return Convert<bool>::To( static_cast< MyGUI::Canvas * >(_native)->isTextureManaged( ) );
		}
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetTextureManaged( MyGUI::Widget* _native , Convert<bool>::Type _value )
		{
			static_cast< MyGUI::Canvas * >(_native)->setTextureManaged( Convert<bool>::From( _value ) );
		}
	}
	


   	namespace ScopeCanvasMethod_IsTextureCreated
	{
		MYGUIEXPORT Convert<bool>::Type MYGUICALL ExportCanvas_IsTextureCreated( MyGUI::Widget* _native )
		{
			return Convert<bool>::To( static_cast< MyGUI::Canvas * >(_native)->isTextureCreated( ) );
		}
	}



   	namespace ScopeCanvasMethod_IsTextureSrcSize
	{
		MYGUIEXPORT Convert<bool>::Type MYGUICALL ExportCanvas_IsTextureSrcSize( MyGUI::Widget* _native )
		{
			return Convert<bool>::To( static_cast< MyGUI::Canvas * >(_native)->isTextureSrcSize( ) );
		}
	}





   	namespace ScopeCanvasMethod_SetCoord
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetCoord_left_top_width_height( MyGUI::Widget* _native ,
			Convert<int>::Type _left ,
			Convert<int>::Type _top ,
			Convert<int>::Type _width ,
			Convert<int>::Type _height )
		{
			static_cast< MyGUI::Canvas * >(_native)->setCoord(
				Convert<int>::From(_left) ,
				Convert<int>::From(_top) ,
				Convert<int>::From(_width) ,
				Convert<int>::From(_height) );
		}
	}



   	namespace ScopeCanvasMethod_SetSize
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetSize_width_height( MyGUI::Widget* _native ,
			Convert<int>::Type _width ,
			Convert<int>::Type _height )
		{
			static_cast< MyGUI::Canvas * >(_native)->setSize(
				Convert<int>::From(_width) ,
				Convert<int>::From(_height) );
		}
	}



   	namespace ScopeCanvasMethod_SetCoord
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetCoord_coord( MyGUI::Widget* _native ,
			Convert<const MyGUI::types::TCoord< int > &>::Type _coord )
		{
			static_cast< MyGUI::Canvas * >(_native)->setCoord(
				Convert<const MyGUI::types::TCoord< int > &>::From(_coord) );
		}
	}



   	namespace ScopeCanvasMethod_SetSize
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetSize_size( MyGUI::Widget* _native ,
			Convert<const MyGUI::types::TSize< int > &>::Type _size )
		{
			static_cast< MyGUI::Canvas * >(_native)->setSize(
				Convert<const MyGUI::types::TSize< int > &>::From(_size) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureGroup
	{
		MYGUIEXPORT Convert<const std::string &>::Type MYGUICALL ExportCanvas_GetTextureGroup( MyGUI::Widget* _native )
		{
			return Convert<const std::string &>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureGroup( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureName
	{
		MYGUIEXPORT Convert<const std::string &>::Type MYGUICALL ExportCanvas_GetTextureName( MyGUI::Widget* _native )
		{
			return Convert<const std::string &>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureName( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureFormat
	{
		MYGUIEXPORT Convert<Ogre::PixelFormat>::Type MYGUICALL ExportCanvas_GetTextureFormat( MyGUI::Widget* _native )
		{
			return Convert<Ogre::PixelFormat>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureFormat( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureSrcSize
	{
		MYGUIEXPORT Convert< MyGUI::types::TSize< int > >::Type MYGUICALL ExportCanvas_GetTextureSrcSize( MyGUI::Widget* _native )
		{
			return Convert< MyGUI::types::TSize< int > >::To( static_cast< MyGUI::Canvas * >(_native)->getTextureSrcSize( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureSrcHeight
	{
		MYGUIEXPORT Convert<int>::Type MYGUICALL ExportCanvas_GetTextureSrcHeight( MyGUI::Widget* _native )
		{
			return Convert<int>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureSrcHeight( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureSrcWidth
	{
		MYGUIEXPORT Convert<int>::Type MYGUICALL ExportCanvas_GetTextureSrcWidth( MyGUI::Widget* _native )
		{
			return Convert<int>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureSrcWidth( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureRealSize
	{
		MYGUIEXPORT Convert< MyGUI::types::TSize< int > >::Type MYGUICALL ExportCanvas_GetTextureRealSize( MyGUI::Widget* _native )
		{
			return Convert< MyGUI::types::TSize< int > >::To( static_cast< MyGUI::Canvas * >(_native)->getTextureRealSize( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureRealHeight
	{
		MYGUIEXPORT Convert<int>::Type MYGUICALL ExportCanvas_GetTextureRealHeight( MyGUI::Widget* _native )
		{
			return Convert<int>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureRealHeight( ) );
		}
	}



   	namespace ScopeCanvasMethod_GetTextureRealWidth
	{
		MYGUIEXPORT Convert<int>::Type MYGUICALL ExportCanvas_GetTextureRealWidth( MyGUI::Widget* _native )
		{
			return Convert<int>::To( static_cast< MyGUI::Canvas * >(_native)->getTextureRealWidth( ) );
		}
	}



   	namespace ScopeCanvasMethod_SetPixel
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetPixel_pixelvalue( MyGUI::Widget* _native ,
			Convert<const MyGUI::types::TPoint< int > &>::Type _pixel ,
			Convert<const Ogre::ColourValue &>::Type value )
		{
			static_cast< MyGUI::Canvas * >(_native)->setPixel(
				Convert<const MyGUI::types::TPoint< int > &>::From(_pixel) ,
				Convert<const Ogre::ColourValue &>::From(value) );
		}
	}



   	namespace ScopeCanvasMethod_SetPixel
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_SetPixel_x_yvalue( MyGUI::Widget* _native ,
			Convert<int>::Type _x ,
			Convert<int>::Type _y ,
			Convert<const Ogre::ColourValue &>::Type value )
		{
			static_cast< MyGUI::Canvas * >(_native)->setPixel(
				Convert<int>::From(_x) ,
				Convert<int>::From(_y) ,
				Convert<const Ogre::ColourValue &>::From(value) );
		}
	}



   	namespace ScopeCanvasMethod_IsLocked
	{
		MYGUIEXPORT Convert<bool>::Type MYGUICALL ExportCanvas_IsLocked( MyGUI::Widget* _native )
		{
			return Convert<bool>::To( static_cast< MyGUI::Canvas * >(_native)->isLocked( ) );
		}
	}



   	namespace ScopeCanvasMethod_Unlock
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_Unlock( MyGUI::Widget* _native )
		{
			static_cast< MyGUI::Canvas * >(_native)->unlock( );
		}
	}



   	namespace ScopeCanvasMethod_Lock
	{
		MYGUIEXPORT Convert<void *>::Type MYGUICALL ExportCanvas_Lock( MyGUI::Widget* _native )
		{
			return Convert<void *>::To( static_cast< MyGUI::Canvas * >(_native)->lock( ) );
		}
	}



   	namespace ScopeCanvasMethod_UpdateTexture
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_UpdateTexture( MyGUI::Widget* _native )
		{
			static_cast< MyGUI::Canvas * >(_native)->updateTexture( );
		}
	}



   	namespace ScopeCanvasMethod_LoadTexture
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_LoadTexturetexturemanageMode( MyGUI::Widget* _native ,
			Convert<Ogre::TexturePtr>::Type texture ,
			Convert<bool>::Type manageMode )
		{
			static_cast< MyGUI::Canvas * >(_native)->loadTexture(
				Convert<Ogre::TexturePtr>::From(texture) ,
				Convert<bool>::From(manageMode) );
		}
	}


   	namespace ScopeCanvasMethod_LoadTexture
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_LoadTexturetexture( MyGUI::Widget* _native ,
			Convert<Ogre::TexturePtr>::Type texture )
		{
			static_cast< MyGUI::Canvas * >(_native)->loadTexture(
				Convert<Ogre::TexturePtr>::From(texture) );
		}
	}



   	namespace ScopeCanvasMethod_DestroyTexture
	{
		MYGUIEXPORT void MYGUICALL ExportCanvas_DestroyTexture( MyGUI::Widget* _native )
		{
			static_cast< MyGUI::Canvas * >(_native)->destroyTexture( );
		}
	}















}
