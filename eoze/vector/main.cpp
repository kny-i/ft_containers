#include <vector>
#include <map>
#include <iostream>
int	main()
{
	std::map<int, std::string> a;

	a[1] = "hoge";
	std::map<int, std::string>::const_iterator it = a.begin();
	it->second = "hoge";
	it->first = 3;

}