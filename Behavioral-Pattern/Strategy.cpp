#include <iostream>

class Strategy{
	public:
		virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA: public Strategy{
	public:
		void AlgorithmInterface(){
			std::cout << "Called A Algorithm()\n";
		}
};

class ConcreteStrategyB: public Strategy{
	public:
		void AlgorithmInterface(){
			std::cout << "Called B Algorithm()\n";
		}
};

class ConcreteStrategyC: public Strategy{
	public:
		void AlgorithmInterface(){
			std::cout << "Called C Algorithm()\n";
		}
};

class Context{
	private:
		Strategy* strategy;
	
	public:
		Context(Strategy* strategy){
			this->strategy = strategy;
		}

		void ContextInterface(){
			strategy->AlgorithmInterface();
		}
};

int main(){
	ConcreteStrategyA a;
	ConcreteStrategyB b;
	ConcreteStrategyC c;

	Context* context = new Context(&a);
	context->ContextInterface();
	delete context;

	context = new Context(&b);
	context->ContextInterface();
	delete context;

	context = new Context(&c);
	context->ContextInterface();
	delete context;

	return 0;
}


