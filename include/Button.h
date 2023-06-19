#pragma once

#include "Utility.h"

class Window;

struct ButtonStyle
{
	int TextColor { Utility::ToColor(200, 200, 200) };
	int BackgroundColor { Utility::ToColor(50, 50, 50) };
	int BorderColor { Utility::ToColor(200, 200, 200) };

	int HoverTextColor { Utility::ToColor(225, 225, 225) };
	int HoverBackgroundColor { Utility::ToColor(25, 25, 25) };
	int HoverBorderColor { Utility::ToColor(225, 225, 225) };

	int PressedTextColor { Utility::ToColor(255, 255, 255) };
	int PressedBackgroundColor { Utility::ToColor(0, 0, 0) };
	int PressedBorderColor { Utility::ToColor(255, 255, 255) };

	int DisabledTextColor { Utility::ToColor(100, 100, 100) };
	int DisabledBackgroundColor { Utility::ToColor(30, 30, 30) };
	int DisabledBorderColor { Utility::ToColor(100, 100, 100) };

	float BorderWidth { 2.f };

	Pivot Pivot { Pivot::Center };
};

class Button
{
public:
	Button(const std::string& text, const Vector2F& position, const Vector2I& size, const ButtonStyle& style = ButtonStyle());

private:
	std::string _text;
	Vector2F _position {};
	Vector2I _size {};
	ButtonStyle _style;

	bool _enabled { true };
	bool _visible { true };

	bool _isHovered { false };
	bool _isPressed { false };

	[[nodiscard]] int GetTextColor() const;
	[[nodiscard]] int GetBackgroundColor() const;
	[[nodiscard]] int GetBorderColor() const;

public:
	void Draw(Window& window);

	bool IsHovered(const Vector2I& mousePosition) const;

	void SetText(const std::string& text);
	void SetPosition(const Vector2F& position);
	void SetSize(const Vector2I& size);
	void SetStyle(const ButtonStyle& style);

	void SetEnabled(bool enabled);
	void SetVisible(bool visible);
	void SetHovered(bool hovered);
	void SetPressed(bool pressed);

	[[nodiscard]] bool IsEnabled() const;
	[[nodiscard]] bool IsVisible() const;
	[[nodiscard]] bool IsHovered() const;
	[[nodiscard]] bool IsPressed() const;

	[[nodiscard]] std::string GetText() const;
	[[nodiscard]] Vector2F GetPosition() const;
	[[nodiscard]] Vector2I GetSize() const;
	[[nodiscard]] ButtonStyle GetStyle() const;
};