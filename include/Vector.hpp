#ifndef VECTOR_HPP
#define VECTOR_HPP

# include <vector>
# include <initializer_list>
# include <iostream>

template<typename T>
class Vector {
	private:
		std::vector<T> data;
	
	public:
		Vector() = default;
		Vector(size_t size) : data(size) {}
		Vector(std::initializer_list<T>init) : data(init) {}

		auto size() const -> size_t { return data.size(); } // -> size_t veut dire ouput en size_t
		auto begin() const { return data.begin(); }
		auto end() const { return data.end() ;}

		T& operator[](size_t i) { return data[i] ;}
		const T& operator[](size_t i) const { return data[i] ;}

		void print() const {
			std::cout << "[";
			for (size_t i = 0; i < data.size(); i++) {
				std::cout << data[i];
				if (i < data.size() - 1) std::cout << ", ";
			}
			std::cout << "]";
		}

		// Ex00 operations
		void add(const Vector<T>& other);
		void sub(const Vector<T>& other);
		void scl(T scalar);

		// ex03 (produit scalaire)
		T dot(const Vector<T>& other) const;

		// ex04 (norme)
		T norm1() const;
		T norm() const;
		T norm_inf() const;

		// ex05
		T angle_cos(const Vector<T>& other) const;
};

#include "../src/Vector.tpp"

#endif