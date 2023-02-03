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
#include <stack>

clock_t time_begin();
void time_end(clock_t start, std::string const &msg);
void vector(std::ofstream &std);
void map(std::ofstream &std);
void stack(std::ofstream &std);
int	main()
{
	system("mkdir output");
	std::cout << "=======================================" << std::endl;
//	vector test
	{
		/* === VECTOR === */
		std::ofstream vec_std;
		vec_std.open("output/vec_std");
		vector(vec_std);
		vec_std << std::flush;
	}
	std::cout << "============[VECTOR DONE !!]============" << std::endl;
//	map test
	{
		std::ofstream map_std;
		map_std.open("output/map_std");
		map(map_std);
		map_std << std::flush;
	}
	std::cout << "=============[MAP DONE !!]=============" << std::endl;
//	stack test
	{
		std::ofstream stack_std;
		stack_std.open("output/stack_std");
		stack(stack_std);
		stack_std << std::flush;
	}
	std::cout << "============[STACK DONE !!]============" << std::endl;
}

void time_end(clock_t start, std::string const &msg) {
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << msg <<": " << duration << "m seconds" << std::endl;
	std::cout << std::flush;
}

clock_t time_begin() {
	clock_t start = clock();
	return start;
}

void stack(std::ofstream &std) {

	{
		clock_t start = time_begin();
		std::stack<int> a;
		std::stack<int, std::vector<int> > b;
		std::deque<int> c(50, 100);
		std::stack<int> d(c);
		std::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		std << a.empty();
		std << b.empty();
		std << c.empty();
		std << d.empty();
		std << e.empty();
		time_end(start, "std[constructor, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::stack<int> a;
		std::stack<int, std::vector<int> > b;
		std::deque<int> c(50, 100);
		std::stack<int> d(c);
		std::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			b.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			d.push(i);
		}

		std << a.size() << std::endl;
		std << a.top() << std::endl;
		a.pop();
		for (;!a.empty();) {
			std << a.top() << std::endl;
			a.pop();
		}
		std << b.size() << std::endl;
		std << b.top() << std::endl;
		b.pop();
		for (;!b.empty();) {
			std << b.top() << std::endl;
			b.pop();
		}
		std << d.size() << std::endl;
		std << d.top() << std::endl;
		d.pop();
		for (;!d.empty();) {
			std << d.top() << std::endl;
			d.pop();
		}
		std << e.size() << std::endl;

		time_end(start, "std[pop, push, top, size, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::stack<int> a;
		std::stack<int, std::deque<int> > b;
		std::deque<int> c(50, 100);
		std::stack<int> d(c);
		std::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			b.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			d.push(i);
		}
		std << (a == b) << std::endl;
		std << (a != b) << std::endl;
		std << (a <= b) << std::endl;
		std << (a >= b) << std::endl;
		std << (a < b) << std::endl;
		std << (a > b) << std::endl;
		std << (a == b) << std::endl;
		std << (d == b) << std::endl;
		std << (d != b) << std::endl;
		std << (d <= b) << std::endl;
		std << (d >= b) << std::endl;
		std << (d < b) << std::endl;
		std << (d > b) << std::endl;
		std << (d == b) << std::endl;
		std << (a == d) << std::endl;
		std << (a != d) << std::endl;
		std << (a <= d) << std::endl;
		std << (a >= d) << std::endl;
		std << (a < d) << std::endl;
		std << (a > d) << std::endl;
		std << (d == b) << std::endl;
		std << (a == a) << std::endl;
		std << (a != a) << std::endl;
		std << (a <= a) << std::endl;
		std << (a >= a) << std::endl;
		std << (a < a) << std::endl;
		std << (a > a) << std::endl;
		time_end(start, "std[operators]");
	}

}

