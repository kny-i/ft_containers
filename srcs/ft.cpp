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
void vector(std::ofstream &mine);
void map(std::ofstream &mine);
void stack(std::ofstream &mine);
int	main()
{
	system("mkdir output");
	std::cout << "=======================================" << std::endl;
//	vector test
	{
		/* === VECTOR === */
		std::ofstream vec_mine;
		vec_mine.open("output/vec_mine");
		vector(vec_mine);
		vec_mine << std::flush;
	}
	std::cout << "============[VECTOR DONE !!]============" << std::endl;
//	map test
	{
		std::ofstream map_mine;
		map_mine.open("output/map_mine");
		map(map_mine);
		map_mine << std::flush;
	}
	std::cout << "=============[MAP DONE !!]=============" << std::endl;
//	stack test
	{
		std::ofstream stack_mine;
		stack_mine.open("output/stack_mine");
		stack(stack_mine);
		stack_mine << std::flush;
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

void stack(std::ofstream &mine) {

	{
		clock_t start = time_begin();
		ft::stack<int> a;
		ft::stack<int, ft::vector<int> > b;
		ft::vector <int> c(50, 100);
		ft::stack<int> d(c);
		ft::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		mine << a.empty();
		mine << b.empty();
		mine << c.empty();
		mine << d.empty();
		mine << e.empty();
		time_end(start, "mine[constructor, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::stack<int> a;
		ft::stack<int, ft::vector<int> > b;
		ft::vector <int> c(50, 100);
		ft::stack<int> d(c);
		ft::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			b.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			d.push(i);
		}

		mine << a.size() << std::endl;
		mine << a.top() << std::endl;
		a.pop();
		for (;!a.empty();) {
			mine << a.top() << std::endl;
			a.pop();
		}
		mine << b.size() << std::endl;
		mine << b.top() << std::endl;
		b.pop();
		for (;!b.empty();) {
			mine << b.top() << std::endl;
			b.pop();
		}
		mine << d.size() << std::endl;
		mine << d.top() << std::endl;
		d.pop();
		for (;!d.empty();) {
			mine << d.top() << std::endl;
			d.pop();
		}
		mine << e.size() << std::endl;

		time_end(start, "mine[pop, push, top, size, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::stack<int> a;
		ft::stack<int, ft::vector<int> > b;
		ft::vector<int> c(50, 100);
		ft::stack<int> d(c);
		ft::stack<int, std::deque<int> > e;



		for (int i = 0; i < 1000; ++i) {
			a.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			b.push(i);
		}
		for (int i = 100; i < 200; ++i) {
			d.push(i);
		}
		mine << (a == b) << std::endl;
		mine << (a != b) << std::endl;
		mine << (a <= b) << std::endl;
		mine << (a >= b) << std::endl;
		mine << (a < b) << std::endl;
		mine << (a > b) << std::endl;
		mine << (a == b) << std::endl;
		mine << (d == b) << std::endl;
		mine << (d != b) << std::endl;
		mine << (d <= b) << std::endl;
		mine << (d >= b) << std::endl;
		mine << (d < b) << std::endl;
		mine << (d > b) << std::endl;
		mine << (d == b) << std::endl;
		mine << (a == d) << std::endl;
		mine << (a != d) << std::endl;
		mine << (a <= d) << std::endl;
		mine << (a >= d) << std::endl;
		mine << (a < d) << std::endl;
		mine << (a > d) << std::endl;
		mine << (d == b) << std::endl;
		mine << (a == a) << std::endl;
		mine << (a != a) << std::endl;
		mine << (a <= a) << std::endl;
		mine << (a >= a) << std::endl;
		mine << (a < a) << std::endl;
		mine << (a > a) << std::endl;
		time_end(start, "mine[operators]");
	}

}

void map(std::ofstream &mine) {

	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				mine << it->second << ' ' << std::endl;
			}
			time_end(start, "mine[constructor]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			for (ft::map<int, std::string>::reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
				mine << it->second << ' ' << std::endl;
			}
			time_end(start, "mine[reverse_iterator]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			for (ft::map<int, std::string>::const_reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
				mine << it->second << ' ' << std::endl;
			}
			time_end(start, "mine[const_reverse_iterator]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			for (ft::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
				mine << it->second << ' ' << std::endl;
				it->second = "test";
			}
			for (ft::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
				mine << it->second << ' ' << std::endl;
			}

			time_end(start, "mine[iterator]");
		}
		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);
			mine << a.empty() << std::endl;
			mine << b.empty() << std::endl;
			mine << c.empty() << std::endl;
			time_end(start, "mine[empty]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);
			mine << a.size() << std::endl;
			mine << b.size() << std::endl;
			mine << c.size() << std::endl;
			time_end(start, "mine[size]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);
			mine << a.max_size() << std::endl;
			mine << b.max_size() << std::endl;
			mine << c.max_size() << std::endl;
			time_end(start, "mine[max_size]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			ft::pair<int, std::string> pair(1, "PIYO");
			b.insert(ft::make_pair(1, "TEST"));
			c.insert(c.begin(), c.end());
			a.insert(a.begin(), pair);
			for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
				mine << it->second << ' ';
			}
			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				mine << it->second << ' ';
			}
			for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
				mine << it->second << ' ';
			}

			time_end(start, "mine[insert]");
		}

		std::cout  << std::endl;
	}
	{
		{
			clock_t start = time_begin();
			ft::map<int, std::string > a;
			a[1] = "one";
			a[2] = "two";
			a[3] = "three";
			a[4] = "four";

			ft::map<int, std::string> b(a.begin(), a.end());
			ft::map<int, std::string> c(b);

			ft::pair<int, std::string> pair(1, "PIYO");
			b.insert(ft::make_pair(1, "TEST"));
			b.erase(b.begin());
			//erase にend()が入ってきたらsegv
			c.insert(c.begin(), c.end());
			c.erase(c.begin(), --c.end() );
			a.erase(1);
			a.erase(3);
			for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
				mine << it->second << ' ';
			}
			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
				mine << it->second << ' ';
			}
			for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
				mine << it->second << ' ';
			}

			time_end(start, "mine[erase]");
		}

		std::cout  << std::endl;
	}
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string> b(a.begin(), a.end());
		ft::map<int, std::string> c(b);

		ft::pair<int, std::string> pair(1, "PIYO");
		b.insert(ft::make_pair(1, "TEST"));
		b.erase(b.begin());
		//erase にend()が入ってきたらsegv
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			mine << it->second << ' ';
		}
		for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
			mine << it->second << ' ';
		}
		for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << it->second << ' ';
		}

		time_end(start, "mine[swap]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string> b(a.begin(), a.end());
		ft::map<int, std::string> c(b);

		ft::pair<int, std::string> pair(1, "PIYO");
		b.insert(ft::make_pair(1, "TEST"));
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

		for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			mine << it->second << ' ';
		}
		for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
			mine << it->second << ' ';
		}
		for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << it->second << ' ';
		}

		time_end(start, "mine[clear]");
	}
	std::cout << std::endl;

	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string >::key_compare map_value_compare = a.key_comp();
		(void)map_value_compare;
		ft::map<int, std::string, ft::map<int, std::string >::key_compare> b;
		for(ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			mine << it->second << ' ';
		}
		mine << "test" << std::endl;
		time_end(start, "mine[key_compare]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string> b(a.begin(), a.end());
		ft::map<int, std::string> c(b);

		ft::pair<int, std::string> pair(1, "PIYO");
		b.insert(ft::make_pair(1, "TEST"));
		b.erase(b.begin());
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		mine << ft::map<int, std::string>::const_iterator(a.find(2))->second << std::endl;
		mine << ft::map<int, std::string>::iterator(a.find(2))->second << std::endl;
		mine << ft::map<int, std::string>::iterator(b.find(2))->second << std::endl;

		time_end(start, "mine[find]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string> b(a.begin(), a.end());
		ft::map<int, std::string> c(b);

		ft::pair<int, std::string> pair(1, "PIYO");
		b.insert(ft::make_pair(1, "TEST"));
		b.erase(b.begin());
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		mine << a.count(2) << std::endl;
		mine << a.count(2) << std::endl;
		mine << b.count(2) << std::endl;
		mine << b.count(2) << std::endl;

		time_end(start, "mine[count]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		mine << ft::map<int, std::string>::iterator(a.lower_bound(3))->second << std::endl;
		mine << ft::map<int, std::string>::const_iterator (a.lower_bound(3))->second << std::endl;
		mine << ft::map<int, std::string>::iterator(a.upper_bound(3))->second << std::endl;
		mine << ft::map<int, std::string>::const_iterator (a.upper_bound(3))->second << std::endl;
		mine << ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator>(a.equal_range(3)).second->second << std::endl;
		mine << ft::pair<ft::map<int, std::string>::iterator , ft::map<int, std::string>::iterator >(a.equal_range(3)).second->second << std::endl;
		time_end(start, "mine[bound]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string>::allocator_type alloc = a.get_allocator();
		mine << alloc.max_size() << std::endl;
		time_end(start, "mine[alloc]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string > b;
		b[1] = "one";
		b[2] = "two";
		b[3] = "three";
		b[4] = "four";

		ft::map<int, std::string > c;
		b[1] = "one";
		b[100] = "two";
		b[3] = "three";
		b[4] = "four";

		mine << (a == b) << std::endl;
		mine << (a != b) << std::endl;
		mine << (a < b) << std::endl;
		mine << (a <= b) << std::endl;
		mine << (a > b) << std::endl;
		mine << (a >= b) << std::endl;
		mine << (c == b) << std::endl;
		mine << (c != b) << std::endl;
		mine << (c < b) << std::endl;
		mine << (c <= b) << std::endl;
		mine << (c > b) << std::endl;
		mine << (c >= b) << std::endl;
		mine << (c == a) << std::endl;
		mine << (c != a) << std::endl;
		mine << (c < a) << std::endl;
		mine << (c <= a) << std::endl;
		mine << (c > a) << std::endl;
		mine << (c >= a) << std::endl;
		time_end(start, "mine[operators]");
	}
	std::cout << std::endl;

}

void vector(std::ofstream &mine) {

	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = e.begin(); it != e.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = f.begin(); it != f.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[constructor]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a(10, 50);
		a.assign(50, 20);
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << ' ';
		}
		a.assign(50, 20);
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << ' ';
		}
		a.assign(10, 20);
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << ' ';
		}

		ft::vector<int> b;
		b.assign(a.begin(), a.end());
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << ' ';
		}
		time_end(start, "mine[assign]");
	}
	std::cout << std::endl;
	{
		try {

			clock_t start = time_begin();
			ft::vector<int> a;
			std::allocator<int> alloc;
			ft::vector<int> c(alloc);
			ft::vector<int> b(100, 50);
			ft::vector<int> d(10, 50, alloc);
			ft::vector<int> e(b.begin(), b.end());
			ft::vector<int> f(e);
			a = b;
			for (int i = 0; i < 100; ++i) {
				mine << b.at(i) << std::endl;
			}
			for (int i = 0; i < 100; ++i) {
				mine << e.at(i) << std::endl;
			}
			for (int i = 0; i < 100; ++i) {
				mine << b.at(i) << std::endl;
			}
			time_end(start, "mine[at]");

		} catch (const std::exception &e) {
			mine << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;
		for (int i = 0; i < 100; ++i) {
			mine << b[i] << std::endl;
		}
		for (int i = 0; i < 100; ++i) {
			mine << e[i] << std::endl;
		}
		for (int i = 0; i < 100; ++i) {
			mine << b[i] << std::endl;
		}
		time_end(start, "mine[]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a(100, 50);
		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}

		for (ft::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[iterator]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a(100, 50);
		mine << a.front() << std::endl;
		mine << a.back() << std::endl;
		mine << *a.data() << std::endl;
		mine << *a.data() << std::endl;
		time_end(start, "mine[back, front, data]");

	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		mine << a.size() << std::endl;
		mine << a.empty() << std::endl;
		mine << b.size() << std::endl;
		mine << b.empty() << std::endl;
		mine << e.size() << std::endl;
		mine << e.empty() << std::endl;
		mine << b.size() << std::endl;
		mine << b.empty() << std::endl;
		time_end(start, "mine[size, empty]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		a.clear();
		b.clear();
		c.clear();
		d.clear();
		e.clear();
		f.clear();
		mine << a.size() << std::endl;
		mine << a.empty() << std::endl;
		mine << a.max_size() << std::endl;
		mine << a.capacity() << std::endl;
		mine << b.size() << std::endl;
		mine << b.empty() << std::endl;
		mine << b.max_size() << std::endl;
		mine << b.capacity() << std::endl;
		mine << e.size() << std::endl;
		mine << e.empty() << std::endl;
		mine << e.max_size() << std::endl;
		mine << e.capacity() << std::endl;
		mine << b.size() << std::endl;
		mine << b.empty() << std::endl;
		mine << b.max_size() << std::endl;
		mine << b.capacity() << std::endl;
		mine << e.size() << std::endl;
		mine << e.empty() << std::endl;
		mine << e.max_size() << std::endl;
		mine << e.capacity() << std::endl;
		mine << f.size() << std::endl;
		mine << f.empty() << std::endl;
		mine << f.max_size() << std::endl;
		mine << f.capacity() << std::endl;
		time_end(start, "mine[size, empty, max_size, capacity]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
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
		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[push_back]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
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
		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[pop_back]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
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
		for (ft::vector<int>::iterator it = a.begin(); !a.empty();) {
			a.erase(it);
		}
		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		b.erase(b.begin(), b.end() - 1);
		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[erase]");
	}
	{
		try {
			clock_t start = time_begin();
			ft::vector<int> a;
			std::allocator<int> alloc;
			ft::vector<int> c(alloc);
			ft::vector<int> b(100, 50);
			ft::vector<int> d(10, 50, alloc);
			ft::vector<int> e(b.begin(), b.end());
			ft::vector<int> f(e);
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
			mine << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		mine << a.capacity();
		mine << b.capacity();
		mine << c.capacity();
		mine << d.capacity();
		mine << e.capacity();
		mine << f.capacity();
		time_end(start, "std[capacity]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		a.insert(a.begin() + 1, b.begin(), b.end());
		for(ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		b.insert(b.begin(), 10);
		for(ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		c.insert(c.end(), 100, 100);
		for(ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "std[insert]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		a.swap(b);
		for(ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		b.swap(c);
		for(ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		c.swap(a);
		for(ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[swap]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		a.resize(10, 10);
		for(ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		b.resize(100, 50);
		for(ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
			mine << *it << std::endl;
		}
		c.resize(42, 42);
		for(ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
			mine << *it << std::endl;
		}
		time_end(start, "mine[resize]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a;
		std::allocator<int> alloc;
		ft::vector<int> c(alloc);
		ft::vector<int> b(100, 50);
		ft::vector<int> d(10, 50, alloc);
		ft::vector<int> e(b.begin(), b.end());
		ft::vector<int> f(e);
		a = b;

		mine << (a == c) << std::endl;
		mine << (a <= c) << std::endl;
		mine << (a >= c) << std::endl;
		mine << (a < c) << std::endl;
		mine << (a > c) << std::endl;
		mine << (a != c) << std::endl;
		mine << (b == c) << std::endl;
		mine << (b <= c) << std::endl;
		mine << (b >= c) << std::endl;
		mine << (b < c) << std::endl;
		mine << (b > c) << std::endl;
		mine << (b != c) << std::endl;
		mine << (d == c) << std::endl;
		mine << (d <= c) << std::endl;
		mine << (d >= c) << std::endl;
		mine << (d < c) << std::endl;
		mine << (d > c) << std::endl;
		mine << (d != c) << std::endl;
		mine << (a == c) << std::endl;
		mine << (a <= c) << std::endl;
		mine << (a >= c) << std::endl;
		mine << (a < c) << std::endl;
		mine << (a > c) << std::endl;
		mine << (a != e) << std::endl;
		mine << (b == e) << std::endl;
		mine << (b <= e) << std::endl;
		mine << (b >= e) << std::endl;
		mine << (b < e) << std::endl;
		mine << (b > e) << std::endl;
		mine << (b != e) << std::endl;
		time_end(start, "mine[operators]");
	}
}


