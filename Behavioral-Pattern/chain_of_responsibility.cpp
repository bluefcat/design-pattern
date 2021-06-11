#include <iostream>
#include <string>

using std::ostream;

class Creature{
	public:
		std::string name_;
		int attack_, defense_;

		Creature(const std::string& name, const int attack, const int defense)
			:name_(name), attack_(attack), defense_(defense){
			}

		friend ostream& operator<<(ostream& os, const Creature& obj){
			return os
				<< "name: " << obj.name_ 
				<< "\nattack: " << obj.attack_
				<< "\ndefense: " << obj.defense_;
		}
};

class CreatureModifier{
	CreatureModifier* next{nullptr};
	protected:
		Creature& creature_;
	
	public:
		explicit CreatureModifier(Creature& creature)
			:creature_(creature){}

		void add(CreatureModifier* cm){
			if(next) next->add(cm);
			else next = cm;
		}

		virtual void handle(){
			if(next) next->handle(); //main point!
		}
};

class DoubleAttackModifier: public CreatureModifier{
	public:
		explicit DoubleAttackModifier(Creature& creature)
			:CreatureModifier(creature){}

		void handle() override{
			creature_.attack_ *= 2;
			CreatureModifier::handle();	//!
		}
};

class IncreaseDefenseModifier: public CreatureModifier{
	public:
		explicit IncreaseDefenseModifier(Creature& creature)
			:CreatureModifier(creature){}

		void handle() override{
			if(creature_.attack_ <= 2) creature_.defense_ = 1;
			CreatureModifier::handle(); //!	
		}
};


int main(){
	Creature c{"Slime", 1, 1};
	CreatureModifier root{c};
	
	std::cout << c << std::endl;

	DoubleAttackModifier r1{c};
	DoubleAttackModifier r1_2{c};

	IncreaseDefenseModifier r2{c};

	root.add(&r1);
	root.add(&r1_2);
	root.add(&r2);

	root.handle();

	std::cout << c << std::endl;

	return 0;
}