void map(std::ofstream &std) {

	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				std << it->second << ' ' << std::endl;
			}
			time_end(start, "std[constructor]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			for (std::map<int, std::string>::reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
				std << it->second << ' ' << std::endl;
			}
			time_end(start, "std[reverse_iterator]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			for (std::map<int, std::string>::const_reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
				std << it->second << ' ' << std::endl;
			}
			time_end(start, "std[const_reverse_iterator]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			for (std::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
				std << it->second << ' ' << std::endl;
				it->second = "test";
			}
			for (std::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
				std << it->second << ' ' << std::endl;
			}

			time_end(start, "std[iterator]");
		}
		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);
			std << a.empty() << std::endl;
			std << b.empty() << std::endl;
			std << c.empty() << std::endl;
			time_end(start, "std[empty]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);
			std << a.size() << std::endl;
			std << b.size() << std::endl;
			std << c.size() << std::endl;
			time_end(start, "std[size]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);
			std << a.max_size() << std::endl;
			std << b.max_size() << std::endl;
			std << c.max_size() << std::endl;
			time_end(start, "std[max_size]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			std::pair<int, std::string> pair(1, "PIYO");
			b.insert(std::make_pair(1, "TEST"));
			c.insert(c.begin(), c.end());
			a.insert(a.begin(), pair);
			for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
				std << it->second << ' ';
			}
			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				std << it->second << ' ';
			}
			for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
				std << it->second << ' ';
			}

			time_end(start, "std[insert]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			std::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			std::map<int, std::string> b(a.begin(), a.end());
			std::map<int, std::string> c(b);

			std::pair<int, std::string> pair(1, "PIYO");
			b.insert(std::make_pair(1, "TEST"));
			b.erase(b.begin());
			//erase にend()が入ってきたらsegv
			c.insert(c.begin(), c.end());
			c.erase(c.begin(), --c.end() );
			a.erase(1);
			a.erase(3);
			for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
				std << it->second << ' ';
			}
			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				std << it->second << ' ';
			}
			for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
				std << it->second << ' ';
			}

			time_end(start, "std[erase]");
		}

		std::cout  << std::endl;
	}
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string> b(a.begin(), a.end());
		std::map<int, std::string> c(b);

		std::pair<int, std::string> pair(1, "PIYO");
		b.insert(std::make_pair(1, "TEST"));
		b.erase(b.begin());
		//erase にend()が入ってきたらsegv
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			std << it->second << ' ';
		}
		for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
			std << it->second << ' ';
		}
		for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << it->second << ' ';
		}

		time_end(start, "std[swap]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string> b(a.begin(), a.end());
		std::map<int, std::string> c(b);

		std::pair<int, std::string> pair(1, "PIYO");
		b.insert(std::make_pair(1, "TEST"));
		b.erase(b.begin());
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		a.clear();
		b.clear();
		c.clear();

		for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			std << it->second << ' ';
		}
		for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
			std << it->second << ' ';
		}
		for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << it->second << ' ';
		}

		time_end(start, "std[clear]");
	}
	std::cout << std::endl;

	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string >::key_compare map_value_compare = a.key_comp();
		(void)map_value_compare;
		std::map<int, std::string, std::map<int, std::string >::key_compare> b;
		for(std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			std << it->second << ' ';
		}
		std << "test" << std::endl;
		time_end(start, "std[key_compare]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string> b(a.begin(), a.end());
		std::map<int, std::string> c(b);

		std::pair<int, std::string> pair(1, "PIYO");
		b.insert(std::make_pair(1, "TEST"));
		b.erase(b.begin());
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		std << std::map<int, std::string>::const_iterator(a.find(2))->second << std::endl;
		std << std::map<int, std::string>::iterator(a.find(2))->second << std::endl;
		std << std::map<int, std::string>::iterator(b.find(2))->second << std::endl;

		time_end(start, "std[find]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string> b(a.begin(), a.end());
		std::map<int, std::string> c(b);

		std::pair<int, std::string> pair(1, "PIYO");
		b.insert(std::make_pair(1, "TEST"));
		b.erase(b.begin());
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		std << a.count(2) << std::endl;
		std << a.count(2) << std::endl;
		std << b.count(2) << std::endl;
		std << b.count(2) << std::endl;

		time_end(start, "std[count]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std << std::map<int, std::string>::iterator(a.lower_bound(3))->second << std::endl;
		std << std::map<int, std::string>::const_iterator (a.lower_bound(3))->second << std::endl;
		std << std::map<int, std::string>::iterator(a.upper_bound(3))->second << std::endl;
		std << std::map<int, std::string>::const_iterator (a.upper_bound(3))->second << std::endl;
		std << std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator>(a.equal_range(3)).second->second << std::endl;
		std << std::pair<std::map<int, std::string>::iterator , std::map<int, std::string>::iterator >(a.equal_range(3)).second->second << std::endl;
		time_end(start, "std[bound]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string>::allocator_type alloc = a.get_allocator();
		std << alloc.max_size() << std::endl;
		time_end(start, "std[alloc]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string > b;
		b[1] = "one";
		b[2] = "two";
		b[3] = "three";
		b[4] = "four";

		std::map<int, std::string > c;
		b[1] = "one";
		b[100] = "two";
		b[3] = "three";
		b[4] = "four";

		std << (a == b) << std::endl;
		std << (a != b) << std::endl;
		std << (a < b) << std::endl;
		std << (a <= b) << std::endl;
		std << (a > b) << std::endl;
		std << (a >= b) << std::endl;
		std << (c == b) << std::endl;
		std << (c != b) << std::endl;
		std << (c < b) << std::endl;
		std << (c <= b) << std::endl;
		std << (c > b) << std::endl;
		std << (c >= b) << std::endl;
		std << (c == a) << std::endl;
		std << (c != a) << std::endl;
		std << (c < a) << std::endl;
		std << (c <= a) << std::endl;
		std << (c > a) << std::endl;
		std << (c >= a) << std::endl;
		time_end(start, "std[operators]");
	}
	std::cout << std::endl;

}

void vector(std::ofstream &std) {

	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = e.begin(); it != e.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = f.begin(); it != f.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[constructor]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a(10, 50);
		a.assign(50, 20);
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << ' ';
		}
		a.assign(50, 20);
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << ' ';
		}
		a.assign(10, 20);
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << ' ';
		}

		std::vector<int> b;
		b.assign(a.begin(), a.end());
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << ' ';
		}
		time_end(start, "std[assign]");
	}
	std::cout << std::endl;
	{
		try {

			clock_t start = time_begin();
			std::vector<int> a;
			std::allocator<int> alloc;
			std::vector<int> c(alloc);
			std::vector<int> b(100, 50);
			std::vector<int> d(10, 50, alloc);
			std::vector<int> e(b.begin(), b.end());
			std::vector<int> f(e);
			a = b;
			for (int i = 0; i < 100; ++i) {
				std << b.at(i) << std::endl;
			}
			for (int i = 0; i < 100; ++i) {
				std << e.at(i) << std::endl;
			}
			for (int i = 0; i < 100; ++i) {
				std << b.at(i) << std::endl;
			}
			time_end(start, "std[at]");

		} catch (const std::exception &e) {
			std << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;
		for (int i = 0; i < 100; ++i) {
			std << b[i] << std::endl;
		}
		for (int i = 0; i < 100; ++i) {
			std << e[i] << std::endl;
		}
		for (int i = 0; i < 100; ++i) {
			std << b[i] << std::endl;
		}
		time_end(start, "std[]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a(100, 50);
		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}

		for (std::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[iterator]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a(100, 50);
		std << a.front() << std::endl;
		std << a.back() << std::endl;
		std << *a.data() << std::endl;
		std << *a.data() << std::endl;
		time_end(start, "std[back, front, data]");

	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		std << a.size() << std::endl;
		std << a.empty() << std::endl;
		std << b.size() << std::endl;
		std << b.empty() << std::endl;
		std << e.size() << std::endl;
		std << e.empty() << std::endl;
		std << b.size() << std::endl;
		std << b.empty() << std::endl;
		time_end(start, "std[size, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		a.clear();
		b.clear();
		c.clear();
		d.clear();
		e.clear();
		f.clear();
		std << a.size() << std::endl;
		std << a.empty() << std::endl;
		std << a.max_size() << std::endl;
		std << a.capacity() << std::endl;
		std << b.size() << std::endl;
		std << b.empty() << std::endl;
		std << b.max_size() << std::endl;
		std << b.capacity() << std::endl;
		std << e.size() << std::endl;
		std << e.empty() << std::endl;
		std << e.max_size() << std::endl;
		std << e.capacity() << std::endl;
		std << b.size() << std::endl;
		std << b.empty() << std::endl;
		std << b.max_size() << std::endl;
		std << b.capacity() << std::endl;
		std << e.size() << std::endl;
		std << e.empty() << std::endl;
		std << e.max_size() << std::endl;
		std << e.capacity() << std::endl;
		std << f.size() << std::endl;
		std << f.empty() << std::endl;
		std << f.max_size() << std::endl;
		std << f.capacity() << std::endl;
		time_end(start, "std[size, empty, max_size, capacity]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		for (int i = 0; i < 1000; ++i) {
			a.push_back(i);
		}
		for (int i = 0; i < 200; ++i) {
			b.push_back(i);
		}
		for (int i = -100; i < 0; ++i) {
			c.push_back(i);
		}
		for (int i = 1000; i < 2000; ++i) {
			e.push_back(i);
		}
		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[push_back]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		for (int i = 0; i < 1000; ++i) {
			a.push_back(i);
		}
		for (int i = 0; i < 200; ++i) {
			b.push_back(i);
		}
		for (int i = -100; i < 0; ++i) {
			c.push_back(i);
		}
		for (int i = 1000; i < 2000; ++i) {
			e.push_back(i);
		}
		a.pop_back();
		b.pop_back();
		c.pop_back();
		d.pop_back();
		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[pop_back]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		for (int i = 0; i < 1000; ++i) {
			a.push_back(i);
		}
		for (int i = 0; i < 200; ++i) {
			b.push_back(i);
		}
		for (int i = -100; i < 0; ++i) {
			c.push_back(i);
		}
		for (int i = 1000; i < 2000; ++i) {
			e.push_back(i);
		}
		a.erase(a.begin());
		for (std::vector<int>::iterator it = a.begin(); !a.empty();) {
			a.erase(it);
		}
		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		b.erase(b.begin(), b.end() - 1);
		for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[erase]");
	}
	{
		try {
			clock_t start = time_begin();
			std::vector<int> a;
			std::allocator<int> alloc;
			std::vector<int> c(alloc);
			std::vector<int> b(100, 50);
			std::vector<int> d(10, 50, alloc);
			std::vector<int> e(b.begin(), b.end());
			std::vector<int> f(e);
			a = b;

			for (int i = 0; i < 1000; ++i) {
				a.push_back(i);
			}
			for (int i = 0; i < 200; ++i) {
				b.push_back(i);
			}
			for (int i = -100; i < 0; ++i) {
				c.push_back(i);
			}
			for (int i = 1000; i < 2000; ++i) {
				e.push_back(i);
			}

			a.reserve(100);
			b.reserve(50);
			c.reserve(0);
//			d.reserve(d.max_size() - 1);

			time_end(start, "std[reserve]");


		}catch (const std::exception &e){
			//bad alloc
			std << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		std << a.capacity();
		std << b.capacity();
		std << c.capacity();
		std << d.capacity();
		std << e.capacity();
		std << f.capacity();
		time_end(start, "std[capacity]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		a.insert(a.begin() + 1, b.begin(), b.end());
		for(std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		b.insert(b.begin(), 10);
		for(std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		c.insert(c.end(), 100, 100);
		for(std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[insert]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		a.swap(b);
		for(std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		b.swap(c);
		for(std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		c.swap(a);
		for(std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[swap]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		a.resize(10, 10);
		for(std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		b.resize(100, 50);
		for(std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			std << *it << std::endl;
		}
		c.resize(42, 42);
		for(std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			std << *it << std::endl;
		}
		time_end(start, "std[resize]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		std::vector<int> a;
		std::allocator<int> alloc;
		std::vector<int> c(alloc);
		std::vector<int> b(100, 50);
		std::vector<int> d(10, 50, alloc);
		std::vector<int> e(b.begin(), b.end());
		std::vector<int> f(e);
		a = b;

		std << (a == c) << std::endl;
		std << (a <= c) << std::endl;
		std << (a >= c) << std::endl;
		std << (a < c) << std::endl;
		std << (a > c) << std::endl;
		std << (a != c) << std::endl;
		std << (b == c) << std::endl;
		std << (b <= c) << std::endl;
		std << (b >= c) << std::endl;
		std << (b < c) << std::endl;
		std << (b > c) << std::endl;
		std << (b != c) << std::endl;
		std << (d == c) << std::endl;
		std << (d <= c) << std::endl;
		std << (d >= c) << std::endl;
		std << (d < c) << std::endl;
		std << (d > c) << std::endl;
		std << (d != c) << std::endl;
		std << (a == c) << std::endl;
		std << (a <= c) << std::endl;
		std << (a >= c) << std::endl;
		std << (a < c) << std::endl;
		std << (a > c) << std::endl;
		std << (a != e) << std::endl;
		std << (b == e) << std::endl;
		std << (b <= e) << std::endl;
		std << (b >= e) << std::endl;
		std << (b < e) << std::endl;
		std << (b > e) << std::endl;
		std << (b != e) << std::endl;
		time_end(start, "std[operators]");
	}
}


