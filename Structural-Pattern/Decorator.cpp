#include <iostream>

class Component{
	public:
		virtual void Operation() = 0;
};

class ConcreteComponent : public Component{
	public:
		void Operation(){
			std::cout << "ConcreteComponent Operation()\n";
		}
};

class Decorator : public Component{
	protected:
		Component* component;
	public:
		void SetComponent(Component* component){
			this->component = component;
		}			
		
		virtual void Operation(){
			if(component != nullptr) component->Operation();
		}
};

class ConcreteDecoratorA : public Decorator{
	public:
		void Operation(){
			Decorator::Operation();
			std::cout << "ConcreteDecoratorA Operation()\n";
		}
};

class ConcreteDecoratorB : public Decorator{
	public:
		void Operation(){
			Decorator::Operation();
			std::cout << "ConcreteDecoratorB Operation()\n";
		}

		void AddedBehavior(){}
};

int main(){
	ConcreteComponent c;
	ConcreteDecoratorA da;
	ConcreteDecoratorB db;
	
	da.SetComponent(&c);
	db.SetComponent(&da);

	da.Operation();
	std::cout << std::endl;
	db.Operation();

	return 0;
}
