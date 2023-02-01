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

#include <thread>
#include <fstream>
#include <vector>
#include "vector.hpp"
#include <map>
#include "map.hpp"
/* colors */
const char *const StopColor = "\033[0m";
const char *const BoldColor = "\033[1m";
const char *const BlackColor = "\033[30m";
const char *const RedColor = "\033[31m";
const char *const GreenColor = "\033[32m";
const char *const YellowColor = "\033[33m";
const char *const BlueColor = "\033[34m";
const char *const MagentaColor = "\033[35m";
const char *const CyanColor = "\033[36m";
const char *const WhiteColor = "\033[37m";
const char *const UnderlineColor =" \033[4m";

void print_vec_int(ft::vector<int> const &vec, std::ofstream &ft_ofs) {
	if (vec.empty()) {
		ft_ofs << "Empty!" << std::endl;
	} else {
		for (size_t i = 0; i < vec.size(); i++) {
			ft_ofs << "[" << vec[i] << "]";
		}
		ft_ofs << std::endl;
	}
}

void print_vec_int(std::vector<int> const &vec, std::ofstream &std_ofs) {
	if (vec.empty()) {
		std_ofs << "Empty!" << std::endl;
	} else {
		for (size_t i = 0; i < vec.size(); i++) {
			std_ofs << "[" << vec[i] << "]";
		}
		std_ofs << std::endl;
	}
}

void print_vec_string(ft::vector<std::string> const &vec, std::ofstream &ft_ofs) {
	if (vec.empty()) {
		ft_ofs << "Empty!" << std::endl;
	} else {
		for (size_t i = 0; i < vec.size(); i++) {
			ft_ofs << "[" << vec[i] << "]";
		}
		ft_ofs << std::endl;
	}
}

void print_vec_string(std::vector<std::string> const &vec, std::ofstream &std_ofs) {
	if (vec.empty()) {
		std_ofs << "Empty!" << std::endl;
	} else {
		for (size_t i = 0; i < vec.size(); i++) {
			std_ofs << "[" << vec[i] << "]";
		}
		std_ofs << std::endl;
	}
}

clock_t start_stop_watch() {
	return clock();
}

void calculate_time(clock_t start, std::string const &func_name) {
	clock_t end = clock();
	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << BlueColor << func_name << " => " << UnderlineColor << duration << " milliseconds" << StopColor << std::endl;
}

void print_result(std::string const &stl_name) {
	const int SUCCESS = 0;
	int exit_status;
	std::cout << GreenColor;
	if (stl_name == "vector") {
		exit_status = system("diff test/actual_vector test/expected_vector");
		if (exit_status == SUCCESS) {
			std::cout << "   ===> vector tester ok!!!!\n";
		} else {
			std::cout << RedColor << "   ===> vector tester ng!!!!\n";
		}
	}
	if (stl_name == "stack") {
		exit_status = system("diff ./test/actual_stack ./test/expected_stack");
		if (exit_status == SUCCESS) {
			std::cout << "   ===> stack  tester ok!!!!\n";
		} else {
			std::cout << RedColor << "   ===> stack  tester ng!!!!\n";
		}
	}
	if (stl_name == "map") {
		exit_status = system("diff ./test/actual_map ./test/expected_map");
		if (exit_status == SUCCESS) {
			std::cout << "   ===> map   tester ok!!!!\n";
		} else {
			std::cout << RedColor << "   ===> map   tester ng!!!!\n";
		}
	}
	std::cout << StopColor;
}

