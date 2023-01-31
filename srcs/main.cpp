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
	std::cout << std::endl;

	if (test_case == "vector") {
		if (system("diff output/vec_mine output/vec_std") == 0)
			std::cout << "\033[32mvector[OK] \033[m\n";
		else
			std::cout << "\033[31mvector[KO] \033[m\n";
		std::cout << "=======================================" << std::endl;
		std::cout << std::flush;

	}else if (test_case == "map") {
		if (system("diff output/map_mine output/map_std") == 0)
			std::cout << "\033[32mmap[OK] \033[m\n";
		else
			std::cout << "\033[31mmap[KO] \033[m\n";
		std::cout << "=======================================" << std::endl;
		std::cout << std::flush;

	} else if (test_case == "stack") {
		if (system("diff output/stack_mine output/stack_std") == 0)
			std::cout << "\033[32mstack[OK] \033[m\n";
		else
			std::cout << "\033[31mstack[KO] \033[m\n";
		std::cout << "=======================================" << std::endl;
		std::cout << std::flush;
	}

}

void time_end(clock_t start, std::string const &msg) {
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << msg <<": " << duration << " k second" << std::endl;
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

}

void vector(std::ofstream &mine, std::ofstream &std) {

//	ft::vector<int> a;
//	ft::vector<int> b(3, 100);//3 elements with 100
//	ft::vector<int> c(b.begin(), b.end());
//	ft::vector<int> d(c);
//	int ints[] = {10, 1, 9, 2};
//	ft::vector<int> ve_ints(ints, ints + sizeof(ints) / sizeof (int));
//
//	for (ft::vector<int>::iterator it = d.begin(); it != d.end(); it++) {
//		mine << *it << ' ';
//	}
	//clock_t start  = time_begin();
	//time_end(start, "test");

}



