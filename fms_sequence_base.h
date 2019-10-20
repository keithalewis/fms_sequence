// fms_sequence_base.h - Base sequence
#pragma once
#include <compare>
#include <concepts>
#include <iterator>
#include <type_traits>

namespace fms::sequence {

	template<class S>
	using value_type = std::invoke_result_t<decltype(&S::operator*), S>;

}

template <class T, class U>
concept derived = std::is_base_of<U, T>::value;

template<typename S>
concept sequence_base = requires(S s) {
	{s} -> bool;
	{*s} -> decltype(*s);
	{++s}->S&;
};

namespace fms::sequence {

    // Hide member functions in derived classes to specialize.
    template<sequence_base S>
    class base {
    private:
        S s;
    public:
        base(S s)
            : s(s)
        { }
        virtual ~base()
        { }
        const auto operator<=>(const base&) const = default;
        operator bool() const
        {
            return s;
        }
        const auto& operator*() const
        {
            return *s;
        }
        auto& operator*()
        {
            return *s;
        }
        base& operator++()
        {
            ++s;

            return *this;
        }
    };

}