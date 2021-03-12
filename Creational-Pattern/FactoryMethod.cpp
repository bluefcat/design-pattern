#include <iostream>

class Product{
	public:
		virtual ~Product() {}
		virtual void Use() = 0;
};

class ProductA : public Product{
	public:
		ProductA(){ std::cout << "Create ProductA" << std::endl; }
		void Use(){ std::cout << "Use ProductA" << std::endl; }
};

class ProductB : public Product{
	public:
		ProductB(){ std::cout << "Create ProductB" << std::endl; }
		void Use(){ std::cout << "Use ProductB" << std::endl; }
};

class Creator{
	public:
		virtual ~Creator() {};
		virtual Product& FactoryMethod() = 0;
};

class ConcreteCreatorA : public Creator{
	public:
		ConcreteCreatorA(){}
		Product& FactoryMethod(){ 
			static ProductA a; 
			return a; 
		}
};

class ConcreteCreatorB : public Creator{
	public:
		ConcreteCreatorB(){}
		Product& FactoryMethod(){ 
			static ProductB b;
			return b; 
		}
};

int main(){
	ConcreteCreatorA factoryA;
	ConcreteCreatorB factoryB;

	factoryA.FactoryMethod().Use();
	factoryB.FactoryMethod().Use();

	return 0;
}
