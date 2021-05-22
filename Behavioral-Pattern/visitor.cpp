#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::ostringstream;

class Expression{
	public:
		virtual ~Expression() = default;
};

class DoubleExpression: public Expression{
	public:
		double value_;
		explicit DoubleExpression(const double value): value_(value){};
};

class AdditionExpression: public Expression{
	public:
		Expression *left_, *right_;

		AdditionExpression(Expression* const left, Expression* const right)
			:left_(left), right_(right){}

		~AdditionExpression(){
			delete left_;
			delete right_;
		}
};

class ExpressionPrinter{
	public:
		ostringstream oss;

		void Print(Expression* e){
			if(auto de = dynamic_cast<DoubleExpression*>(e)){
				oss << de->value_;
			}
			else if(auto ae = dynamic_cast<AdditionExpression*>(e)){
				oss << "(";
				Print(ae->left_);
				oss << "+";
				Print(ae->right_);
				oss << ")";
			}
		}

		string str() const { return oss.str(); }
};

int main(){
	auto e = new AdditionExpression{
		new DoubleExpression{ 1 },
		new AdditionExpression{
			new DoubleExpression{ 2 },
			new DoubleExpression{ 3 }
		}
	};
	ExpressionPrinter ep;
	ep.Print(e);

	std::cout << ep.str() << std::endl;
	
	return 0;
}
