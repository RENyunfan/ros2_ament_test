//
// Created by yunfan on 2021/11/24.
//


#include "iostream"
#include "my_math_lib/my_math_lib.hpp"
using namespace std;
int main(){

    my_math_lib::Complex<int> a(12,30);
    my_math_lib::Complex<int> b(2,10);
    my_math_lib::Complex<int> c = a + b;

    cout<<c<<endl;

    return 0;
}