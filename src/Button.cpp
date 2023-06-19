#include "Button.h"

#include "Window.h"

Button::Button(const std::string& text, const Vector2F& position, const Vector2I& size, const ButtonStyle& style)
{
	_text = text;
	_position = position;
	_size = size;
	_style = style;
}

int Button::GetTextColor() const
{
	if (!_enabled) return _style.DisabledTextColor;

	if (_isPressed) return _style.PressedTextColor;

	if (_isHovered) return _style.HoverTextColor;

	return _style.TextColor;
}

int Button::GetBackgroundColor() const
{
	if (!_enabled) return _style.DisabledBackgroundColor;

	if (_isPressed) return _style.PressedBackgroundColor;

	if (_isHovered) return _style.HoverBackgroundColor;

	return _style.BackgroundColor;
}

int Button::GetBorderColor() const
{
	if (!_enabled) return _style.DisabledBorderColor;

	if (_isPressed) return _style.PressedBorderColor;

	if (_isHovered) return _style.HoverBorderColor;

	return _style.BorderColor;
}

void Button::Draw(Window& window)
{
	if (!_visible) return;

	auto textColorToUse = GetTextColor();
	auto backgroundColorToUse = GetBackgroundColor();
	auto borderColorToUse = GetBorderColor();

	auto position = _position;
	auto size = _size;
	auto pivot = _style.Pivot;

	if (pivot == Pivot::Center)
	{
		position.X -= size.X / 2;
		position.Y -= size.Y / 2;
	}
	else if (pivot == Pivot::TopRight)
	{
		position.X -= size.X;
	}

	window.DrawFullRectangle(position.X, position.Y, size.X, size.Y, backgroundColorToUse);
	window.DrawRectangle(position.X, position.Y, size.X, size.Y, borderColorToUse, _style.BorderWidth);

	auto textSize = size.Y * 0.5f;

	window.DrawText({ .Text = _text, .Size = textSize, .Position = { static_cast<int>(position.X + size.X / 2), static_cast<int>(position.Y + size.Y * 3/4) }, .Color = textColorToUse, .Pivot = Center });
}

bool Button::IsHovered(const Vector2I& mousePosition) const
{
	auto position = _position;
	auto size = _size;
	auto pivot = _style.Pivot;

	if (pivot == Pivot::Center)
	{
		position.X -= size.X / 2;
		position.Y -= size.Y / 2;
	}
	else if (pivot == Pivot::TopRight)
	{
		position.X -= size.X;
	}

	return mousePosition.X >= position.X && mousePosition.X <= position.X + size.X && mousePosition.Y >= position.Y && mousePosition.Y <= position.Y + size.Y;
}

void Button::SetText(const std::string& text)
{
	_text = text;
}

void Button::SetPosition(const Vector2F& position)
{
	_position = position;
}

void Button::SetSize(const Vector2I& size)
{
	_size = size;
}

void Button::SetStyle(const ButtonStyle& style)
{
	_style = style;
}

void Button::SetEnabled(bool enabled)
{
	_enabled = enabled;
}

void Button::SetVisible(bool visible)
{
	_visible = visible;
}

void Button::SetHovered(bool hovered)
{
	_isHovered = hovered;
}

void Button::SetPressed(bool pressed)
{
	_isPressed = pressed;
}

bool Button::IsEnabled() const
{
	return _enabled;
}

bool Button::IsVisible() const
{
	return _visible;
}

bool Button::IsHovered() const
{
	return _isHovered;
}

bool Button::IsPressed() const
{
	return _isPressed;
}

std::string Button::GetText() const
{
	return _text;
}

Vector2F Button::GetPosition() const
{
	return _position;
}

Vector2I Button::GetSize() const
{
	return _size;
}

ButtonStyle Button::GetStyle() const
{
	return _style;
}

