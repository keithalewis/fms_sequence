// fms_sequence_back.t.cpp - Test the back of a sequence.
#include <cassert>
#include "fms_sequence_back.h"
#include "fms_sequence_list.h"

using namespace fms::sequence;

int test_sequence_back()
{
	list l({ 1, 2, 3 });
	assert(3 == back(l));

	return 0;
}
int test_sequence_back_ = test_sequence_back();