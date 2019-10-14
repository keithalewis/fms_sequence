// fms_sequence_take.h - Take items from a sequence.
#pragma once
#include "fms_sequence_base.h"

namespace fms::sequence {

    template<class S, class V = value_type<S>>
    class take : public base<S, V> {
    private:
        long n;
    public:
        take(long n, S s)
            : base<S, V>(s), n(n)
        {
            if (n < 0) {
                n = -n; // !!! take(-n, end(s) + n)
            }
        }
        const auto operator<=>(const take&) const = default;
        operator bool() const override
        {
            return n != 0;
        }
        take& operator++() override
        {
            base<S,V>::operator++();
            --n;

            return *this;
        }
    };

}