void vector_sample(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft::vector<int> v(3, 100);
		for (ft::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			ft_ofs << *it << ' ';
		}
		calculate_time(start, "vector sample mine");
	}
	{
		clock_t start = start_stop_watch();
		std::vector<int> v(3, 100);
		for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
			std_ofs << *it << ' ';
		}
		calculate_time(start, "vector sample real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_constructor(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "constructor test" << "]" << StopColor << std::endl;
		ft::vector<int> iv1;
		print_vec_int(iv1, ft_ofs);
		ft::vector<std::string> sv3(10, "hello");
		print_vec_string(sv3, ft_ofs);
		ft::vector<int> iv3(5, -1);
		print_vec_int(iv3, ft_ofs);
		iv1 = iv3;
		print_vec_int(iv1, ft_ofs);
		//this test contains destructor and assignation operator overloadcalculate_time(start, "vector_sample mine");
		calculate_time(start, "vector constructor mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "constructor test" << "]" << StopColor << std::endl;
		std::vector<int> iv1;
		print_vec_int(iv1, std_ofs);
		std::vector<std::string> sv3(10, "hello");
		print_vec_string(sv3, std_ofs);
		std::vector<int> iv3(5, -1);
		print_vec_int(iv3, std_ofs);
		iv1 = iv3;
		print_vec_int(iv1, std_ofs);
		//this test contains destructor and assignation operator overload
		calculate_time(start, "vector constructor real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_independence_memeber(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "independence member test" << "]" << StopColor << std::endl;
		ft::vector<int> v;
		v.assign(5,0);
		print_vec_int(v, ft_ofs);
		calculate_time(start, "vector independence member mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "independence member test" << "]" << StopColor << std::endl;
		std::vector<int> v;
		v.assign(5,0);
		print_vec_int(v, std_ofs);
		calculate_time(start, "vector independence member real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_iterator(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "iterator test" << "]" << StopColor << std::endl;
		ft::vector<int> v(10000);
		for (int i = 0; i < v.size(); i++) {
			v[i] = i;
		}
		print_vec_int(v, ft_ofs);
		ft::vector<int>::iterator it = v.begin();
		ft::vector<int>::iterator end = v.end();
		for (int index = 0; it != end; it++, index++) {
			ft_ofs << "[" << index << "] " << *it << " ";
		}
		ft_ofs << std::endl;
		ft::vector<int>::reverse_iterator rit = v.rbegin();
		ft::vector<int>::reverse_iterator rend = v.rend();
		for (int index = 0; rit != rend; rit++, index++) {
			ft_ofs << "[" << index << "] " << *rit << " ";
		}
		ft_ofs << std::endl;
		calculate_time(start, "vector iterator mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "iterator test" << "]" << StopColor << std::endl;
		std::vector<int> v(10000);
		for (int i = 0; i < v.size(); i++) {
			v[i] = i;
		}
		print_vec_int(v, std_ofs);
		std::vector<int>::iterator it = v.begin();
		std::vector<int>::iterator end = v.end();
		for (int index = 0; it != end; it++, index++) {
			std_ofs << "[" << index << "] " << *it << " ";
		}
		std_ofs << std::endl;
		std::vector<int>::reverse_iterator rit = v.rbegin();
		std::vector<int>::reverse_iterator rend = v.rend();
		for (int index = 0; rit != rend; rit++, index++) {
			std_ofs << "[" << index << "] " << *rit << " ";
		}
		std_ofs << std::endl;
		calculate_time(start, "vector iterator real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_capacity(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "capacity test" << "]" << StopColor << std::endl;
		ft::vector<int> v;
		if (v.empty()) {
			ft_ofs << "v is Empty" << std::endl;
		} else {
			ft_ofs << "v is not Empty" << std::endl;
		}
		ft::vector<int> v2(3, 7);
		v = v2;
		ft_ofs << "v.max_size() == " << v.max_size() << std::endl;
		print_vec_int(v, ft_ofs);
		ft_ofs << "v.size() == " << v.size() << std::endl;
		ft_ofs << "v.capacity() == " << v.capacity() << std::endl;
		v.reserve(200);
		//reserveのどこかでバグってる
		ft_ofs << "<< after reserve(200) >>" << std::endl;
		ft_ofs << "v.size() == "<< v.size() << std::endl;
		ft_ofs << "v.capacity() == "<< v.capacity() << std::endl;
		calculate_time(start, "vector capacity mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "capacity test" << "]" << StopColor << std::endl;
		std::vector<int> v;
		if (v.empty()) {
			std_ofs << "v is Empty" << std::endl;
		} else {
			std_ofs << "v is not Empty" << std::endl;
		}
		std::vector<int> v2(3, 7);
		v = v2;
		std_ofs << "v.max_size() == " << v.max_size() << std::endl;
		print_vec_int(v, std_ofs);
		std_ofs << "v.size() == " << v.size() << std::endl;
		std_ofs << "v.capacity() == " << v.capacity() << std::endl;
		v.reserve(200);
		//reserveのどこかでバグってる
		std_ofs << "<< after reserve(200) >>" << std::endl;
		std_ofs << "v.size() == "<< v.size() << std::endl;
		std_ofs << "v.capacity() == "<< v.capacity() << std::endl;
		calculate_time(start, "vector capacity real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_modifiers(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "modifiers test" << "]" << StopColor << std::endl;
		ft::vector<std::string> v(50, "a");
		print_vec_string(v, ft_ofs);
		v.clear();
		ft_ofs << "v.size() == " << v.size() << std::endl;
		ft_ofs << "v.capacity() == " << v.capacity() << std::endl;
		ft::vector<std::string> v2(50, "a");
		v = v2;
		//erase()
		v.erase(v.begin(), v.begin() + 49);
		print_vec_string(v, ft_ofs);
		ft_ofs << "v.size() == " << v.size() << std::endl;

		//insert()
		ft::vector<int> v3;
		v3.insert(v3.begin(), 3);
		v3.insert(v3.begin(), 4);
		v3.insert(v3.begin(), 5);
		v3.insert(v3.end(), 5);
		print_vec_int(v3, ft_ofs);
		ft::vector<int> v4(5, 42);
		v4.insert(v4.begin(), 3, 423);
		print_vec_int(v4, ft_ofs);
		ft::vector<int>::iterator v4it = v4.begin();
		v4.erase(v4it);
		v4it += 3;
		v4.erase(v4it);
		print_vec_int(v4, ft_ofs);
		v4.erase(v4.begin(), v4.end());
		print_vec_int(v4, ft_ofs);

		//push_back() and pop_back()
		ft::vector<int> v5;
		v5.push_back(1);
		v5.push_back(2);
		print_vec_int(v5, ft_ofs);
		v5.pop_back();
		print_vec_int(v5, ft_ofs);

		//swap()
		ft::vector<int> v6(3, 42);
		ft::vector<int> v7(3, 24);
		ft_ofs << "<<before swap()>> \nv6 -> ";
		print_vec_int(v6, ft_ofs);
		ft_ofs << "v7 -> ";
		print_vec_int(v7, ft_ofs);
		v6.swap(v7);
		ft_ofs << "<<after swap()>> \nv6 -> ";
		print_vec_int(v6, ft_ofs);
		ft_ofs << "v7 -> ";
		print_vec_int(v7, ft_ofs);
		calculate_time(start, "vector modifiers mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "modifiers test" << "]" << StopColor << std::endl;
		std::vector<std::string> v(50, "a");
		print_vec_string(v, std_ofs);
		v.clear();
		std_ofs << "v.size() == " << v.size() << std::endl;
		std_ofs << "v.capacity() == " << v.capacity() << std::endl;
		std::vector<std::string> v2(50, "a");
		v = v2;
		//erase()
		v.erase(v.begin(), v.begin() + 49);
		print_vec_string(v, std_ofs);
		std_ofs << "v.size() == " << v.size() << std::endl;

		//insert()
		std::vector<int> v3;
		v3.insert(v3.begin(), 3);
		v3.insert(v3.begin(), 4);
		v3.insert(v3.begin(), 5);
		v3.insert(v3.end(), 5);
		print_vec_int(v3, std_ofs);
		std::vector<int> v4(5, 42);
		v4.insert(v4.begin(), 3, 423);
		print_vec_int(v4, std_ofs);
		std::vector<int>::iterator v4it = v4.begin();
		v4.erase(v4it);
		v4it += 3;
		v4.erase(v4it);
		print_vec_int(v4, std_ofs);
		v4.erase(v4.begin(), v4.end());
		print_vec_int(v4, std_ofs);

		//push_back() and pop_back()
		std::vector<int> v5;
		v5.push_back(1);
		v5.push_back(2);
		print_vec_int(v5, std_ofs);
		v5.pop_back();
		print_vec_int(v5, std_ofs);

		//swap()
		std::vector<int> v6(3, 42);
		std::vector<int> v7(3, 24);
		std_ofs << "<<before swap()>> \nv6 -> ";
		print_vec_int(v6, std_ofs);
		std_ofs << "v7 -> ";
		print_vec_int(v7, std_ofs);
		v6.swap(v7);
		std_ofs << "<<after swap()>> \nv6 -> ";
		print_vec_int(v6, std_ofs);
		std_ofs << "v7 -> ";
		print_vec_int(v7, std_ofs);
		calculate_time(start, "vector modifiers real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}


void vector_random_access(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "random access test" << "]" << StopColor << std::endl;
		ft::vector<int> v;
		for (int i = 0; i < 100; i++) {
			v.push_back(i);
		}
		ft::vector<int>::iterator it = v.begin();
		ft_ofs << *(++it) << std::endl;//1
		ft_ofs << *(--it) << std::endl;//0
		ft_ofs << *(it++) << std::endl;//0
		calculate_time(start, "vector random access mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "random access test" << "]" << StopColor << std::endl;
		std::vector<int> v;
		for (int i = 0; i < 100; i++) {
			v.push_back(i);
		}
		std::vector<int>::iterator it = v.begin();
		std_ofs << *(++it) << std::endl;//1
		std_ofs << *(--it) << std::endl;//0
		std_ofs << *(it++) << std::endl;//0
		calculate_time(start, "vector random access real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void vector_non_member_functions(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "non member mine test" << "]" << StopColor << std::endl;
		ft::vector<int> v1(4, 30);
		ft::vector<int> v2(4, 30);
		if (v1 == v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v1 != v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v1 < v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v1 > v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v1 <= v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v1 >= v2) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		v1.swap(v2);
		print_vec_int(v1, ft_ofs);

		/* different vector */
		ft::vector<int> v3(9, 81);
		ft::vector<int> v4(18, 23);
		if (v3 == v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v3 != v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v3 < v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v3 > v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v3 <= v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		if (v3 >= v4) {
			ft_ofs << "OK" << ' ';
		} else {
			ft_ofs << "KO" << ' ';
		}
		v3.swap(v4);
		print_vec_int(v3, ft_ofs);
		calculate_time(start, "vector non member mine");
	}
	/* STOP! */
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "non member mine test" << "]" << StopColor << std::endl;
		std::vector<int> v1(4, 30);
		std::vector<int> v2(4, 30);
		if (v1 == v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v1 != v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v1 < v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v1 > v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v1 <= v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v1 >= v2) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		v1.swap(v2);
		print_vec_int(v1, std_ofs);

		/* different vector */
		std::vector<int> v3(9, 81);
		std::vector<int> v4(18, 23);
		if (v3 == v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v3 != v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v3 < v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v3 > v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v3 <= v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		if (v3 >= v4) {
			std_ofs << "OK" << ' ';
		} else {
			std_ofs << "KO" << ' ';
		}
		v3.swap(v4);
		print_vec_int(v3, std_ofs);
		calculate_time(start, "vector non member real");
	}
	if (system("diff test/actual_vector test/expected_vector") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

/* [VECTOR] [VECTOR] [VECTOR] [VECTOR]　[VECTOR] [VECTOR]　*/
void tester_in_vector_test(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	try {
		vector_constructor(ft_ofs, std_ofs);
		vector_independence_memeber(ft_ofs, std_ofs);
		vector_iterator(ft_ofs, std_ofs);
		vector_capacity(ft_ofs, std_ofs);
		vector_modifiers(ft_ofs, std_ofs);
		vector_random_access(ft_ofs, std_ofs);
		vector_non_member_functions(ft_ofs, std_ofs);
	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

/* [STACK] [STACK] [STACK] [STACK] [STACK] [STACK] [STACK] */
void tester_in_stack_test(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	try {

	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

/* [MAP] [MAP] [MAP] [MAP] [MAP] [MAP] [MAP] [MAP] [MAP] */
void map_sample(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		for (ft::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++) {
			ft_ofs << rit->second << ' ';
		}
		ft_ofs << '\n';
		mp.clear();
		for (ft::map<int, std::string>::iterator newit = mp.begin(); newit != mp.end(); newit++) {
			ft_ofs << newit->second << std::endl;
		}
		calculate_time(start, "map sample mine");
	}
	{
		clock_t start = start_stop_watch();
		std::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		for (std::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++) {
			std_ofs << rit->second << ' ';
		}
		std_ofs << '\n';
		mp.clear();
		for (std::map<int, std::string>::iterator newit = mp.begin(); newit != mp.end(); newit++) {
			std_ofs << newit->second << std::endl;
		}
		calculate_time(start, "map sample real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_constructor(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "map constructor test" << "]" << StopColor << std::endl;
		ft::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";

		ft::map<int, std::string> mp2(mp.begin(), mp.end());
		for (ft::map<int, std::string>::iterator it = mp2.begin(); it != mp2.end(); it++) {
			ft_ofs << it->second << std::endl;
		}
		ft::map<int, std::string> mp3 = mp;
		for (ft::map<int, std::string>::iterator it = mp3.begin(); it != mp3.end(); it++) {
			ft_ofs << it->second << std::endl;
		}
		ft::map<int, std::string> mp4;
		mp4 = mp;
		for (ft::map<int, std::string>::iterator it = mp4.begin(); it != mp4.end(); it++) {
			ft_ofs << it->second << std::endl;
		}
		calculate_time(start, "map constructor mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "map constructor test" << "]" << StopColor << std::endl;
		std::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";

		std::map<int, std::string> mp2(mp.begin(), mp.end());
		for (std::map<int, std::string>::iterator it = mp2.begin(); it != mp2.end(); it++) {
			std_ofs << it->second << std::endl;
		}
		std::map<int, std::string> mp3 = mp;
		for (std::map<int, std::string>::iterator it = mp3.begin(); it != mp3.end(); it++) {
			std_ofs << it->second << std::endl;
		}
		std::map<int, std::string> mp4;
		mp4 = mp;
		for (std::map<int, std::string>::iterator it = mp4.begin(); it != mp4.end(); it++) {
			std_ofs << it->second << std::endl;
		}
		calculate_time(start, "map constructor real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_element_access(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "element_access test" << "]" << StopColor << std::endl;
		ft::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		ft_ofs << "mp[4] : " << mp[4] << std::endl;
		ft_ofs << "mp[5] : " << mp[5] << std::endl;
		ft_ofs << "mp[-1] : " << mp[-1] << std::endl;
		ft::map<int, int> mp2;
		ft_ofs << "mp[100] => " << mp2[100] << std::endl;
		calculate_time(start, "map element access mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "element_access test" << "]" << StopColor << std::endl;
		std::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		std_ofs << "mp[4] : " << mp[4] << std::endl;
		std_ofs << "mp[5] : " << mp[5] << std::endl;
		std_ofs << "mp[-1] : " << mp[-1] << std::endl;
		ft::map<int, int> mp2;
		std_ofs << "mp[100] => " << mp2[100] << std::endl;
		calculate_time(start, "map element access real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_iterator(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "iterator test" << "]" << StopColor << std::endl;
		ft::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->second << std::endl;
		}
		for (ft::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it) {
			ft_ofs << it->second << std::endl;
		}
		for (ft::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++) {
			ft_ofs << rit->second << std::endl;
		}
		for (ft::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit) {
			ft_ofs << rit->second << std::endl;
		}
		calculate_time(start, "map iterator mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "iterator test" << "]" << StopColor << std::endl;
		std::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->second << std::endl;
		}
		for (std::map<int, std::string>::iterator it = mp.begin(); it != mp.end(); ++it) {
			std_ofs << it->second << std::endl;
		}
		for (std::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); rit++) {
			std_ofs << rit->second << std::endl;
		}
		for (std::map<int, std::string>::reverse_iterator rit = mp.rbegin(); rit != mp.rend(); ++rit) {
			std_ofs << rit->second << std::endl;
		}
		calculate_time(start, "map iterator real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_capacity(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft_ofs << GreenColor << "[" << "capacity test" << "]" << StopColor << std::endl;
		ft::map<int, std::string> mp;
		if (mp.empty()) {
			ft_ofs << "OK\n";
		} else {
			ft_ofs << "KO\n";
		}
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		if (mp.empty()) {
			ft_ofs << "OK\n";
		} else {
			ft_ofs << "KO\n";
		}
		ft_ofs << mp.size();
		ft_ofs << mp.max_size();
		calculate_time(start, "map capacity mine");
	}
	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "capacity test" << "]" << StopColor << std::endl;
		std::map<int, std::string> mp;
		if (mp.empty()) {
			std_ofs << "OK\n";
		} else {
			std_ofs << "KO\n";
		}
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		if (mp.empty()) {
			std_ofs << "OK\n";
		} else {
			std_ofs << "KO\n";
		}
		std_ofs << mp.size();
		std_ofs << mp.max_size();
		calculate_time(start, "map capacity real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_modifiers(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
//		ft_ofs << '\n';//why？
		ft_ofs << GreenColor << "[" << "modifiers test" << "]" << StopColor << std::endl;
		ft::map<long, long> mp;
		mp.insert(ft::make_pair(1, 2));
		for (ft::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(0);
		for (ft::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(1);
		for (ft::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(2);
		for (ft::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->first << ' ' << it->second << ' ';
		}

		ft::map<long, long> mp2;
		for (long i = 0; i < 100; i++) {
			mp2[i] = i * i;
		}
		mp.swap(mp2);
		for (ft::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			ft_ofs << it->first << ' ' << it->second << ' ';
		}
		calculate_time(start, "map modifiers mine");
	}

	{
		clock_t start = start_stop_watch();
		std_ofs << GreenColor << "[" << "modifiers test" << "]" << StopColor << std::endl;
		std::map<long, long> mp;
		mp.insert(std::make_pair(1, 2));
		for (std::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(0);
		for (std::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(1);
		for (std::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->first << ' ' << it->second << ' ';
		}
		mp.erase(2);
		for (std::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->first << ' ' << it->second << ' ';
		}

		std::map<long, long> mp2;
		for (long i = 0; i < 100; i++) {
			mp2[i] = i * i;
		}
		mp.swap(mp2);
		for (std::map<long, long>::iterator it = mp.begin(); it != mp.end(); it++) {
			std_ofs << it->first << ' ' << it->second << ' ';
		}
		calculate_time(start, "map modifiers real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_lookup(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft::map<int, std::string> mp;
		for (int i = 0; i <= 100; i++) {
			ft_ofs << mp.count(1) << std::endl;
		}
		mp.insert(ft::make_pair(1, "one"));
		mp.insert(ft::make_pair(2, "two"));
		mp[3] = "three";
		mp[4] = "four";
		mp[INT_MAX] = "INT_MAX";
		for (int i = 0; i <= 100; i++) {
			ft_ofs << mp.count(1) << std::endl;
		}
		ft::map<int, std::string>::iterator it = mp.find(INT_MAX);
		ft_ofs << it->second << std::endl;
		calculate_time(start, "map lookup mine");
	}
	{
		clock_t start = start_stop_watch();
		std::map<int, std::string> mp;
		for (int i = 0; i <= 100; i++) {
			std_ofs << mp.count(1) << std::endl;
		}
		mp.insert(std::make_pair(1, "one"));
		mp.insert(std::make_pair(2, "two"));
		mp[3] = "three";
		mp[4] = "four";
		mp[INT_MAX] = "INT_MAX";
		for (int i = 0; i <= 100; i++) {
			std_ofs << mp.count(1) << std::endl;
		}
		std::map<int, std::string>::iterator it = mp.find(INT_MAX);
		std_ofs << it->second << std::endl;
		calculate_time(start, "map lookup real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void map_related_to_range(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	{
		clock_t start = start_stop_watch();
		ft::map<int, std::string> mp;
		mp[1] = "one";
		mp[2] = "two";
		mp[3] = "three";
		mp[4] = "four";
		mp[5] = "five";
		mp[6] = "six";
		mp[7] = "seven";
		mp[8] = "eight";
		mp[9] = "nine";
		mp[10] = "ten";
		for (int i = 1; i <= 10; i++) {
			ft_ofs << mp.upper_bound(i)->second << '\n';
		}
		ft_ofs << "\n";
		calculate_time(start, "map related to range mine");
	}
	{
		/* TEST誤作動中 why? */
		clock_t start = start_stop_watch();
		std_ofs << "\n";
		calculate_time(start, "map related to range real");
	}
	if (system("diff test/actual_map test/expected_map") == 0) {
		std::cout << GreenColor << "-> [OK]\n" << StopColor;
	} else {
		std::cout << RedColor << "[ERROR] column : " << __LINE__ << std::endl;
	}
}

void tester_in_map_test(std::ofstream &ft_ofs, std::ofstream &std_ofs) {
	try {
		map_sample(ft_ofs, std_ofs);
		map_constructor(ft_ofs, std_ofs);
		map_element_access(ft_ofs, std_ofs);
		map_iterator(ft_ofs, std_ofs);
		map_capacity(ft_ofs, std_ofs);
		map_modifiers(ft_ofs, std_ofs);
		map_lookup(ft_ofs, std_ofs);
//		map_related_to_range(ft_ofs, std_ofs);
	} catch (std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}

void vector_test() {
	std::cout << GreenColor << "\n          [vector tester]" << StopColor << std::endl;
	std::ofstream ft_ofs;
	std::ofstream std_ofs;

	system("mkdir test 2> /dev/null");

	ft_ofs.open("./test/actual_vector");
	std_ofs.open("./test/expected_vector");

	tester_in_vector_test(ft_ofs, std_ofs);

	ft_ofs << std::flush;
	std_ofs << std::flush;

	print_result("vector");
}

void stack_test() {
	std::cout << GreenColor << "\n          [stack tester]" << StopColor << std::endl;
	std::ofstream ft_ofs;
	std::ofstream std_ofs;

	system("mkdir test 2> /dev/null");

	ft_ofs.open("test/actual_stack");
	std_ofs.open("test/expected_stack");

	tester_in_stack_test(ft_ofs, std_ofs);

	print_result("stack");
}

void map_test() {
	std::cout << GreenColor << "\n          [map tester]" << StopColor << std::endl;
	std::ofstream ft_ofs;
	std::ofstream std_ofs;

	system("mkdir test 2> /dev/null");

	ft_ofs.open("test/actual_map");
	std_ofs.open("test/expected_map");

	tester_in_map_test(ft_ofs, std_ofs);

	print_result("map");
}

int main() {
	vector_test();
	stack_test();
	map_test();
}

//
//void judge(std::string const &test_case);
//clock_t time_begin();
//void time_end(clock_t start, std::string const &msg);
//void vector(std::ofstream &mine, std::ofstream &std);
//void map(std::ofstream &mine, std::ofstream &std);
//void stack(std::ofstream &mine, std::ofstream &std);
//int	main()
//{
//	system("mkdir output");
//	std::cout << "=======================================" << std::endl;
//	//vector test
//	{
//		/* === VECTOR === */
//		std::ofstream vec_mine;
//		std::ofstream vec_std;
//		vec_mine.open("output/vec_mine");
//		vec_std.open("output/vec_std");
//		vector(vec_mine, vec_std);
//		vec_mine << std::flush;
//		vec_std << std::flush;
//		judge("vector");
//	}
//
//	//map test
//	{
//		std::ofstream map_mine;
//		std::ofstream map_std;
//		map_mine.open("output/map_mine");
//		map_std.open("output/map_std");
//		map(map_mine, map_std);
//		map_mine << std::flush;
//		map_std << std::flush;
//		judge("map");
//	}
//	//stack test
//	{
//		std::ofstream stack_mine;
//		std::ofstream stack_std;
//		stack_mine.open("output/stack_mine");
//		stack_std.open("output/stack_std");
//		stack(stack_mine, stack_std);
//		stack_mine << std::flush;
//		stack_std << std::flush;
//		judge("stack");
//	}
//}
//
//void judge(std::string const &test_case) {
//
//	if (test_case == "vector") {
//		if (system("diff output/vec_mine output/vec_std") == 0)
//			std::cout << "\033[32mvector[OK] \033[m\n";
//		else
//			std::cout << "\033[31mvector[KO] \033[m\n";
//		std::cout << "============[VECTOR DONE !!]============" << std::endl;
//		std::cout << std::flush;
//
//	}else if (test_case == "map") {
//		if (system("diff output/map_mine output/map_std") == 0)
//			std::cout << "\033[32mmap[OK] \033[m\n";
//		else
//			std::cout << "\033[31mmap[KO] \033[m\n";
//		std::cout << "=============[MAP DONE !!]=============" << std::endl;
//		std::cout << std::flush;
//
//	} else if (test_case == "stack") {
//		if (system("diff output/stack_mine output/stack_std") == 0)
//			std::cout << "\033[32mstack[OK] \033[m\n";
//		else
//			std::cout << "\033[31mstack[KO] \033[m\n";
//		std::cout << "============[STACK DONE !!]============" << std::endl;
//		std::cout << std::flush;
//	}
//
//}
//
//void time_end(clock_t start, std::string const &msg) {
//	clock_t end = clock();
//	double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
//	std::cout << msg <<": " << duration << "m seconds" << std::endl;
//	std::cout << std::flush;
//}
//
//clock_t time_begin() {
//	clock_t start = clock();
//	return start;
//}
//
//void stack(std::ofstream &mine, std::ofstream &std) {
//
//
//}
//
//void map(std::ofstream &mine, std::ofstream &std) {
//
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				mine << it->second << ' ' << std::endl;
//			}
//			time_end(start, "mine[constructor]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//
//			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				std << it->second << ' ' << std::endl;
//			}
//			time_end(start, "std[constructor]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			for (ft::map<int, std::string>::reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
//				mine << it->second << ' ' << std::endl;
//			}
//			time_end(start, "mine[reverse_iterator]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//
//			for (std::map<int, std::string>::reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
//		std << it->second << ' ' << std::endl;
//			}
//			time_end(start, "std[reverse_iterator]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			for (ft::map<int, std::string>::const_reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
//				mine << it->second << ' ' << std::endl;
//			}
//			time_end(start, "mine[const_reverse_iterator]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//
//			for (std::map<int, std::string>::const_reverse_iterator it = c.rbegin(); it != c.rend(); ++it) {
//				std << it->second << ' ' << std::endl;
//			}
//			time_end(start, "std[const_reverse_iterator]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			for (ft::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
//				mine << it->second << ' ' << std::endl;
//				it->second = "test";
//			}
//			for (ft::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
//				mine << it->second << ' ' << std::endl;
//			}
//
//			time_end(start, "mine[iterator]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//
//			for (std::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
//				std << it->second << ' ' << std::endl;
//				it->second = "test";
//			}
//			for (std::map<int, std::string>::iterator it = c.begin(); it != c.end(); ++it) {
//				std << it->second << ' ' << std::endl;
//			}
//			time_end(start, "std[iterator]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//			mine << a.empty() << std::endl;
//			mine << b.empty() << std::endl;
//			mine << c.empty() << std::endl;
//			time_end(start, "mine[empty]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//			std << a.empty() << std::endl;
//			std << b.empty() << std::endl;
//			std << c.empty() << std::endl;
//			time_end(start, "std[empty]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//			mine << a.size() << std::endl;
//			mine << b.size() << std::endl;
//			mine << c.size() << std::endl;
//			time_end(start, "mine[size]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//			std << a.size() << std::endl;
//			std << b.size() << std::endl;
//			std << c.size() << std::endl;
//			time_end(start, "std[size]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//			mine << a.max_size() << std::endl;
//			mine << b.max_size() << std::endl;
//			mine << c.max_size() << std::endl;
//			time_end(start, "mine[max_size]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//			std << a.max_size() << std::endl;
//			std << b.max_size() << std::endl;
//			std << c.max_size() << std::endl;
//			time_end(start, "std[max_size]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			ft::pair<int, std::string> pair(1, "PIYO");
//			b.insert(ft::make_pair(1, "TEST"));
//			c.insert(c.begin(), c.end());
//			a.insert(a.begin(), pair);
//			for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//				mine << it->second << ' ';
//			}
//			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				mine << it->second << ' ';
//			}
//			for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//				mine << it->second << ' ';
//			}
//
//			time_end(start, "mine[insert]");
//		}
//
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//			std::pair<int, std::string> pair(1, "PIYO");
//			b.insert(std::make_pair(1, "TEST"));
//			c.insert(c.begin(), c.end());
//			a.insert(a.begin(), pair);
//			for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//				std << it->second << ' ';
//			}
//			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				std << it->second << ' ';
//			}
//			for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//				std << it->second << ' ';
//			}
//
//			time_end(start, "std[insert]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		{
//			clock_t start = time_begin();
//			ft::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			ft::map<int, std::string> b(a.begin(), a.end());
//			ft::map<int, std::string> c(b);
//
//			ft::pair<int, std::string> pair(1, "PIYO");
//			b.insert(ft::make_pair(1, "TEST"));
//			b.erase(b.begin());
//			//erase にend()が入ってきたらsegv
//			c.insert(c.begin(), c.end());
//			c.erase(c.begin(), --c.end() );
//			a.erase(1);
//			a.erase(3);
//			for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//				mine << it->second << ' ';
//			}
//			for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				mine << it->second << ' ';
//			}
//			for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//				mine << it->second << ' ';
//			}
//
//			time_end(start, "mine[erase]");
//		}
//		{
//			clock_t start = time_begin();
//			std::map<int, std::string > a;
//			a[1] = "one";
//			a[2] = "two";
//			a[3] = "three";
//			a[4] = "four";
//
//			std::map<int, std::string> b(a.begin(), a.end());
//			std::map<int, std::string> c(b);
//
//			std::pair<int, std::string> pair(1, "PIYO");
//			b.insert(std::make_pair(1, "TEST"));
//			b.erase(b.begin());
//			//erase にend()が入ってきたらsegv
//			c.insert(c.begin(), c.end());
//			c.erase(c.begin(), --c.end() );
//			a.erase(1);
//			a.erase(3);
//			for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//				std << it->second << ' ';
//			}
//			for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				std << it->second << ' ';
//			}
//			for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//				std << it->second << ' ';
//			}
//
//			time_end(start, "std[erase]");
//		}
//		std::cout  << std::endl;
//	}
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string> b(a.begin(), a.end());
//		ft::map<int, std::string> c(b);
//
//		ft::pair<int, std::string> pair(1, "PIYO");
//		b.insert(ft::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		//erase にend()が入ってきたらsegv
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			mine << it->second << ' ';
//		}
//		for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//			mine << it->second << ' ';
//		}
//		for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << it->second << ' ';
//		}
//
//		time_end(start, "mine[swap]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string> b(a.begin(), a.end());
//		std::map<int, std::string> c(b);
//
//		std::pair<int, std::string> pair(1, "PIYO");
//		b.insert(std::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		//erase にend()が入ってきたらsegv
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			std << it->second << ' ';
//		}
//		for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//			std << it->second << ' ';
//		}
//		for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << it->second << ' ';
//		}
//
//		time_end(start, "mine[swap]");
//	}
//	std::cout  << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string> b(a.begin(), a.end());
//		ft::map<int, std::string> c(b);
//
//		ft::pair<int, std::string> pair(1, "PIYO");
//		b.insert(ft::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		a.clear();
//		b.clear();
//		c.clear();
//
//		for (ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			mine << it->second << ' ';
//		}
//		for (ft::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//			mine << it->second << ' ';
//		}
//		for (ft::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << it->second << ' ';
//		}
//
//		time_end(start, "mine[clear]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string> b(a.begin(), a.end());
//		std::map<int, std::string> c(b);
//
//		std::pair<int, std::string> pair(1, "PIYO");
//		b.insert(std::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		a.clear();
//		b.clear();
//		c.clear();
//
//		for (std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			std << it->second << ' ';
//		}
//		for (std::map<int, std::string>::const_iterator it = c.begin(); it != c.end(); ++it) {
//			std << it->second << ' ';
//		}
//		for (std::map<int, std::string>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << it->second << ' ';
//		}
//
//		time_end(start, "std[clear]");
//	}
//	std::cout << std::endl;
//
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string >::key_compare map_value_compare = a.key_comp();
//		ft::map<int, std::string, ft::map<int, std::string >::key_compare> b;
//		for(ft::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			mine << it->second << ' ';
//		}
//		mine << "test" << std::endl;
//		time_end(start, "mine[key_compare]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string >::key_compare map_value_compare = a.key_comp();
//		std::map<int, std::string, std::map<int, std::string >::key_compare> b;
//		for(std::map<int, std::string>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			std << it->second << ' ';
//		}
//		std << "test" << std::endl;
//		time_end(start, "std[key_compare]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string> b(a.begin(), a.end());
//		ft::map<int, std::string> c(b);
//
//		ft::pair<int, std::string> pair(1, "PIYO");
//		b.insert(ft::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		mine << ft::map<int, std::string>::const_iterator(a.find(2))->second << std::endl;
//		mine << ft::map<int, std::string>::iterator(a.find(2))->second << std::endl;
//		mine << ft::map<int, std::string>::const_iterator (b.find(2))->second << std::endl;
//		mine << ft::map<int, std::string>::iterator(b.find(2))->second << std::endl;
//
//		time_end(start, "mine[find]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string> b(a.begin(), a.end());
//		std::map<int, std::string> c(b);
//
//		std::pair<int, std::string> pair(1, "PIYO");
//		b.insert(std::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		std << std::map<int, std::string>::const_iterator(a.find(2))->second << std::endl;
//		std << std::map<int, std::string>::iterator(a.find(2))->second << std::endl;
//		std << std::map<int, std::string>::const_iterator (b.find(2))->second << std::endl;
//		std << std::map<int, std::string>::iterator(b.find(2))->second << std::endl;
//		time_end(start, "std[find]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string> b(a.begin(), a.end());
//		ft::map<int, std::string> c(b);
//
//		ft::pair<int, std::string> pair(1, "PIYO");
//		b.insert(ft::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		mine << a.count(2) << std::endl;
//		mine << a.count(2) << std::endl;
//		mine << b.count(2) << std::endl;
//		mine << b.count(2) << std::endl;
//
//		time_end(start, "mine[count]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string> b(a.begin(), a.end());
//		std::map<int, std::string> c(b);
//
//		std::pair<int, std::string> pair(1, "PIYO");
//		b.insert(std::make_pair(1, "TEST"));
//		b.erase(b.begin());
//		c.insert(c.begin(), c.end());
//		c.erase(c.begin(), --c.end() );
//		a.erase(1);
//		a.erase(3);
//		a.swap(b);
//		b.swap(c);
//		c.swap(a);
//		std << a.count(2) << std::endl;
//		std << a.count(2) << std::endl;
//		std << b.count(2) << std::endl;
//		std << b.count(2) << std::endl;
//
//		time_end(start, "std[count]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		mine << ft::map<int, std::string>::iterator(a.lower_bound(3))->second << std::endl;
//		mine << ft::map<int, std::string>::const_iterator (a.lower_bound(3))->second << std::endl;
//		mine << ft::map<int, std::string>::iterator(a.upper_bound(3))->second << std::endl;
//		mine << ft::map<int, std::string>::const_iterator (a.upper_bound(3))->second << std::endl;
//		mine << ft::pair<ft::map<int, std::string>::const_iterator, ft::map<int, std::string>::const_iterator>(a.equal_range(3)).second->second << std::endl;
//		mine << ft::pair<ft::map<int, std::string>::iterator , ft::map<int, std::string>::iterator >(a.equal_range(3)).second->second << std::endl;
//		time_end(start, "mine[bound]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std << std::map<int, std::string>::iterator(a.lower_bound(3))->second << std::endl;
//		std << std::map<int, std::string>::const_iterator (a.lower_bound(3))->second << std::endl;
//		std << std::map<int, std::string>::iterator(a.upper_bound(3))->second << std::endl;
//		std << std::map<int, std::string>::const_iterator (a.upper_bound(3))->second << std::endl;
//		std << std::pair<std::map<int, std::string>::const_iterator, std::map<int, std::string>::const_iterator>(a.equal_range(3)).second->second << std::endl;
//		std << std::pair<std::map<int, std::string>::iterator , std::map<int, std::string>::iterator >(a.equal_range(3)).second->second << std::endl;
//		time_end(start, "std[bound]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string>::allocator_type alloc = a.get_allocator();
//		mine << alloc.max_size() << std::endl;
//		time_end(start, "mine[alloc]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string>::allocator_type alloc = a.get_allocator();
//		std << alloc.max_size() << std::endl;
//		time_end(start, "std[alloc]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		ft::map<int, std::string > b;
//		b[1] = "one";
//		b[2] = "two";
//		b[3] = "three";
//		b[4] = "four";
//
//		ft::map<int, std::string > c;
//		b[1] = "one";
//		b[100] = "two";
//		b[3] = "three";
//		b[4] = "four";
//
//		mine << (a == b) << std::endl;
//		mine << (a != b) << std::endl;
//		mine << (a < b) << std::endl;
//		mine << (a <= b) << std::endl;
//		mine << (a > b) << std::endl;
//		mine << (a >= b) << std::endl;
//		mine << (c == b) << std::endl;
//		mine << (c != b) << std::endl;
//		mine << (c < b) << std::endl;
//		mine << (c <= b) << std::endl;
//		mine << (c > b) << std::endl;
//		mine << (c >= b) << std::endl;
//		mine << (c == a) << std::endl;
//		mine << (c != a) << std::endl;
//		mine << (c < a) << std::endl;
//		mine << (c <= a) << std::endl;
//		mine << (c > a) << std::endl;
//		mine << (c >= a) << std::endl;
//		time_end(start, "mine[operator]");
//	}
//	{
//		clock_t start = time_begin();
//		std::map<int, std::string > a;
//		a[1] = "one";
//		a[2] = "two";
//		a[3] = "three";
//		a[4] = "four";
//
//		std::map<int, std::string > b;
//		b[1] = "one";
//		b[2] = "two";
//		b[3] = "three";
//		b[4] = "four";
//
//		std::map<int, std::string > c;
//		b[1] = "one";
//		b[100] = "two";
//		b[3] = "three";
//		b[4] = "four";
//
//		std << (a == b) << std::endl;
//		std << (a != b) << std::endl;
//		std << (a < b) << std::endl;
//		std << (a <= b) << std::endl;
//		std << (a > b) << std::endl;
//		std << (a >= b) << std::endl;
//		std << (c == b) << std::endl;
//		std << (c != b) << std::endl;
//		std << (c < b) << std::endl;
//		std << (c <= b) << std::endl;
//		std << (c > b) << std::endl;
//		std << (c >= b) << std::endl;
//		std << (c == a) << std::endl;
//		std << (c != a) << std::endl;
//		std << (c < a) << std::endl;
//		std << (c <= a) << std::endl;
//		std << (c > a) << std::endl;
//		std << (c >= a) << std::endl;
//		time_end(start, "std[operator]");
//	}
//	std::cout << std::endl;
//
//}
//
//void vector(std::ofstream &mine, std::ofstream &std) {
//
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator it = b.begin(); it != b.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator it = c.begin(); it != c.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator it = e.begin(); it != e.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator it = f.begin(); it != f.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "mine[constructor]");
//	}
//	{
//		{
//			clock_t start = time_begin();
//			std::vector<int> a;
//			std::allocator<int> alloc;
//			std::vector<int> c(alloc);
//			std::vector<int> b(100, 50);
//			std::vector<int> d(10, 50, alloc);
//			std::vector<int> e(b.begin(), b.end());
//			std::vector<int> f(e);
//			a = b;
//			for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//				std << *it << std::endl;
//			}
//			for (std::vector<int>::const_iterator it = b.begin(); it != b.end(); ++it) {
//				std << *it << std::endl;
//			}
//			for (std::vector<int>::const_iterator it = c.begin(); it != c.end(); ++it) {
//				std << *it << std::endl;
//			}
//			for (std::vector<int>::const_iterator it = d.begin(); it != d.end(); ++it) {
//				std << *it << std::endl;
//			}
//			for (std::vector<int>::const_iterator it = e.begin(); it != e.end(); ++it) {
//				std << *it << std::endl;
//			}
//			for (std::vector<int>::const_iterator it = f.begin(); it != f.end(); ++it) {
//				std << *it << std::endl;
//			}
//			time_end(start, "std[constructor]");
//		}
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a(10, 50);
//		a.assign(50, 20);
//		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << ' ';
//		}
//		a.assign(50, 20);
//		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << ' ';
//		}
//		a.assign(10, 20);
//		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << ' ';
//		}
//
//		ft::vector<int> b;
//		b.assign(a.begin(), a.end());
//		for (ft::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << ' ';
//		}
//		time_end(start, "mine[assign]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a(10, 50);
//		a.assign(50, 20);
//		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << ' ';
//		}
//		a.assign(50, 20);
//		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << ' ';
//		}
//		a.assign(10, 20);
//		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << ' ';
//		}
//
//		std::vector<int> b;
//		b.assign(a.begin(), a.end());
//		for (std::vector<int>::const_iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << ' ';
//		}
//		time_end(start, "std[assign]");
//	}
//	std::cout << std::endl;
//	{
//		try{
//
//			clock_t start = time_begin();
//			ft::vector<int> a;
//			std::allocator<int> alloc;
//			ft::vector<int> c(alloc);
//			ft::vector<int> b(100, 50);
//			ft::vector<int> d(10, 50, alloc);
//			ft::vector<int> e(b.begin(), b.end());
//			ft::vector<int> f(e);
//			a = b;
//			for (int i = 0; i < 100; ++i) {
//				mine << b.at(i) << std::endl;
//			}
//			for (int i = 0; i < 100; ++i) {
//				mine << e.at(i) << std::endl;
//			}
//			for (int i = 0; i < 100; ++i) {
//				mine << b.at(i) << std::endl;
//			}
//			time_end(start, "mine[at]");
//
//		} catch (const std::exception& e) {
//			mine << e.what() << std::endl;
//		}
//	}
//	{
//		try{
//			clock_t start = time_begin();
//			std::vector<int> a;
//			std::allocator<int> alloc;
//			std::vector<int> c(alloc);
//			std::vector<int> b(100, 50);
//			std::vector<int> d(10, 50, alloc);
//			std::vector<int> e(b.begin(), b.end());
//			std::vector<int> f(e);
//			a = b;
//			for (int i = 0; i < 100; ++i) {
//				std << b.at(i) << std::endl;
//			}
//			for (int i = 0; i < 100; ++i) {
//				std << e.at(i) << std::endl;
//			}
//			for (int i = 0; i < 100; ++i) {
//				std << b.at(i) << std::endl;
//			}
//			time_end(start, "std[at]");
//
//		} catch (const std::exception& e) {
//			std << e.what() << std::endl;
//		}
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//		for (int i = 0; i < 100; ++i) {
//			mine << b[i] << std::endl;
//		}
//		for (int i = 0; i < 100; ++i) {
//			mine << e[i] << std::endl;
//		}
//		for (int i = 0; i < 1000; ++i) {
//			mine << b[i] << std::endl;
//		}
//		time_end(start, "mine[]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a;
//		std::allocator<int> alloc;
//		std::vector<int> c(alloc);
//		std::vector<int> b(100, 50);
//		std::vector<int> d(10, 50, alloc);
//		std::vector<int> e(b.begin(), b.end());
//		std::vector<int> f(e);
//		a = b;
//		for (int i = 0; i < 100; ++i) {
//			std << b[i] << std::endl;
//		}
//		for (int i = 0; i < 100; ++i) {
//			std << e[i] << std::endl;
//		}
//		for (int i = 0; i < 1000; ++i) {
//			std << b[i] << std::endl;
//		}
//		time_end(start, "std[]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a(100, 50);
//		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_iterator  it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//
//		for (ft::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::const_reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "mine[iterator]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a(100, 50);
//		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::const_iterator  it = a.begin(); it != a.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::const_reverse_iterator it = a.rbegin(); it != a.rend(); ++it) {
//			std << *it << std::endl;
//		}
//		time_end(start, "std[iterator]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a(100, 50);
//		mine << a.front() << std::endl;
//		mine << a.back() << std::endl;
//		mine << *a.data() << std::endl;
//		mine << *a.data() << std::endl;
//		time_end(start, "mine[back, front, data]");
//
//	}
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a(100, 50);
//		std << a.front() << std::endl;
//		std << a.back() << std::endl;
//		std << *a.data() << std::endl;
//		std << *a.data() << std::endl;
//		time_end(start, "std[back, front, data]");
//	}
//	std::cout << std::endl;
//		{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		mine << a.size() << std::endl;
//		mine << a.empty() << std::endl;
//		mine << b.size() << std::endl;
//		mine << b.empty() << std::endl;
//		mine << e.size() << std::endl;
//		mine << e.empty() << std::endl;
//		mine << b.size() << std::endl;
//		mine << b.empty() << std::endl;
//		time_end(start, "mine[size, empty]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a;
//		std::allocator<int> alloc;
//		std::vector<int> c(alloc);
//		std::vector<int> b(100, 50);
//		std::vector<int> d(10, 50, alloc);
//		std::vector<int> e(b.begin(), b.end());
//		std::vector<int> f(e);
//		a = b;
//
//		std << a.size() << std::endl;
//		std << a.empty() << std::endl;
//		std << b.size() << std::endl;
//		std << b.empty() << std::endl;
//		std << e.size() << std::endl;
//		std << e.empty() << std::endl;
//		std << b.size() << std::endl;
//		std << b.empty() << std::endl;
//		time_end(start, "std[size, empty]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		a.clear();
//		b.clear();
//		c.clear();
//		d.clear();
//		e.clear();
//		f.clear();
//		mine << a.size() << std::endl;
//		mine << a.empty() << std::endl;
//		mine << b.size() << std::endl;
//		mine << b.empty() << std::endl;
//		mine << e.size() << std::endl;
//		mine << e.empty() << std::endl;
//		mine << b.size() << std::endl;
//		mine << b.empty() << std::endl;
//		mine << e.size() << std::endl;
//		mine << e.empty() << std::endl;
//		mine << f.size() << std::endl;
//		mine << f.empty() << std::endl;
//		time_end(start, "std[size, empty]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a;
//		std::allocator<int> alloc;
//		std::vector<int> c(alloc);
//		std::vector<int> b(100, 50);
//		std::vector<int> d(10, 50, alloc);
//		std::vector<int> e(b.begin(), b.end());
//		std::vector<int> f(e);
//		a = b;
//
//		a.clear();
//		b.clear();
//		c.clear();
//		d.clear();
//		e.clear();
//		f.clear();
//		std << a.size() << std::endl;
//		std << a.empty() << std::endl;
//		std << b.size() << std::endl;
//		std << b.empty() << std::endl;
//		std << e.size() << std::endl;
//		std << e.empty() << std::endl;
//		std << b.size() << std::endl;
//		std << b.empty() << std::endl;
//		std << e.size() << std::endl;
//		std << e.empty() << std::endl;
//		std << f.size() << std::endl;
//		std << f.empty() << std::endl;
//		time_end(start, "std[size, empty]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "mine[push_back]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a;
//		std::allocator<int> alloc;
//		std::vector<int> c(alloc);
//		std::vector<int> b(100, 50);
//		std::vector<int> d(10, 50, alloc);
//		std::vector<int> e(b.begin(), b.end());
//		std::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			std << *it << std::endl;
//		}
//		time_end(start, "std[push_back]");
//	}
//	std::cout << std::endl;
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		a.pop_back();
//		b.pop_back();
//		c.pop_back();
//		d.pop_back();
//		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "mine[pop_back]");
//	}
//	{
//		clock_t start = time_begin();
//		std::vector<int> a;
//		std::allocator<int> alloc;
//		std::vector<int> c(alloc);
//		std::vector<int> b(100, 50);
//		std::vector<int> d(10, 50, alloc);
//		std::vector<int> e(b.begin(), b.end());
//		std::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		a.pop_back();
//		b.pop_back();
//		c.pop_back();
//		d.pop_back();
//		for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			std << *it << std::endl;
//		}
//		for (std::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			std << *it << std::endl;
//		}
//		time_end(start, "std[pop_back]");
//	}
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		a.erase(a.begin());
//		for(ft::vector<int>::iterator it = a.begin();it != a.end();  ++it) {
//			a.erase(it);
//		}
//		b.erase(b.begin(), b.end() - 1);
//		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "mine[erase]");
//	}
//	{
//		clock_t start = time_begin();
//		ft::vector<int> a;
//		std::allocator<int> alloc;
//		ft::vector<int> c(alloc);
//		ft::vector<int> b(100, 50);
//		ft::vector<int> d(10, 50, alloc);
//		ft::vector<int> e(b.begin(), b.end());
//		ft::vector<int> f(e);
//		a = b;
//
//		for (int i = 0; i < 1000; ++i) {
//			a.push_back(i);
//		}
//		for (int i = 0; i < 200; ++i) {
//			b.push_back(i);
//		}
//		for (int i = -100; i < 0; ++i) {
//			c.push_back(i);
//		}
//		for (int i = 1000; i <  2000; ++i) {
//			e.push_back(i);
//		}
//		a.erase(a.begin());
//		for(ft::vector<int>::iterator it = a.begin();it != a.end();  ++it) {
//			a.erase(it);
//		}
//		b.erase(b.begin(), b.end() - 1);
//		for (ft::vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = b.begin(); it != b.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = c.begin(); it != c.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		for (ft::vector<int>::iterator it = d.begin(); it != d.end(); ++it) {
//			mine << *it << std::endl;
//		}
//		time_end(start, "std[erase]");
//	}
//}
//*/