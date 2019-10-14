// fms_sequence_base.t.cpp - Test fms::sequence::base.
#include <cassert>
#include <vector>
#include "fms_sequence_base.h"

using namespace fms::sequence;

template<class X>
int test_sequence_base()
{
    {
        X x[] = { 1, 2 };
        base<X*,X> b(x);
        base b2(b);
        assert(b == b2);

        b = b2;

        assert(b == b2);
        assert(!(b != b2));
        assert(b <= b2);
        assert(!(b < b2));
        assert(b >= b2);
        assert(!(b > b2));

        assert(x[0] == *b);
        ++b;
        assert(x[1] == *b);
        assert(++b); // out of range
    }
    {
        std::vector<X> x({ 1, 2 });
        X* px = &x[0];
        base<X*,X> b(px);
        base b2(b);
        b = b2;

        assert(b == b2);
        assert(!(b != b2));
        assert(b <= b2);
        assert(!(b < b2));
        assert(b >= b2);
        assert(!(b > b2));

        assert(x[0] == *b);
        ++b;
        assert(x[1] == *b);
        assert(++b); // out of range
    }

    return 0;
}
int test_sequence_base_int = test_sequence_base<int>();
