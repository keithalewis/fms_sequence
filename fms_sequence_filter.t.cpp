// fms_sequence_filter.t.cpp - Test sequence filter.
#include <cassert>
#include "fms_sequence_filter.h"
#include "fms_sequence_length.h"
#include "fms_sequence_take.h"
#include "fms_sequence_equal.h"

using namespace fms::sequence;

int test_sequence_filter()
{
	int i[] = { 1, 2, 3 };
	auto ti = take(3, i);
	
	{
		auto t2 = filter([](int i) { return i == 2; }, ti);
		assert(t2);
		assert(2 == *t2);
		++t2;
		assert(!t2);
	}
	{
		auto t0 = filter([](int i) { return false; }, ti);
		assert(!t0);
	}
	{
		auto t = filter([](int i) { return true; }, ti);
		assert(equal(t, ti));
	}
	{
		auto t = filter([](int i) { return false; }, ti);
		assert(!t);
		assert(0 == length(t));
	}

	return 0;
}
int test_sequence_filter_ = test_sequence_filter();