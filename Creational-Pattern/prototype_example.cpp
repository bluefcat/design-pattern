#include <iostream>
#include <string>

using namespace std;

class Address{
	public:
		string street_;
		string city_;
		int suite_;

		Address(string street, string city, int suite): street_(street), city_(city), suite_(suite){ }
};

template<typename T> class Cloneable{
	public:	
		virtual T Clone() const = 0;
};

class Contact: public Cloneable<Contact>{
	string name_;
	Address* address_;

	public:
		Contact(string name, Address* address):name_(name), address_(address){ }
		Contact Clone() const{
			return Contact(name_, new Address(*address_));
		}

		void PrintContact(){
			cout << name_ << endl;
			cout << address_->street_ << " " << address_->city_ << " " << address_->suite_ << endl;
			return;
		}
};

int main(){
	Contact worker("sss", new Address("123 East Dr", "London", 0));
	Contact john = worker.Clone();

	john.PrintContact();

	return 0;
}
