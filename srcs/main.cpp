
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"
#include <stdlib.h>
#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

template<class T>
void judge(T test_num) {
	std::cout << std::endl;
	std::cout << "=======================================" << std::endl;
	std::cout << "[TEST"<<test_num << "]"<< std::endl;
	if (system("diff 1 2") == 0)
		std::cout << "\033[32m[OK] \033[m";
	else
		std::cout << "\033[31m[KO] \033[m";
	std::cout << std::flush;
}


void vector(std::ofstream &fs1, std::ofstream &fs2);
void vector_test(std::ofstream &fs1, std::ofstream &fs2);
void map(std::ofstream &fs1, std::ofstream &fs2);
int	main()
{
	std::ofstream vec_1;
	std::ofstream vec_2;

	vec_1.open("vec_1");
	vec_2.open("vec_2");
	{
		std::cout << "\n=== VECTOR ===" << std::endl;
		vector(vec_1, vec_2);
//		vector_test(fs1, fs2);
	}

	std::ofstream map_1;
	std::ofstream map_2;
	map_1.open("map_1");
	map_2.open("map_2");
	{
		std::cout << "\n=== MAP ===" << std::endl;
		map(map_1, map_2);

	}



}

void map(std::ofstream &fs1, std::ofstream &fs2) {

	ft::map<int, int> map1;
	for(int i = 0; i < 100; i++) {
		map1[i] = i;
	}
	ft::map<int, int> map_2(map1.begin(), map1.end());
	for(ft::map<int , int >::iterator it = map_2.begin(); it != map_2.end(); it++) {
		std::cout << it->second << std::endl;
		std::cout << "piyo" << std::endl;
	}


}
void vector(std::ofstream &fs1, std::ofstream &fs2) {

	ft::vector<int> a;
	ft::vector<int> b(3, 100);//3 elements with 100
	ft::vector<int> c(b.begin(), b.end());
	ft::vector<int> d(c);
	int ints[] = {10, 1, 9, 2};
	ft::vector<int> ve_ints(ints, ints + sizeof(ints) / sizeof (int));

	for (ft::vector<int>::iterator it = d.begin(); it != d.end(); it++) {
		fs1 << *it << ' ';
	}

}


