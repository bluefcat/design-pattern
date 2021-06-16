#include <iostream>
#include <map>
#include <string>
#include <memory>

class HotDrink{
	public:
		virtual void prepare(int volume) = 0;
};

class Tea: public HotDrink{
	public:
		void prepare(int volume) override{
			std::cout << "Take tea bag, boil water, pour " << volume << "ml, add some lemon\n";
		}
};

class Coffee: public HotDrink{
	public:
		void prepare(int volume) override{
			std::cout << "Grind some beans, boil water, pour " << volume << "ml, add cream\n";
		}
};

class HotDrinkFactory{
	public:
		virtual std::unique_ptr<HotDrink> Make() const = 0;
};

class TeaFactory: public HotDrinkFactory{
	std::unique_ptr<HotDrink> Make() const override{
		return std::make_unique<Tea>();
	}
};

class CoffeeFactory: public HotDrinkFactory{
	std::unique_ptr<HotDrink> Make() const override{
		return std::make_unique<Coffee>();
	}
};

class DrinkFactory{
	private:
		std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories_;
	
	public:
		DrinkFactory(){
			hot_factories_["coffee"] = std::make_unique<CoffeeFactory>();
			hot_factories_["tea"] = std::make_unique<TeaFactory>();
		}

		std::unique_ptr<HotDrink> MakeDrink(const std::string& name, int volume){
			auto drink = hot_factories_[name]->Make();
			drink->prepare(volume);
			return drink;
		}
};

int main(){
	DrinkFactory df;
	df.MakeDrink("coffee", 100);
	return 0;
}
