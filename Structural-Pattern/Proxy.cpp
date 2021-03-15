#include <iostream>

class Subject{
	public:
		virtual void Request() = 0;
};

class RealSubject : public Subject{
	public:
		void Request(){
			std::cout << "RealSubject Request\n";
		}
};

class Proxy : public Subject{
	private:
		RealSubject realSubject;

	public:
		void Request(){
			realSubject.Request();
		}	
};

int main(){
	Proxy proxy;
	proxy.Request();

	return 0;
}
