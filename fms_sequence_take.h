// fms_sequence_take.h - Take items from a sequence.
#pragma once
#include "fms_sequence_base.h"

namespace fms::sequence {

    template<class S>
    class take : public base<S> {
    private:
        long n;
    public:
        take(long n, S s)
            : base<S>(s), n(n)
        {
            if (n < 0) {
                n = -n; // !!! take(-n, end(s) + n)
            }
        }
        const auto operator<=>(const take&) const = default;
        operator bool() const // hide
        {
            return n != 0;
        }
        take& operator++() // hide
        {
            base<S>::operator++();
            --n;

            return *this;
        }
    };

}
