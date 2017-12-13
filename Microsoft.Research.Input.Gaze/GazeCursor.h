#pragma once

#include "pch.h"

using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Shapes;

BEGIN_NAMESPACE_GAZE_INPUT

const int DEFAULT_CURSOR_RADIUS = 5;
const bool DEFAULT_CURSOR_VISIBILITY = true;

ref class GazeCursor sealed
{
public:
    static property GazeCursor^ Instance
    {
        GazeCursor^ get()
        {
            static GazeCursor^ cursor = ref new GazeCursor();
            return cursor;
        }
    }

    property int CursorRadius
    {
        int get() { return _cursorRadius; }
        void set(int value);
    }

    property bool IsCursorVisible
    {
        bool get() { return _isCursorVisible; }
        void set(bool value);
    }

    property Point Position
    {
        Point get()
        {
            return _cursorPosition;
        }

        void set(Point value)
        {
            _cursorPosition = value;
            _gazeCursor->Margin = Thickness(value.X, value.Y, 0, 0);
        }
    }

    property Point PositionOriginal
    {
        Point get()
        {
            return _originalCursorPosition;
        }

        void set(Point value)
        {
            _originalCursorPosition = value;
            _origSignalCursor->Margin = Thickness(value.X, value.Y, 0, 0);
        }
    }

private:
    GazeCursor();

private:
    Popup^              _gazePopup;
    Canvas^             _gazeCanvas;
    Shapes::Ellipse^    _gazeCursor;
    Shapes::Ellipse^    _origSignalCursor;
    Shapes::Rectangle^  _gazeRect;
    Point               _cursorPosition = {};
    Point               _originalCursorPosition = {};
    int                 _cursorRadius = DEFAULT_CURSOR_RADIUS;
    bool                _isCursorVisible = DEFAULT_CURSOR_VISIBILITY;

};

END_NAMESPACE_GAZE_INPUT