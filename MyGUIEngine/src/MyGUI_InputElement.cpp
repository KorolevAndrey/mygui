/*!
	@file
	@author		Albert Semenov
	@date		03/2010
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "MyGUI_Precompiled.h"
#include "MyGUI_InputElement.h"

namespace MyGUI
{

	InputElement::InputElement()
	{
	}

	InputElement::~InputElement()
	{
	}

	void InputElement::registerInputElement()
	{
		registerEvent("Direct", false, false);
		registerEvent("Tunnel", true, false);
		registerEvent("Bubble", false, true);
	}

	void InputElement::unregisterInputElement()
	{
	}

} // namespace MyGUI