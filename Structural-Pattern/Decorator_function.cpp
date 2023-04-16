#include <iostream>
#include <functional>

template <typename F, typename... Args>
using fp = std::function<typename std::result_of<F(Args...)>::type(F&& f, Args&&... args)>;

template <typename F, typename... Args>
auto decorator(F&& f, Args&&... args){
	std::cout << "This is Decorator\n";
	auto result = f(args...);
	std::cout << "This is Decorator\n";
	return result;
}

int function(int a, int b){
	std::cout << a << " + " << b << " = " << a+b << "\n";
	return a+b;
}

int main(){
	int a = decorator(function, 1, 2);
	
	std::cout << a << "\n";

	return 0;
}
