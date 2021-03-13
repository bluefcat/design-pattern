#include <iostream>

class Adaptee{
	public:
	void SpecificRequest(){
		std::cout << "Called SepcificRequest()\n";
	}
};

class Target{
	public:
	virtual void Request(){
		std::cout << "Called Target Request()\n";
	}
};

class Adapter : public Target{
	Adaptee adaptee;
	public:
	Adapter(){}
	virtual void Request(){
		adaptee.SpecificRequest();
	}
};

int main(){
	Target* target = new Adapter();
	target->Request();

	return 0;
}

