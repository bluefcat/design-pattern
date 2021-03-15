#include <iostream>
#include <vector>
#include <string>

class Observer{
	public:
		virtual void Update() = 0;
};

class Subject{
	private:
		std::vector<Observer*> observers;

	public:
		void Attach(Observer* observer){
			observers.push_back(observer);
		}
		
		void Notify(){
			for(auto observer : observers){
				observer->Update();
			}
		}
};

class ConcreteSubject: public Subject{
	public:
		std::string SubjectState;
};

class ConcreteObserver: public Observer{
	private:
		std::string name;
		std::string observerState;

	public:
		ConcreteSubject* subject;
		ConcreteObserver(ConcreteSubject* subject, std::string name){
			this->name = name;
			this->subject = subject;
		}

		void Update(){
			observerState = subject->SubjectState;
			std::cout << "Observer " << name << "'s new state is " << observerState << "\n";
		}
};

int main(){
	ConcreteSubject s;
	
	Observer* x = new ConcreteObserver(&s, "X");
	Observer* y = new ConcreteObserver(&s, "Y");
	Observer* z = new ConcreteObserver(&s, "Z");

	s.Attach(x);
	s.Attach(y);
	s.Attach(z);

	s.SubjectState = "ABC";
	s.Notify();

	delete z;
	delete y;
	delete x;
	return 0;
}

