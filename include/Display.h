#pragma once

#include <cstdint>
#include <vector>
#include <functional>

#include "Button.h"

class Window;

class Display
{

public:
    Display() = default;

private:
	std::vector<Button> _buttons;
	std::vector<std::function<void(Window&)>> _buttonCallbacks;

protected:
	void AddButton(Button button, const std::function<void(Window&)>& callback);
	void ClearButtons();

	[[nodiscard]] Button& GetButton(int index);

public:
	void Init(Window& window);

    /**
     * @brief Initialize the display, called once
     * @param window
     */
    virtual void OnStart(Window& window) {}
	void UpdateButtons(Window& window);
    virtual void Update(Window& window) {}
    virtual void Draw(Window& window) {}
	void DrawButtons(Window& window);

    //TODO: Manage buttons and UI elements
};