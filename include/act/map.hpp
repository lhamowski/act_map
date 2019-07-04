#pragma once

#include <algorithm>
#include <array>
#include <utility>

namespace act::details
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

    template<typename... Args>
    constexpr map(Args&&... elements) :
      elements_{std::forward<Args>(elements)...}
    {
    }

    constexpr size_type size() const { return elements_.size(); }

private:
    container_type elements_;
};

template<typename... Args>
map(Args&&... elements)
  ->map<typename details::first_element<Args...>::type::first_type,
        typename details::first_element<Args...>::type::second_type,
        sizeof...(elements)>;

} // namespace act