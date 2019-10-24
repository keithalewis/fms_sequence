// fms_sequence_end.t.cpp - Test finding the end of a sequence.
#include <cassert>
#include "fms_sequence_end.h"
#include "fms_sequence_list.h"
#include "fms_sequence_take.h"

using namespace fms::sequence;

int test_sequence_end()
{
	{
		int i[] = { 1, 2, 3 };
		auto ti = take(3, i);
		auto te = end(ti);
		assert(!te);
	}

	return 0;
}
int test_sequence_end_ = test_sequence_end();
