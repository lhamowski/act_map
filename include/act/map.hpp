#pragma once

#include <algorithm>
#include <array>
#include <utility>
#include <optional>

namespace act::detail
{

template<typename FirstType, typename... Ignore>
struct first_element
{
    using type = FirstType;
};

} // namespace act::details

namespace act
{

template<typename Key, typename Mapped, std::size_t size>
class map
{
public:
    using key_type = Key;
    using mapped_type = Mapped;
    using value_type = std::pair<key_type, mapped_type>;
    using container_type = std::array<value_type, size>;
    using size_type = typename container_type::size_type;
    using iterator = typename container_type::iterator;
    using const_iterator = typename container_type::const_iterator;
    using reverse_iterator = typename container_type::reverse_iterator;
    using const_reverse_iterator =
      typename container_type::const_reverse_iterator;

    template<typename... Args>
    constexpr map(Args&&... elements) :
      elements_{std::forward<Args>(elements)...}
    {
    }

    constexpr std::optional<value_type> find(const key_type& key) const
    {
        auto actual = cbegin();
        auto last = cend();

        for (; actual != last; ++actual)
        {
            if (actual->first == key)
            {
                return *actual;
            }
        }
        
        return {};
    }

    constexpr auto contains(const key_type& key) const
    {
        return find(key) != std::nullopt;
    }

    constexpr std::optional<mapped_type> at(const key_type& key) const
    {
        auto result = find(key);

        if (result != std::nullopt)
            return result->second;

        return {};
    }

    constexpr auto operator[](const key_type& key) const
    {
        return at(key);
    }

    constexpr size_type count(const key_type& key) const
    {
        return find(key) != std::nullopt ? 1 : 0;
    }

    constexpr auto empty() const { return size() == 0; }

    constexpr size_type size() const { return elements_.size(); }

    constexpr auto begin()         { return elements_.begin();   }
    constexpr auto end()           { return elements_.end();     }
    constexpr auto rbegin()        { return elements_.rbegin();  }
    constexpr auto rend()          { return elements_.rend();    }
    constexpr auto cbegin()  const { return elements_.cbegin();  }
    constexpr auto cend()    const { return elements_.cend();    }
    constexpr auto crbegin() const { return elements_.crbegin(); }
    constexpr auto crend()   const { return elements_.crend();   }

private:
    container_type elements_;
};

template<typename... Args>
map(Args&&... elements)
  ->map<typename detail::first_element<Args...>::type::first_type,
        typename detail::first_element<Args...>::type::second_type,
        sizeof...(elements)>;

} // namespace act