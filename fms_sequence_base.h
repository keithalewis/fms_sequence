// fms_sequence_base.h - Base sequence
#pragma once
#include <compare>
#include <iterator>
#include <concepts>

namespace fms::sequence {

    // Hide member functions in derived classes to specialize.
    template<class /* std::input_iterator */ S>
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
            return true;
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