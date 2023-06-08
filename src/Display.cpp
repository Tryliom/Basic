#include "Display.h"

#include "Window.h"

Display::Display(uint32_t width, uint32_t height)
{
    _width = width;
    _height = height;
}

void Display::Init(Window& window)
{
    if (_width == 0 || _height == 0)
    {
        _width = window.Width;
        _height = window.Height;
    }
    else
    {
        window.Resize(_width, _height);
    }

    OnStart(window);
}

void Display::OnStart(Window& window)
{

}

void Display::Update(Window& window)
{

}

void Display::Draw(Window& window)
{

}
