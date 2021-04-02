#include <iostream>

class Weapon{
	public:
		int power_;
};

class Armor{
	public:
		int defence_;
};

class Character{
	public:
		Weapon* weapon_;
		Armor* armor_;

		void DisplayParts(){
			std::cout << "Weapon power: " << weapon_->power_ << std::endl;
			std::cout << "Armor defence: " << armor_->defence_ << std::endl;
		}

};

class CharacterBuilder{
	public:
		virtual Weapon* CreateWeapon() = 0;
		virtual Armor* CreateArmor() = 0;
};

class CharacterDirector{
	private:
		CharacterBuilder* builder_;
	public:
		void SetBuilder(CharacterBuilder* builder){
			builder_ = builder;
		}

		Character* CreateCharacter(){
			Character* result = new Character();

			result->weapon_ = builder_->CreateWeapon();
			result->armor_ = builder_->CreateArmor();

			return result;
		}
};

class ArcherBuilder: public CharacterBuilder{
	public:
		Weapon* CreateWeapon(){
			Weapon* weapon = new Weapon();
			weapon->power_ = 200;

			return weapon;
		}
		Armor* CreateArmor(){
			Armor* armor = new Armor();
			armor->defence_ = 50;

			return armor;
		}
};


class WarriorBuilder: public CharacterBuilder{
	public:
		Weapon* CreateWeapon(){
			Weapon* weapon = new Weapon();
			weapon->power_ = 50;

			return weapon;
		}
		Armor* CreateArmor(){
			Armor* armor = new Armor();
			armor->defence_ = 200;

			return armor;
		}
};

int main(){
	Character* character;
	CharacterDirector director;

	ArcherBuilder archer;
	director.SetBuilder(&archer);
	character = director.CreateCharacter();
	character->DisplayParts();

	return 0;
}
