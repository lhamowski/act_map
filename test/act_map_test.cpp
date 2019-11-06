#include "act/map.hpp"

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <cstdint>
#include <utility>

enum color { red, green, blue, black, white, yellow };

TEST_CASE("Creat simple RGB colors map", "[map]")
{
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

    constexpr act::map rgb_colors{std::pair{color::red,   rgb{255, 0,   0  }},
                                  std::pair{color::green, rgb{0,   255, 0  }},
                                  std::pair{color::blue,  rgb{0,   0,   255}},
                                  std::pair{color::black, rgb{0,   0,   0  }},
                                  std::pair{color::white, rgb{255, 255, 255}}};
    REQUIRE(rgb_colors.size() == 5);

    constexpr auto red_color_pair = rgb_colors.find(color::red);
    constexpr auto yellow_color_pair = rgb_colors.find(color::yellow);
    REQUIRE(*red_color_pair == std::pair{color::red, rgb{255, 0, 0}});
    REQUIRE(yellow_color_pair == std::nullopt);

    constexpr auto green_color_rgb = rgb_colors.at(color::green);
    REQUIRE(*green_color_rgb == rgb{0, 255, 0});

    // operator[] is equivalent to at(const Key& key)
    constexpr auto blue_color_rgb = rgb_colors[color::blue];
    REQUIRE(*blue_color_rgb == rgb{0, 0, 255});

    constexpr auto yellow_color_count = rgb_colors.count(color::yellow);
    constexpr auto black_color_count = rgb_colors.count(color::black);
    REQUIRE(yellow_color_count == 0);
    REQUIRE(black_color_count == 1);
}