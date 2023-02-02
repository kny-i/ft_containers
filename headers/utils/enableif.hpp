#ifndef ENABLE
#define ENABLE


//if bool is false, does nothing
//if bool is true, do upper thing
namespace ft {
	template <bool Condition, class T = void>
			struct enable_if {};
	template <class T>
		struct enable_if<true, T> {
			typedef T type;
		};
}


#endif
