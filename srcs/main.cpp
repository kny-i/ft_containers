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

void judge(std::string const &test_case);
clock_t time_begin();
void time_end(clock_t start, std::string const &msg);
void vector(std::ofstream &mine, std::ofstream &std);
void map(std::ofstream &mine, std::ofstream &std);
void stack(std::ofstream &mine, std::ofstream &std);
int	main()
{
	system("mkdir output");
	std::cout << "=======================================" << std::endl;
	//vector test
	{
		/* === VECTOR === */
		std::ofstream vec_mine;
		std::ofstream vec_std;
		vec_mine.open("output/vec_mine");
		vec_std.open("output/vec_std");
		vector(vec_mine, vec_std);
		vec_mine << std::flush;
		vec_std << std::flush;
		judge("vector");
	}

	//map test
	{
		std::ofstream map_mine;
		std::ofstream map_std;
		map_mine.open("output/map_mine");
		map_std.open("output/map_std");
		map(map_mine, map_std);
		map_mine << std::flush;
		map_std << std::flush;
		judge("map");
	}
	//stack test
	{
		std::ofstream stack_mine;
		std::ofstream stack_std;
		stack_mine.open("output/stack_mine");
		stack_std.open("output/stack_std");
		stack(stack_mine, stack_std);
		stack_mine << std::flush;
		stack_std << std::flush;
		judge("stack");
	}
}

void judge(std::string const &test_case) {

	if (test_case == "vector") {
		if (system("diff output/vec_mine output/vec_std") == 0)
			std::cout << "\033[32mvector[OK] \033[m\n";
		else
			std::cout << "\033[31mvector[KO] \033[m\n";
		std::cout << "============[VECTOR DONE !!]============" << std::endl;
		std::cout << std::flush;

	}else if (test_case == "map") {
		if (system("diff output/map_mine output/map_std") == 0)
			std::cout << "\033[32mmap[OK] \033[m\n";
		else
			std::cout << "\033[31mmap[KO] \033[m\n";
		std::cout << "=============[MAP DONE !!]=============" << std::endl;
		std::cout << std::flush;

	} else if (test_case == "stack") {
		if (system("diff output/stack_mine output/stack_std") == 0)
			std::cout << "\033[32mstack[OK] \033[m\n";
		else
			std::cout << "\033[31mstack[KO] \033[m\n";
		std::cout << "============[STACK DONE !!]============" << std::endl;
		std::cout << std::flush;
	}

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

void stack(std::ofstream &mine, std::ofstream &std) {


}

void map(std::ofstream &mine, std::ofstream &std) {

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

		time_end(start, "mine[swap]");
	}
	std::cout  << std::endl;
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
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string >::key_compare map_value_compare = a.key_comp();
		ft::map<int, std::string, ft::map<int, std::string >::key_compare> b;
		for(ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
			mine << it->second << ' ';
		}
		mine << "test" << std::endl;
		time_end(start, "mine[key_compare]");
	}
	{
		clock_t start = time_begin();
		std::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		std::map<int, std::string >::key_compare map_value_compare = a.key_comp();
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
		mine << ft::map<int, std::string>::const_iterator (b.find(2))->second << std::endl;
		mine << ft::map<int, std::string>::iterator(b.find(2))->second << std::endl;

		time_end(start, "mine[find]");
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
		c.insert(c.begin(), c.end());
		c.erase(c.begin(), --c.end() );
		a.erase(1);
		a.erase(3);
		a.swap(b);
		b.swap(c);
		c.swap(a);
		std << std::map<int, std::string>::const_iterator(a.find(2))->second << std::endl;
		std << std::map<int, std::string>::iterator(a.find(2))->second << std::endl;
		std << std::map<int, std::string>::const_iterator (b.find(2))->second << std::endl;
		std << std::map<int, std::string>::iterator(b.find(2))->second << std::endl;
		time_end(start, "std[find]");
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
		ft::map<int, std::string > a;
		a[1] = "one";
		a[2] = "two";
		a[3] = "three";
		a[4] = "four";

		ft::map<int, std::string>::allocator_type alloc = a.get_allocator();
		mine << alloc.max_size() << std::endl;
		time_end(start, "mine[alloc]");
	}
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
		time_end(start, "mine[operator]");
	}
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
		time_end(start, "std[operator]");
	}
	std::cout << std::endl;

}

void vector(std::ofstream &mine, std::ofstream &std) {

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
	{
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
		try{

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

		} catch (const std::exception& e) {
			mine << e.what() << std::endl;
		}
	}
	{
		try{
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

		} catch (const std::exception& e) {
			std << e.what() << std::endl;
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
		for (int i = 0; i < 1000; ++i) {
			mine << b[i] << std::endl;
		}
		time_end(start, "mine[]");
	}
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
		for (int i = 0; i < 1000; ++i) {
			std << b[i] << std::endl;
		}
		time_end(start, "std[]");
	}
	std::cout << std::endl;
	{
		clock_t start = time_begin();
		ft::vector<int> a(100, 50);
		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			mine << *it << std::endl;
		}
		for (ft::vector<int>::const_iterator  it = a.begin(); it != a.end(); ++it) {
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
	{
		clock_t start = time_begin();
		std::vector<int> a(100, 50);
		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			std << *it << std::endl;
		}
		for (std::vector<int>::const_iterator  it = a.begin(); it != a.end(); ++it) {
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


	}

}



