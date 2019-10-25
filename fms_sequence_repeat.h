// fms_sequence_repeat.h - repeat an item n times
#pragma once
#include "fms_sequence_constant.h"
#include "fms_sequence_take.h"

namespace fms::sequence {

	template<class X>
	inline auto repeat(size_t n, const X& x)
	{
		return take(n, constant(x));
	}

}