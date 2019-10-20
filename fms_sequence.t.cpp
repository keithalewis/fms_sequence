// fms_sequence.t.cpp - Test fms sequence.
#include <cassert>
#include <string>
#include "fms_sequence_base.h"

template<sequence_base S>
struct s {
	S i;
	s()
	{ }
	s(const S& i)
		: i(i)
	{ }
	operator bool() const
	{
		return true;
	}
	decltype(*i) operator*() const
	{
		return 0;
	}
	s& operator++()
	{
		return *this;
	}
};

int main()
{
	{
		//int i[] = { 1, 2, 3 };
		s<int*> si;
		assert(si);
	}

    return 0;
}