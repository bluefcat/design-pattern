#include <iostream>

class Singleton{
	private:
		Singleton() {}
		static Singleton* _instance;	

	public:
		static Singleton* get_instance(){
			if(_instance == nullptr) _instance = new Singleton();
			return _instance;
		}

};

Singleton* Singleton::_instance = nullptr;

int main(){
	Singleton* tmpA = Singleton::get_instance();
	Singleton* tmpB = Singleton::get_instance();

	std::cout << tmpA << ", " << tmpB << "\n";

	return 0;
}
