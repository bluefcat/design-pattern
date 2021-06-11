#include <iostream>
#include <string>

//this pattern is pimpl(Pointer to Implementation)
//

class Person{
	public:
		std::string name_;

		class Personimpl;
		Personimpl* impl_;

		Person();
		~Person();

		void greet();
};

class Person::Personimpl{
	public:
		void greet(Person* p){
			std::cout << "Hello! " << p->name_ << "\n";
		}
};

Person::Person(): impl_(new Personimpl()){

}

Person::~Person(){
	delete impl_;
}

int main(){
	Person p;
	p.name_ = "Tom";
	(p.impl_)->greet(&p);

	return 0;
}
