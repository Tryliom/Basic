#include "Display.h"

#include "Window.h"
#include "Input.h"

void Display::AddButton(Button button, const std::function<void(Window&)>& callback)
{
	_buttons.push_back(button);
	_buttonCallbacks.push_back(callback);
}

Button& Display::GetButton(int index)
{
	return _buttons[index];
}

void Display::Init(Window& window)
{
    OnStart(window);
}

void Display::UpdateButtons(Window& window)
{
	auto mousePosition = window.GetMousePosition();
	auto isLeftMouseButtonPressed = Input::IsMouseButtonPressed(MOUSE_LEFT);
	auto isLeftMouseButtonReleased = Input::IsMouseButtonReleased(MOUSE_LEFT);

	for (auto i = 0; i < _buttons.size(); i++)
	{
		auto& button = _buttons[i];

		if (!button.IsEnabled() || !button.IsVisible()) continue;

		auto callback = _buttonCallbacks[i];
		bool hovered = button.IsHovered(mousePosition);

		button.SetHovered(hovered);
		button.SetPressed(hovered && isLeftMouseButtonPressed);

		// Check if the mouse is over the button and if the left mouse button is released
		if (hovered && isLeftMouseButtonReleased)
		{
			callback(window);
		}
	}
}

void Display::DrawButtons(Window& window)
{
	for (auto& button : _buttons)
	{
		button.Draw(window);
	}
}

void Display::ClearButtons()
{
	_buttons.clear();
	_buttonCallbacks.clear();
}
