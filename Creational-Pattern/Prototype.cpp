#include <iostream>

class Prototype{
	public:
	int id;
	Prototype(int id):id(id){}
	Prototype(Prototype& p){
		this->id = p.id;
	}
	
	virtual Prototype& Clone() = 0;
};

class ConcretePrototypeA : public Prototype{
	public:
	ConcretePrototypeA(int id):Prototype(id){}
	ConcretePrototypeA(Prototype& p):Prototype(p.id){}
	Prototype& Clone(){ 
		return *this;
	}
};

class ConcretePrototypeB : public Prototype{
	public:
	ConcretePrototypeB(int id):Prototype(id){}
	ConcretePrototypeB(Prototype& p):Prototype(p.id){}
	Prototype& Clone(){
		return *this;
	}
};

int main(){
	ConcretePrototypeA cpA(3);
	ConcretePrototypeB cpB(2);

	std::cout << "Prototype A : " << &cpA << ", " << cloneA.id << "\n";

	(ConcretePrototypeB)cpB.Clone();
	std::cout << "Prototype B : " << &cpB << ", "  << "\n";

	return 0;
}
