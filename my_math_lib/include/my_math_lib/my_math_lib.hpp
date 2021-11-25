//
// Created by yunfan on 2021/11/24.
//

#ifndef MY_MATH_LIB_MY_MATH_LIB_HPP
#define MY_MATH_LIB_MY_MATH_LIB_HPP

#include "iostream"
using namespace std;

namespace my_math_lib{

    template <typename T>
    class Complex{
        friend ostream& operator<<(ostream &out, Complex &c)
        {
            out<<c.a << " + " << c.b << "i";
            return out;
        }
    private:
        T a;
        T b;

    public:
        Complex(T a, T b){
            this->a = a;
            this->b = b;
        };

        Complex<T> operator+(Complex &c)
        {
            Complex<T> tmp(this->a+c.a, this->b+c.b);
            return tmp;
        }
    };
}// namespace my_math_lib

#endif //MY_MATH_LIB_MY_MATH_LIB_HPP
