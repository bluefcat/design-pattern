#include <iostream>
#include <string>

class Product{
	std::string option;
	std::string base;

	public:
	Product() {};
	void SetOption(std::string option){this->option = option;}
	void SetBase(std::string base){this->base = base;}
	void Print(){
		std::cout << option << "\n";
		std::cout << base << "\n";
	}
};

class Builder{
	public:
	Product p;
	Builder() {}
	Product GetProduct(){ return this->p; }
	
	virtual void BuildOption() = 0;
	virtual void BuildBase() = 0;
};

class ConcreteBuilderA : public Builder{
	public:
	void BuildOption(){ p.SetOption("Option A"); }
	void BuildBase(){ p.SetBase("Base A"); }
};

class ConcreteBuilderB : public Builder{
	public:
	void BuildOption(){ p.SetOption("Option B"); }
	void BuildBase(){ p.SetBase("Base B"); }	
};

class Director{
	Builder* builder;
	public:
	Director() {}

	void SetBuilder(Builder* builder){ this->builder = builder; }
	void ConstructProduct(){
		builder->BuildOption();
		builder->BuildBase();
	}
	
	Product GetProduct(){ return builder->GetProduct(); }
};

int main(){
	Director director;
	ConcreteBuilderA cbA;
	ConcreteBuilderB cbB;

	director.SetBuilder(&cbA);
	director.ConstructProduct();

	director.GetProduct().Print();

	director.SetBuilder(&cbB);
	director.ConstructProduct();

	director.GetProduct().Print();

	return 0;
}
