// fms_sequence_end.h - The end of a sequence, if is exists.
#pragma once

namespace fms::sequence {

	template<class S>
	inline S end(S s)
	{
		while (s) {
			++s;
		}

		return s;
	}

}
