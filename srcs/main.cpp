#include <vector.hpp>

//int main()
//{
//	std::cout << "hello world" << std::endl;
//
//
//	ft::vector<int> a(1, 3);
//
	//push_back
//	a.push_back(2);
//	a.push_back(2);
//	a.push_back(2);
//	a.push_back(2);
//
//	for (ft::vector<int>::iterator start = a.begin(); start != a.end(); ++start)
//	{
//		std::cout << *start << std::endl;
//	}
//
//
//
//
//}
//

#include <map>

int	main()
{
	std::map<int , std::string> a;

	a[0] = "hoge";
	a[1] = "fuga";
	a[2] = "piyo";
	a[3] = "saga";

	std::cout << (a.begin()->second) << std::endl;
	std::cout << (a.end()->second) << std::endl;



}