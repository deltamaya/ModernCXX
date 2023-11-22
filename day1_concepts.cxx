//
// Created by delta on 22/11/2023.
//
#include <iostream>
#include <concepts>

// 概念 "Hashable" 的声明可以被符合以下条件的任意类型 T 满足：
// 对于 T 类型的值 a，表达式 std::hash<T>{}(a) 可以编译并且它的结果可以转换到 std::size_t
template<typename T>
concept Hashable=requires(T a)
{
	{std::hash<T>{}(a)}->std::convertible_to<size_t>;
};

template<Hashable T>
void fn1(T){}

void fn2(Hashable auto e){}

template<typename T>
concept always_true=true;

template<class T,class U>requires always_true<T>&&Hashable<T>&&std::integral<U>
void fn3(){};

template<typename T>
concept decrementable=requires(T t){t--;};

template<typename T>
concept reverse_iterator=decrementable<T>&&requires(T t){*t;};

int main(){
	//常用的concepts
	bool integer=std::integral<int>;
	bool same=std::same_as<int,int>;
	bool derive=std::derived_from<int,int>;
	bool cons=std::constructible_from<int,int>;
	bool mv=std::movable<int>;
	bool cp=std::copyable<int>;
	bool inv=std::invocable<decltype([](int a){std::cout<<a<<std::endl;}),int>;
	//specifies that an object of a type can be copied, moved, swapped, and default constructed
	bool semi=std::semiregular<int>;
	bool eq=std::equality_comparable<int>;//int==int
	bool eq_with=std::equality_comparable_with<int,double>;//int==double?
	bool ord=std::totally_ordered<int>;//> < == != >= <=
	bool ord_with=std::totally_ordered_with<int,double>;//<=> == !=
	//semiregular + equ
	bool reg=std::regular<int>;
}