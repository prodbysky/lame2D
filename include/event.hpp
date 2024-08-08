#include <cstdint>
#include <type_traits>

namespace lame2D {
    enum class EventType : uint8_t {
        Zero,
        No,
        MouseMove,
        KeyboardAction,
    };

    enum class Key : char {
        W            = 'w',
        A            = 'a',
        S            = 's',
        D            = 'd',
        Q            = 'q',
        E            = 'e',
        R            = 'r',
        F            = 'f',
        T            = 't',
        G            = 'g',
        Y            = 'y',
        H            = 'h',
        U            = 'u',
        J            = 'j',
        I            = 'i',
        K            = 'k',
        O            = 'o',
        L            = 'l',
        P            = 'p',
        SemiColon    = ';',
        LeftBracket  = '[',
        Quote        = '\'',
        RightBracket = ']',
        BackSlash    = '\\',
        Z            = 'z',
        X            = 'x',
        C            = 'c',
        V            = 'v',
        B            = 'b',
        N            = 'n',
        M            = 'm',
        Comma        = ',',
        Period       = '.',
        Slash        = '/',
    };

    template <typename E>
    constexpr auto to_underlying(E e) ->
        typename std::underlying_type<E>::type {
        return static_cast<typename std::underlying_type<E>::type>(e);
    }

    struct NoEvent {
        EventType type;
    };

    struct MouseMoveEvent {
        EventType type;
        int32_t x;
        int32_t y;
    };

    struct KeyboardActionEvent {
        EventType type;
        Key k;
        bool down;
    };

    union Event {
        EventType type;
        NoEvent no;
        MouseMoveEvent mouse_move;
        KeyboardActionEvent keyboard;
    };

} // namespace lame2D
