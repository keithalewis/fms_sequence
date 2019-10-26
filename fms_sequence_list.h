// fms_sequence_list.h - sequence from initializer list
#pragma once
#include <initializer_list>
#include <vector>
#include "fms_sequence_interface.h"

namespace fms::sequence {

    template<class X>
    class list : public interface<std::vector<X>, X> {
		typedef interface<std::vector<X>, X> I;
        size_t n;
    public:
        list(const std::initializer_list<X>& s)
            : I(std::vector<X>(s.begin(), s.end())), n(0)
        { }
        list(const std::vector<X>& s)
            : I(s), n(0)
        { }
        list(size_t n, const X* s)
            : I(std::vector(s, s + n)), n(0)
        { }
		
        size_t size() const
        {
            return I::s.size();
        }
		void push_back(const X& x)
		{
			I::s.push_back(x);
		}
        auto begin()
        {
            return I::s.begin();
        }
        auto end()
        {
            return I::s.end();
        }
        void reset()
        {
            n = 0;
        }
		
        bool op_bool() const override
        {
            return n < I::s.size();
        }
        X op_star() const override
        {
            return I::s[n];
        }
		/*
        X& operator*()
        {
            return I::s[n];
        }
		*/
        list& op_incr() override
        {
            if (op_bool()) {
                ++n;
            }

            return *this;
        }
        list& operator--()
        {
            if (n > 0) {
                --n;
            }

            return *this;
        }
    };

	// aliases
	template<class X> 
	using vector = list<X>;
	template<class X> 
	using array = list<X>;

}