#include <iostream>
#include <string>

class Mediator{
	public:
		virtual void Send(std::string, int rcv) = 0;
};

class Colleague{
	protected:
		Mediator* mediator;
	
	public:
		Colleague(Mediator* mediator){
			this->mediator = mediator;
		}
};

class ConcreteColleagueA: public Colleague{
	public:
		ConcreteColleagueA(Mediator* mediator)
		:Colleague(mediator){
		
		}
		
		void Send(std::string message){
			mediator->Send(message, 1);
		}

		void Notify(std::string message){
			std::cout << "ColleagueA get message : " << message << "\n";
		}
};

class ConcreteColleagueB: public Colleague{
	public:
		ConcreteColleagueB(Mediator* mediator)
		:Colleague(mediator){
		}
		void Send(std::string message){
			mediator->Send(message, 2);
		}

		void Notify(std::string message){
			std::cout << "ColleagueB get message : " << message << "\n";
		}
};

class ConcreteMediator: public Mediator{
	private:
		ConcreteColleagueA* colleagueA;
		ConcreteColleagueB* colleagueB;

	public:
		ConcreteMediator(ConcreteColleagueA* a, ConcreteColleagueB* b)
			:colleagueA(a), colleagueB(b){}
		void Send(std::string message, int rcv){
			if(rcv == 1){
				colleagueB->Notify(message);
			}
			else{
				colleagueA->Notify(message);
			}
		}
};

int main(){
	ConcreteColleagueA* a;
	ConcreteColleagueB* b;
	Mediator* m = new ConcreteMediator(a, b);
	a = new ConcreteColleagueA(m);
	b = new ConcreteColleagueB(m);

	a->Send("How are you?");
	b->Send("Fine, Thanks");

	delete m;
	delete b;
	delete a;
	return 0;
}