void vector_test(std::ofstream &fs1, std::ofstream &fs2) {
	judge(1);
	/* vector start */

	fs1 << "\n=== VECTOR ===" << std::endl;
	fs2 << "\n=== VECTOR ===" << std::endl;
	{
		// constructors used in the same order as described above:
		std::vector<int> first;           // empty vector of ints
		std::vector<int> second(4, 100);  // four ints with value 100
		std::vector<int> third(second.begin(),
							   second.end());  // iterating through second
		std::vector<int> fourth(third);        // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints[] = {16, 2, 77, 29};
		std::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

		fs1 << "The contents of fifth are:";
		for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			fs1 << ' ' << *it;
		fs1 << std::endl;

		// constructors used in the same order as described above:
		ft::vector<int> first_;           // empty vector of ints
		ft::vector<int> second_(4, 100);  // four ints with value 100
		ft::vector<int> third_(second_.begin(),
							   second_.end());  // iterating through second
		ft::vector<int> fourth_(third_);        // a copy of third

		// the iterator constructor can also be used to construct from arrays:
		int myints_[] = {16, 2, 77, 29};
		ft::vector<int> fifth_(myints_, myints_ + sizeof(myints_) / sizeof(int));
		fs2 << "The contents of fifth are:";
		for (ft::vector<int>::iterator it = fifth_.begin(); it != fifth_.end();
			 ++it)
			fs2 << ' ' << *it;
		fs2 << std::endl;
	}

	judge(2);

	{
		std::vector<int> myvector;
		for (int i = 1; i <= 5; i++) myvector.push_back(i);

		fs1 << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			fs1 << ' ' << *it;
		fs1 << std::endl;

		ft::vector<int> myvector_;
		for (int i = 1; i <= 5; i++) myvector_.push_back(i);
		fs2 << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector_.begin();
			 it != myvector_.end(); ++it)
			fs2 << ' ' << *it;
		fs2 << std::endl;
	}

	judge(3);

	{
		std::vector<int> foo(3, 0);
		std::vector<int> bar(5, 0);

		bar = foo;
		foo = std::vector<int>();
		fs1 << "Size of foo: " << int(foo.size()) << '\n';
		fs1 << "Size of bar: " << int(bar.size()) << std::endl;

		ft::vector<int> foo_(3, 0);
		ft::vector<int> bar_(5, 0);

		bar_ = foo_;
		foo_ = ft::vector<int>();
		fs2 << "Size of foo: " << int(foo_.size()) << '\n';
		fs2 << "Size of bar: " << int(bar_.size()) << std::endl;
	}

	judge(4);

	{
		std::vector<int> myvector;
		for (int i = 1; i <= 5; i++) myvector.push_back(i);

		fs1 << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			fs1 << ' ' << *it;
		fs1 << std::endl;

		ft::vector<int> myvector_;
		for (int i = 1; i <= 5; i++) myvector_.push_back(i);
		fs2 << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector_.begin();
			 it != myvector_.end(); ++it)
			fs2 << ' ' << *it;
		fs2 << std::endl;
	}

	judge(5);

	{
		std::vector<int> myvector(5);  // 5 default-constructed ints

		int i = 0;

		std::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit) *rit = ++i;
		fs1 << "myvector contains:";
		for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end();
			 ++it)
			fs1 << ' ' << *it;
		fs1 << std::endl;

		ft::vector<int> myvector_(5);  // 5 default-constructed ints

		int i_ = 0;

		ft::vector<int>::reverse_iterator rit_ = myvector_.rbegin();
		for (; rit_ != myvector_.rend(); ++rit_) {
			*rit_ = ++i_;
		}
			

		fs2 << "myvector contains:";
		for (ft::vector<int>::iterator it = myvector_.begin();
			 it != myvector_.end(); ++it)
			fs2 << ' ' << *it;
	}

	judge(6);

