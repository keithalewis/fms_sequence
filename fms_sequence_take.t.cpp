// fms_sequence_take.t.cpp - Test fms::sequence::take.
#include <cassert>
#include "fms_sequence_take.h"

using namespace fms::sequence;

template<class X>
int test_sequence_take()
{
    {
        X x[] = { 1, 2 };
        auto t = take<X*,X>(2, x);
        take t2(t);
        t = t2;

        assert(t == t2);
        assert(!(t != t2));

        assert(x[0] == *t);
        ++t;
        assert(x[1] == *t);
        ++t;
        assert(!t);
    }

    return 0;
}
int test_sequence_take_int = test_sequence_take<int>();