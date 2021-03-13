#include <iostream>
#include <vector>

using std::vector;

class Component{
	protected:
		std::string name;
	
	public:
		Component(std::string name) : name(name){}

		virtual void Add(Component* c) = 0;
		virtual void Remove(Component* c) {};
		virtual void Display(int depth) = 0;
};

class Composite : public Component{
	private:
		vector<Component*> childeren;

	public:
		Composite(std::string name) : Component(name){}
		void Add(Component* c){
			childeren.push_back(c);
		}			

		void Display(int depth){
			for(int i = 0; i < depth; i ++) std::cout << "-";
			std::cout << name << "\n";

			for(auto child : childeren){
				child->Display(depth+2);
			}
		}
};

class Leaf : public Component{
	public:
		Leaf(std::string name) : Component(name) {}
		void Add(Component* c){
			return;
		}

		void Display(int depth){
			for(int i = 0; i < depth; i ++) std::cout << "-";
			std::cout << name << "\n";
		}
};

int main(){
	Composite root("root");
	Leaf leafA("Leaf A");
	Leaf leafB("Leaf B");

	Composite comp("Composite X");
	Leaf leafXA("Leaf XA");
	Leaf leafXB("Leaf XB");
	Leaf leafC("Leaf C");
	
	root.Add(&leafA);
	root.Add(&leafB);
		
	comp.Add(&leafXA);
	comp.Add(&leafXB);

	root.Add(&comp);
	root.Add(&leafC);
	root.Display(1);
	return 0;
}