/*	{
		std::vector<int> myints;
		fs1 << "0. size: " << myints.size() << '\n';

		for (int i = 0; i < 10; i++) myints.push_back(i);
		fs1 << "1. size: " << myints.size() << '\n';

		myints.insert(myints.end(), 10, 100);
		fs1 << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		fs1 << "3. size: " << myints.size() << std::endl;

		ft::vector<int> myints_;
		fs2 << "0. size: " << myints_.size() << '\n';

		for (int i = 0; i < 10; i++) myints_.push_back(i);
		fs2 << "1. size: " << myints_.size() << '\n';

		myints_.insert(myints_.end(), 10, 100);
		fs2 << "2. size: " << myints_.size() << '\n';

		myints_.pop_back();
		fs2 << "3. size: " << myints_.size() << std::endl;
	}

	judge(7);

	{
		std::vector<int> myvector;

//		 set some content in the vector:
		for (int i = 0; i < 100; i++) myvector.push_back(i);

		fs1 << "size: " << myvector.size() << "\n";
		fs1 << "capacity: " << myvector.capacity() << "\n";
		fs1 << "max_size: " << myvector.max_size() << "\n" << std::flush;

		ft::vector<int> myvector_;

//		 set some content in the vector:
		for (int i = 0; i < 100; i++) myvector_.push_back(i);

		fs2 << "size: " << myvector_.size() << "\n";
		fs2 << "capacity: " << myvector_.capacity() << "\n";
		fs2 << "max_size: " << myvector_.max_size() << "\n" << std::flush;
	}

	judge(8);

	{
		std::vector<int> myvector;

//		 set some initial content:
		for (unsigned long i = 1; i < 10; i++) myvector.push_back(i);

		myvector.resize(8, 100);

		fs1 << "myvector contains:";
		for (unsigned long i = 0; i < myvector.size(); i++)
			fs1 << ' ' << myvector[i];
		fs1 << std::endl;

		ft::vector<int> myvector_;

//		 set some initial content:
		for (unsigned long i = 1; i < 10; i++) myvector_.push_back(i);

		myvector_.resize(8, 100);

		fs2 << "myvector contains:";
		for (unsigned long i = 0; i < myvector_.size(); i++)
			fs2 << ' ' << myvector_[i];
		fs2 << std::endl;
	}

	judge(9);

	{
		std::vector<int> myvector;

//		 set some content in the vector:
		for (int i = 0; i < 100; i++) myvector.push_back(i);

		fs1 << "size: " << (int)myvector.size() << '\n';
		fs1 << "capacity: " << (int)myvector.capacity() << '\n';
		fs1 << "max_size: " << (int)myvector.max_size() << std::endl;

		ft::vector<int> myvector_;

//		 set some content in the vector:
		for (int i = 0; i < 100; i++) myvector_.push_back(i);

		fs2 << "size: " << (int)myvector_.size() << '\n';
		fs2 << "capacity: " << (int)myvector_.capacity() << '\n';
		fs2 << "max_size: " << (int)myvector_.max_size() << std::endl;
	}

	judge(10);

	{
		std::vector<int> myvector;
		int sum(0);

		for (int i = 1; i <= 10; i++) myvector.push_back(i);

		while (!myvector.empty()) {
			sum += myvector.back();
			myvector.pop_back();
		}

		fs1 << "total: " << sum << std::endl;

		ft::vector<int> myvector_;
		int sum_(0);

		for (int i = 1; i <= 10; i++) myvector_.push_back(i);

		while (!myvector_.empty()) {
			sum_ += myvector_.back();
			myvector_.pop_back();
		}

		fs2 << "total: " << sum_ << std::endl;
	}

	judge(11);

	{
		std::vector<int>::size_type sz;

		std::vector<int> foo;
		sz = foo.capacity();
		fs1 << "making foo grow:\n";
		for (int i = 0; i < 100; ++i) {
			foo.push_back(i);
			if (sz != foo.capacity()) {
				sz = foo.capacity();
				fs1 << "capacity changed: " << sz << '\n';
			}
		}

		std::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);  // this is the only difference with foo above
		fs1 << "making bar grow:\n";
		for (int i = 0; i < 100; ++i) {
			bar.push_back(i);
			if (sz != bar.capacity()) {
				sz = bar.capacity();
				fs1 << "capacity changed: " << sz << std::endl;
			}
		}

		ft::vector<int>::size_type sz_;

		ft::vector<int> foo_;
		sz_ = foo_.capacity();
		fs2 << "making foo grow:\n";
		for (int i = 0; i < 100; ++i) {
			foo_.push_back(i);
			if (sz_ != foo_.capacity()) {
				sz_ = foo_.capacity();
				fs2 << "capacity changed: " << sz_ << '\n';
			}
		}

		ft::vector<int> bar_;
		sz_ = bar_.capacity();
		bar_.reserve(100);  // this is the only difference with foo above
		fs2 << "making bar grow:\n";
		for (int i = 0; i < 100; ++i) {
			bar_.push_back(i);
			if (sz_ != bar_.capacity()) {
				sz_ = bar_.capacity();
				fs2 << "capacity changed: " << sz_ << std::endl;
			}
		}
	}

	judge(12);

	{
		std::vector<int> myvector(10);  // 10 zero-initialized elements

		std::vector<int>::size_type sz = myvector.size();

//		 assign some values:
		for (unsigned i = 0; i < sz; i++) myvector[i] = i;

//		 reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++) {
			int temp;
			temp = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i] = temp;
		}

		fs1 << "myvector contains:";
		for (unsigned i = 0; i < sz; i++) fs1 << ' ' << myvector[i];
		fs1 << std::endl;

		ft::vector<int> myvector_(10);  // 10 zero-initialized elements

		ft::vector<int>::size_type sz_ = myvector_.size();

//		 assign some values:
		for (unsigned i = 0; i < sz_; i++) myvector_[i] = i;

//		 reverse vector using operator[]:
		for (unsigned i = 0; i < sz_ / 2; i++) {
			int temp;
			temp = myvector_[sz_ - 1 - i];
			myvector_[sz_ - 1 - i] = myvector_[i];
			myvector_[i] = temp;
		}

		fs2 << "myvector contains:";
		for (unsigned i = 0; i < sz_; i++) fs2 << ' ' << myvector_[i];
		fs2 << std::endl;
	}

	judge(13);

	{
		std::vector<int> myvector(10);  // 10 zero-initialized ints

//		 assign some values:
		for (unsigned i = 0; i < myvector.size(); i++) myvector.at(i) = i;

		try {
			fs1 << "myvector contains:";
			for (unsigned i = 0; i < 12; i++) fs1 << ' ' << myvector.at(i);
			fs1 << '\n';
		} catch (const std::out_of_range& e) {
			fs1 << e.what() << std::endl;
		}

		ft::vector<int> myvector_(10);  // 10 zero-initialized ints

//		 assign some values:
		for (unsigned i = 0; i < myvector_.size(); i++) myvector_.at(i) = i;

		try {
			fs2 << "myvector contains:";
			for (unsigned i = 0; i < 12; i++) fs2 << ' ' << myvector_.at(i);
			fs2 << '\n';
		} catch (const std::out_of_range& e) {
			fs2 << e.what() << std::endl;
		}
	}

	judge(14);

	{
		std::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

//		 now front equals 78, and back 16

		myvector.front() -= myvector.back();

		fs1 << "myvector.front() is now " << myvector.front() << std::endl;

		ft::vector<int> myvector_;

		myvector_.push_back(78);
		myvector_.push_back(16);

//		 now front equals 78, and back 16

		myvector_.front() -= myvector_.back();

		fs2 << "myvector.front() is now " << myvector_.front() << '\n'
			<< std::flush;
	}

	judge(15);

	{
		std::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0) {
			myvector.push_back(myvector.back() - 1);
		}

		fs1 << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++) fs1 << ' ' << myvector[i];
		fs1 << std::endl;

		ft::vector<int> myvector_;

		myvector_.push_back(10);

		while (myvector_.back() != 0) {
			myvector_.push_back(myvector_.back() - 1);
		}

		fs2 << "myvector contains:";
		for (unsigned i = 0; i < myvector_.size(); i++) fs2 << ' ' << myvector_[i];
		fs2 << std::endl;
	}

	judge(16);

	{
		std::vector<int> first;
		std::vector<int> second;
		std::vector<int> third;

		first.assign(7, 100);  // 7 ints with a value of 100

		std::vector<int>::iterator it;
		it = first.begin() + 1;

		second.assign(it, first.end() - 1);  // the 5 central values of first

		int myints[] = {1776, 7, 4};
		third.assign(myints, myints + 3);  // assigning from array.

		fs1 << "Size of first: " << int(first.size()) << '\n';
		fs1 << "Size of second: " << int(second.size()) << '\n';
		fs1 << "Size of third: " << int(third.size()) << std::endl;

		ft::vector<int> first_;
		ft::vector<int> second_;
		ft::vector<int> third_;

		first_.assign(7, 100);  // 7 ints with a value of 100

		ft::vector<int>::iterator it_;
		it_ = first_.begin() + 1;

		second_.assign(it_, first_.end() - 1);  // the 5 central values of first_

		int myints_[] = {1776, 7, 4};
		third_.assign(myints_, myints_ + 3);  // assigning from array.

		fs2 << "Size of first: " << int(first_.size()) << '\n';
		fs2 << "Size of second: " << int(second_.size()) << '\n';
		fs2 << "Size of third: " << int(third_.size()) << std::endl;
	}

	judge(17);

	{
		std::vector<int> myvector;

		fs1 << "Please enter some integers (enter 0 to end):\n";

		for (int i = 0; i < 42; i++) myvector.push_back(i);

		fs1 << "myvector stores " << int(myvector.size()) << " numbers.\n"
			<< std::flush;

		ft::vector<int> myvector_;

		fs2 << "Please enter some integers (enter 0 to end):\n";

		for (int i = 0; i < 42; i++) myvector_.push_back(i);

		fs2 << "myvector stores " << int(myvector_.size()) << " numbers.\n"
			<< std::flush;
	}

	judge(18);

	{
		std::vector<int> myvector;
		int sum(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		while (!myvector.empty()) {
			sum += myvector.back();
			myvector.pop_back();
		}

		fs1 << "The elements of myvector add up to " << sum << std::endl;

		ft::vector<int> myvector_;
		int sum_(0);
		myvector_.push_back(100);
		myvector_.push_back(200);
		myvector_.push_back(300);

		while (!myvector_.empty()) {
			sum_ += myvector_.back();
			myvector_.pop_back();
		}

		fs2 << "The elements of myvector add up to " << sum_ << std::endl;
	}

	judge(19);

	{
		std::vector<int> myvector(3, 100);
		std::vector<int>::iterator it;
		std::vector<int>::iterator it_tmp;

		it_tmp = it = myvector.begin();
		it = myvector.insert(it, 200);

		myvector.insert(it, 2, 300);

//		 "it" no longer valid, get a new one:
		it = myvector.begin();

		std::vector<int> anothervector(2, 400);
		myvector.insert(it + 2, anothervector.begin(), anothervector.end());

		int myarray[] = {501, 502, 503};
		myvector.insert(myvector.begin(), myarray, myarray + 3);

		fs1 << "myvector contains:";
		for (it = myvector.begin(); it < myvector.end(); it++) fs1 << ' ' << *it;
		fs1 << std::endl;

		ft::vector<int> myvector_(3, 100);
		ft::vector<int>::iterator it_;
		ft::vector<int>::iterator it__tmp;

		it__tmp = it_ = myvector_.begin();
		it_ = myvector_.insert(it_, 200);

		myvector_.insert(it_, 2, 300);

//		 "it_" no longer valid, get a new one:
		it_ = myvector_.begin();

		ft::vector<int> anothervector_(2, 400);
		myvector_.insert(it_ + 2, anothervector_.begin(), anothervector_.end());

		int myarray_[] = {501, 502, 503};
		myvector_.insert(myvector_.begin(), myarray_, myarray_ + 3);

		fs2 << "myvector contains:";
		for (it_ = myvector_.begin(); it_ < myvector_.end(); it_++)
			fs2 << ' ' << *it_;
		fs2 << std::endl;
	}

	judge(20);

	{
		std::vector<int> myvector;

//		 set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++) myvector.push_back(i);

//		 erase the 6th element
		myvector.erase(myvector.begin() + 5);

//		 erase the first 3 elements:
		myvector.erase(myvector.begin(), myvector.begin() + 3);

		fs1 << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); ++i) fs1 << ' ' << myvector[i];
		fs1 << std::endl;

		ft::vector<int> myvector_;

//		 set some values (from 1 to 10)
		for (int i = 1; i <= 10; i++) myvector_.push_back(i);

//		 erase the 6th element
		myvector_.erase(myvector_.begin() + 5);

//		 erase the first 3 elements:
		myvector_.erase(myvector_.begin(), myvector_.begin() + 3);

		fs2 << "myvector contains:";
		for (unsigned i = 0; i < myvector_.size(); ++i) fs2 << ' ' << myvector_[i];
		fs2 << std::endl;
	}

	judge(21);

	{
		std::vector<int> foo(3, 100);  // three ints with a value of 100
		std::vector<int> bar(5, 200);  // five ints with a value of 200

		foo.swap(bar);

		fs1 << "foo contains:";
		for (unsigned i = 0; i < foo.size(); i++) fs1 << ' ' << foo[i];
		fs1 << '\n';

		fs1 << "bar contains:";
		for (unsigned i = 0; i < bar.size(); i++) fs1 << ' ' << bar[i];
		fs1 << std::endl;

		ft::vector<int> foo_(3, 100);  // three ints with a value of 100
		ft::vector<int> bar_(5, 200);  // five ints with a value of 200

		foo_.swap(bar_);

		fs2 << "foo contains:";
		for (unsigned i = 0; i < foo_.size(); i++) fs2 << ' ' << foo_[i];
		fs2 << '\n';

		fs2 << "bar contains:";
		for (unsigned i = 0; i < bar_.size(); i++) fs2 << ' ' << bar_[i];
		fs2 << std::endl;
	}

	judge(22);

	{
		std::vector<int> myvector;
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);

		fs1 << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++) fs1 << ' ' << myvector[i];
		fs1 << '\n';

		myvector.clear();
		myvector.push_back(1101);
		myvector.push_back(2202);

		fs1 << "myvector contains:";
		for (unsigned i = 0; i < myvector.size(); i++) fs1 << ' ' << myvector[i];
		fs1 << std::endl;

		ft::vector<int> myvector_;
		myvector_.push_back(100);
		myvector_.push_back(200);
		myvector_.push_back(300);

		fs2 << "myvector contains:";
		for (unsigned i = 0; i < myvector_.size(); i++) fs2 << ' ' << myvector_[i];
		fs2 << '\n';

		myvector_.clear();
		myvector_.push_back(1101);
		myvector_.push_back(2202);

		fs2 << "myvector contains:";
		for (unsigned i = 0; i < myvector_.size(); i++) fs2 << ' ' << myvector_[i];
		fs2 << std::endl;
	}

	judge(23);

	{
		std::vector<int> foo(3, 100);  // three ints with a value of 100
		std::vector<int> bar(2, 200);  // two ints with a value of 200

		if (foo == bar) fs1 << "foo and bar are equal\n";
		if (foo != bar) fs1 << "foo and bar are not equal\n";
		if (foo < bar) fs1 << "foo is less than bar\n";
		if (foo > bar) fs1 << "foo is greater than bar\n";
		if (foo <= bar) fs1 << "foo is less than or equal to bar\n";
		if (foo >= bar)
			fs1 << "foo is greater than or equal to bar\n" << std::flush;

		ft::vector<int> foo_(3, 100);  // three ints with a value of 100
		ft::vector<int> bar_(2, 200);  // two ints with a value of 200

		if (foo_ == bar_) fs2 << "foo and bar are equal\n";
		if (foo_ != bar_) fs2 << "foo and bar are not equal\n";
		if (foo_ < bar_) fs2 << "foo is less than bar\n";
		if (foo_ > bar_) fs2 << "foo is greater than bar\n";
		if (foo_ <= bar_) fs2 << "foo is less than or equal to bar\n";
		if (foo_ >= bar_)
			fs2 << "foo is greater than or equal to bar\n" << std::flush;
	}

	judge(24);

	{
		std::vector<int> foo(3, 100);  // three ints with a value of 100
		std::vector<int> bar(5, 200);  // five ints with a value of 200

		foo.swap(bar);

		fs1 << "foo contains:";
		for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
			fs1 << ' ' << *it;
		fs1 << '\n';

		fs1 << "bar contains:";
		for (std::vector<int>::iterator it = bar.begin(); it != bar.end(); ++it)
			fs1 << ' ' << *it;
		fs1 << std::endl;

		ft::vector<int> foo_(3, 100);  // three ints with a value of 100
		ft::vector<int> bar_(5, 200);  // five ints with a value of 200

		foo_.swap(bar_);

		fs2 << "foo contains:";
		for (ft::vector<int>::iterator it = foo_.begin(); it != foo_.end(); ++it)
			fs2 << ' ' << *it;
		fs2 << '\n';

		fs2 << "bar contains:";
		for (ft::vector<int>::iterator it = bar_.begin(); it != bar_.end(); ++it)
			fs2 << ' ' << *it;
		fs2 << std::endl;
	}
*/
}


