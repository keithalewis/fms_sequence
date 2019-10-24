// fms_sequence_uniq.h - Remove duplicates from a sequence.
#pragma once
#include "fms_sequence_traits.h"

namespace fms::sequence {

    template<class S>
    class unique {
        S s;
    public:
        unique(S s)
            : s(s)
        { }
        operator bool() const
        {
            return s;
        }
        auto operator*() const
        {
            return *s;
        }
        unique& operator++()
        {
            auto x = *s;
            while (++s and x == *s)
                ;

            return *this;
        }
    };

}
