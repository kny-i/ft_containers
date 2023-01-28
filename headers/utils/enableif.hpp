#ifndef ENABLE
#define ENABLE

namespace ft {
	template<bool Bool, typename T = void >
	struct enable_if {
		typedef T type;
	};
	template<typename T>
	struct ft::enable_if<false, T> {};
}

#endif