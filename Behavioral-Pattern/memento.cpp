#include <iostream>

class Memento{
	public:
		Memento(int balance): balance_(balance){ }
		friend class BankAccount;
	private:
		int balance_;
};

class BankAccount{
	public:
		explicit BankAccount(const int balance)
			:balance_(balance){
			}

		Memento deposit(int amount){
			balance_ += amount;
			return { balance_ };
		}

		void restore(const Memento& m){
			balance_ = m.balance_;
		}

		void Print(){
			std::cout << "This account have balance: " << balance_ << "$\n";
		}
	private:
		int balance_ = 0;
};

int main(){
	BankAccount ba{ 100 };
	auto m1 = ba.deposit(50);
	ba.Print();
	auto m2 = ba.deposit(25);
	ba.Print();

	ba.restore(m1);
	ba.Print();

	ba.restore(m2);
	ba.Print();


	return 0;
}

