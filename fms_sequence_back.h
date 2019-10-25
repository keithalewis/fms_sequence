// fms_sequence_back.h - Last item in a sequence.
#pragma once

namespace fms::sequence {

	template<class S>
	inline auto back(S s)
	{
		S s_(s);

		while (s) {
			s_ = s;
			++s;
		}

		return s_;
	}

}
