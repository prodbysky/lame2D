#include <cstdint>

namespace lame2D {
    enum class EventType : uint8_t { Zero, No, MouseMove };

    struct NoEvent {
        EventType type;
    };

    struct MouseMoveEvent {
        EventType type;
        int32_t x;
        int32_t y;
    };

    union Event {
        EventType type;
        NoEvent no;
        MouseMoveEvent mouse_move;
    };

} // namespace lame2D
