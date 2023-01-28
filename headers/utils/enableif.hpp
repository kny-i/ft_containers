#ifndef ENABLE
#define ENABLE


//if bool is false, does nothing
//if bool is true, do upper thing
namespace ft {
	template<bool Bool, typename T = void >
	struct enable_if {
		typedef T type;
	};
	template<typename T>
	struct ft::enable_if<false, T> {};
}

#endif