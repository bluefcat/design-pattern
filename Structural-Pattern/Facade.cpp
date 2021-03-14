#include <iostream>

class SubSystemA{
	public:
		void MethodA(){
			std::cout << "SubSystemA Method\n";
		}
};

class SubSystemB{
	public:
		void MethodB(){
			std::cout <<"SubSystemB Method\n";
		}
};

class SubSystemC{
	public:
		void MethodC(){
			std::cout << "SubSystemC Method\n";
		}
};

class Facade{
	private:
		SubSystemA a;
		SubSystemB b;
		SubSystemC c;

	public:
		void Method_one(){
			std::cout << "\nMethod_one ---\n";
			a.MethodA();
			b.MethodB();
		}

		void Method_two(){
			std::cout << "\nMethod_two ---\n";
			b.MethodB();
			c.MethodC();
		}
};

int main(){
	Facade facade;
	facade.Method_one();
	facade.Method_two();
	return 0;
}
