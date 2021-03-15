#include <iostream>

class Receiver{
	public:
		void Action(){
			std::cout << "Called Receiver Action\n";
		}
};

class Command{
	protected:
		Receiver receiver;

	public:
		virtual void Execute() = 0;
};

class ConcreteCommand : public Command{
	public:
		void Execute(){
			receiver.Action();
		}
};

class Invoker{
	private:
		Command* command;
	
	public:
		void SetCommand(Command* command){
			this->command = command;
		}

		void Execute(){
			command->Execute();
		}
};

int main(){
	Command* command = new ConcreteCommand();
	Invoker invoker;

	invoker.SetCommand(command);
	invoker.Execute();

	delete command;

	return 0;
}
