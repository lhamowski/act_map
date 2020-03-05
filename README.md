# act::map

act::map is a simple C++17 header-only library that provides a compile-time associative array.
It is a key-value wrapper for std::array.


```cpp
#include "act/map.hpp"

enum class color { red, green, blue, black, white, yellow };

struct rgb
{
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;

    constexpr bool operator==(const rgb& rhs) const
    {
        return r == rhs.r && g == rhs.g && b == rhs.b;
    }
};

int main()
{
  constexpr act::map rgb_colors{std::pair{color::red,   rgb{255, 0,   0  }},
                                std::pair{color::green, rgb{0,   255, 0  }},
                                std::pair{color::blue,  rgb{0,   0,   255}},
                                std::pair{color::black, rgb{0,   0,   0  }},
                                std::pair{color::white, rgb{255, 255, 255}}};

  constexpr auto blue = rgb_colors[color::blue]; // blue is a std::optional
  constexpr auto yellow = rgb_colors[color::yellow]; // rgb_colors doesn't contain yellow
  static_assert(*blue == rgb{0, 0, 255});
  static_assert(yellow == std::nullopt);

  return 0;
}

```
