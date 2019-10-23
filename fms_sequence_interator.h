// fms_sequence_iterator.h - Iterator concepts
//!!! Replace with std header .
#pragma once
#include <concepts>
#include <iterator>

template<typename T>
concept has_type_member = requires { typename T::type; };

/*
template<typename S>
concept Sequence = requires { 
	S::operator bool();
	//S::operator*();
	//S& S::operator++();
};
template<typename I>
concept InputSequence = requires(I i) {
	I::operator*() const -> auto&&;
};
*/
namespace fms::sequence {
	/*
	*/
}
