#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

namespace ft {

	template<class Inputiterator1, class Inputiterator2>
	bool eqall(Inputiterator1 first, Inputiterator1 last, Inputiterator2 inputiterator2) {
		for (; first != last; ++first) {
			if (*first != *inputiterator2)
				return false;

		}
		return true;
	}

	template<class Inputiterator1, class Inputiterator2, class BinaryPredicate>
	bool eqall(Inputiterator1 first, Inputiterator1 last, Inputiterator2 inputiterator2, BinaryPredicate predicate) {
		for (; first != last; ++first) {
			if (*first != *inputiterator2)
				return false;
		}
		return true;
	}
};
#endif