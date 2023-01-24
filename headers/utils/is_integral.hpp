#ifndef INTEGRAL
#define INTEGRAL
namespace ft {
	template <bool T>
	struct is_integral_type {
		static const bool value = T;
	};


	template <typename T>
	struct is_integral_base
			: is_integral_type<false> {};
	template <>
	struct is_integral_base <bool>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <wchar_t>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <signed char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <short int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <long long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <unsigned char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <unsigned short int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <unsigned int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <unsigned long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <unsigned long long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const bool>
			:is_integral_type<true> {};
	template <>
	struct is_integral_base <const char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const wchar_t>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const signed char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const short int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const long long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const unsigned char>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const unsigned short int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const unsigned int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const unsigned long int>
			: is_integral_type<true> {};
	template <>
	struct is_integral_base <const unsigned long long int>
			: is_integral_type<true> {};

	template <class T>
	struct is_integral : public is_integral_base<T> {};
}

#endif