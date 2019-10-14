// fms_sequence_base.h - Base sequence
#pragma once
#include <compare>
#include <type_traits>>

namespace fms::sequence {

    template<class S>
    using value_type = std::invoke_result_t<decltype(&S::operator*), S>;
    // !!!Or S* if no S::operator*

    // Override in base classes to specialize.
    template<class S, class V = value_type<S>>
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
        virtual operator bool() const
        {
            return true;
        }
        virtual V operator*() const
        {
            return *s;
        }
        virtual base& operator++()
        {
            ++s;

            return *this;
        }
    };

}