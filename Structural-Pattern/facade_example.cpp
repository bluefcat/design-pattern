#include <iostream>

class Engine{
	public:
		void Start(){
			std::cout << "engine is started\n";
		}
};

class Headlights{
	public:
		void TurnOn(){
			std::cout << "Headlights turn on\n";
		}
};

//facade
class Car{
	public:
		void Start(){
			headlights_.TurnOn();
			engine_.Start();
		}
	private:
		Engine engine_;
		Headlights headlights_;
};

int main(){
	Car car;
	car.Start();

	return 0;
}
