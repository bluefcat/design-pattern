#include <iostream>

class Implementor{
	public:
		virtual void Operation() = 0;
};

class Abstraction{
	protected:
		Implementor* implementor;
	
	public:
		void SetImplementor(Implementor* implementor){
			this->implementor = implementor;
		}
		virtual void Operation(){
			implementor->Operation();
		}
};

class RefinedAbstraction : public Abstraction{
	public:
		void Operation(){
			implementor->Operation();
		}
};

class ConcreteImplementorA : public Implementor{
	public:
		void Operation(){
			std::cout << "ConcreteImplementorA Operation\n";
		}
};

class ConcreteImplementorB : public Implementor{
	public:
		void Operation(){
			std::cout << "ConcreteImplementorB Operation\n";
		}
};

int main(){
	Abstraction* ab = new RefinedAbstraction();
	
	ab->SetImplementor(new ConcreteImplementorA());
	ab->Operation();

	ab->SetImplementor(new ConcreteImplementorB());
	ab->Operation();

	return 0;
}
