#ifndef STACK_HPP
#define STACK_HPP
#include <vector>
#include <vector.hpp>


/* ft::vectorはコンポジションとなる */

namespace ft {
	template <class T, typename Container = ft::vector<T> >
	class stack {
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

		explicit stack(const container_type &cont = container_type()) : c(cont) {}
		stack(const stack &other) : c(other.c) {}
		~stack() {}

		bool empty() const {return c.empty();}
		size_type size() const {return c.size();}
		value_type &top(){return c.back();}
		const value_type &top() const{return c.back();}
		void push(const value_type &value) {c.push_back(value);}
		void pop() {return c.pop_back();}


		//stackの場合はclass外にoperatorの処理を実現できない

		friend bool operator==(const stack<T, Container> &lhs, const stack<T, Container>  &rhs) {
			return lhs.c == rhs.c;
		}
		friend bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(lhs.c == rhs.c);
		}
		friend bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return lhs.c < rhs.c;
		}
		friend bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(rhs.c < lhs.c);
		}
		friend bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return rhs.c < lhs.c;
		}
		friend bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
			return !(lhs.c < rhs.c);
		}

	protected:
		Container c;

	};

}

#endif
