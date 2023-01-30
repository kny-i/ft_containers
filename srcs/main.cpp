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
void vector(std::ofstream &fs1, std::ofstream &fs2);
void map(std::ofstream &fs1, std::ofstream &fs2);
void stack(std::ofstream &fs1, std::ofstream &fs2);
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
	double duration = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken by " << msg <<": " << duration << " seconds" << std::endl;
	std::cout << std::flush;
}

clock_t time_begin() {
	clock_t start = clock();
	return start;
}

void stack(std::ofstream &fs1, std::ofstream &fs2) {


}
void map(std::ofstream &fs1, std::ofstream &fs2) {

	{
		std::cout << "[test Constructors]" << std::endl;
		ft::map<int, int > a;

	}

}
void vector(std::ofstream &fs1, std::ofstream &fs2) {

//	ft::vector<int> a;
//	ft::vector<int> b(3, 100);//3 elements with 100
//	ft::vector<int> c(b.begin(), b.end());
//	ft::vector<int> d(c);
//	int ints[] = {10, 1, 9, 2};
//	ft::vector<int> ve_ints(ints, ints + sizeof(ints) / sizeof (int));
//
//	for (ft::vector<int>::iterator it = d.begin(); it != d.end(); it++) {
//		fs1 << *it << ' ';
//	}
	clock_t start  = time_begin();
	time_end(start, "hoge");

}



