// fms_sequence_filter.h - Filter based on a predicate
#pragma once

namespace fms::sequence {

	template<class P,class S>
	class filter {
		P p;
		S s;
	public:
		filter(const P& p, const S& _s)
			: p(p), s(_s)
		{
			while (s and p(*s) == false) {
				++s;
			}
		}
		operator bool() const
		{
			return s;
		}
		auto operator*() const
		{
			return *s;
		}
		filter& operator++()
		{
			while (++s and p(*s) == false) {
				++s;
			}

			return *this;
		}
	};

}