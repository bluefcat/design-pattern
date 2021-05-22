#include <iostream>

template <typename T>
class Parent{
	public:
		void EventLoop(){
			(static_cast<T*>(this))->Event();
		}

		void Event(){
			std::cout << "This is Parent Event\n";
		}
};

class Child: public Parent<Child>{
	public:
		void Event(){
			std::cout << "This is Child Event\n";
		}
};

int main(){
	Child c;
	c.EventLoop();

	return 0;
}
