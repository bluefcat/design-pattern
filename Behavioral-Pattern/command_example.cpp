#include <iostream>

class BankAccount{
	private:
		int balance_;
		int overdraft_limit_;

	public:
		BankAccount(){
			balance_ = 0;
			overdraft_limit_ = -500;
		}

		void Deposit(int amount){
			balance_ += amount;
			std::cout << "Deposited: " << amount << "\nBalance Now: " << balance_ << "\n";
			return ;
		}

		void Withdraw(int amount){
			balance_ -= amount;
			if(balance_ < overdraft_limit_) {
				balance_ += amount;
				return;
			}
			
			std::cout << "Withdraw: " << amount << "\nBalance Now: " << balance_ << "\n";
			return;
		}
};

class Command{
	virtual void Call() const = 0;
	virtual void Undo() const = 0;
};

class BankAccountCommand: public Command{
	private:
		BankAccount& account_;
		int amount_;

	public:
		enum Action_ { Deposit, Withdraw } action_;

	public:
		BankAccountCommand(BankAccount& account, const Action_ action, const int amount)
			:account_(account), action_(action), amount_(amount){
		}

		void Call() const{
			switch(action_){
			case Deposit:
				account_.Deposit(amount_);
				break;
			case Withdraw:
				account_.Withdraw(amount_);
				break;
			default:
				break;
			}
		}

		void Undo() const{
			switch(action_){
				case Deposit:
					account_.Withdraw(amount_);
					break;
				case Withdraw:
					account_.Deposit(amount_);
					break;
				default:
					break;
			}
		}
};

int main(){
	BankAccount ba;
	BankAccountCommand cmd(ba, BankAccountCommand::Deposit, 100);
	cmd.Call();
	cmd.Undo();
	return 0;
}
