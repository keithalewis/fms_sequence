// fms_sequence_equal.h - Check if two sequences have the same values
#pragma once

namespace fms::sequence {

    template<class S, class T>
    inline bool equal(S s, T t)
    {
        while (s and t) {
            if (*s != *t) {
                return false;
            }
            ++s;
            ++t;
        }

        return !s and !t;
    }

}
