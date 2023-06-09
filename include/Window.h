#pragma once

#include <cstdint>
#include <map>
#include <utility>

#include "Image.h"
#include "Utility.h"
#include "Font.h"
#include "Display.h"

class Window
{
public:
    Window(uint32_t width, uint32_t height);

private:
    uint32_t _width;
    uint32_t _height;
    int _background;

    struct mfb_window* _window;
    int* _buffer;

	uint32_t _frame { 0 };

    // Font
    std::map<int, rtpAtlasSprite> _chars;
    std::map<int, Image> _charsImage;

    Display* _display { nullptr };

    void DrawPixel(uint32_t index, int color);

    static Vector2I GetStartPosition(uint32_t width, uint32_t height, int x, int y, Pivot pivot);
    static Vector2I GetRotatedPosition(int x, int y, Image image, Pivot pivot);

public:
    int Width;
    int Height;
    int Frame;

    [[nodiscard]] uint32_t GetBackgroundColor() const { return _background; }
    void SetBackgroundColor(int color) { _background = color; }

    void Update();
    bool IsOpen();
    void SetDisplay(Display* display);
    void Resize(uint32_t width, uint32_t height);

    void DrawPixel(uint32_t x, uint32_t y, int color);

    void DrawHorizontalLine(uint32_t x, uint32_t y, uint32_t length, int color);
    void DrawVerticalLine(uint32_t x, uint32_t y, uint32_t length, int color);

    // Use top left pivot
    void DrawRectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height, int color, int lineWidth = 1);
    void DrawFullRectangle(uint32_t x, uint32_t y, uint32_t width, uint32_t height, int color);

    void DrawLine(Vector2I start, Vector2I end, int color);
	void DrawImage(Image image, int x, int y, Pivot pivot = Pivot::Center);
    void DrawText(Text text);

    Vector2I GetMousePosition();
};
