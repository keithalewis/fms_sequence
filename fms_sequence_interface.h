// fms_sequence_interface.h - virtual base class
#pragma once
#include "fms_sequence_traits.h"

namespace fms::sequence {

	// Interface to sequence of X's
	template<class S, class X>
	class interface {
	protected:
		S s;
	public:
		interface(const S& s)
			: s(s)
		{ }
		virtual ~interface()
		{ }
		operator bool() const
		{
			return op_bool();
		}
		X operator*() const
		{
			return op_star();
		}
		interface& operator++()
		{
			return op_incr();
		}
	private:
		virtual bool op_bool() const = 0;
		virtual X op_star() const = 0;
		virtual interface& op_incr() = 0;
	};

}
