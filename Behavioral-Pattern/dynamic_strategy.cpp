#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

using std::vector;
using std::ostringstream;
using std::runtime_error;

enum class OutputFormat{
	Markdown,
	HTML
};

class ListStrategy{
	public:
		virtual void AddListItem(ostringstream& oss, const std::string& item){};
		virtual void Start(ostringstream& oss) {};
		virtual void End(ostringstream& oss) {};
};


class HTMLListStrategy: public ListStrategy{
	public:
		HTMLListStrategy(){ }
		
		void Start(ostringstream& oss) override{
			oss << "<ul>" << std::endl;
		}

		void End(ostringstream& oss) override{
			oss << "</ul>" << std::endl;
		}

		void AddListItem(ostringstream& oss, const std::string& item) override{
			oss << "<li>" << item << "</li>" << std::endl;
		}
};

class MarkdownListStrategy: public ListStrategy{
	public:
		MarkdownListStrategy(){ }

		void AddListItem(ostringstream& oss, const std::string& item) override{
			oss << "*" << item << std::endl;
		}
};

class TextProcessor{
	public:
		void Clear(){
			oss_.str("");
			oss_.clear();
		}

		void AppendList(const vector<std::string> items){
			list_strategy_->Start(oss_);
			for(auto& item: items){
				list_strategy_->AddListItem(oss_, item);
			}
			list_strategy_->End(oss_);
		}

		void SetOutputFormat(const OutputFormat format){
			switch(format){
				case OutputFormat::Markdown:
					list_strategy_ = std::make_unique<MarkdownListStrategy>();
					break;
				case OutputFormat::HTML:
					list_strategy_ = std::make_unique<HTMLListStrategy>();
					break;
				default:
					throw runtime_error("Unspported strategy");
			}
		}
		std::string str() const { return oss_.str(); }

	private:
		ostringstream oss_;
		std::unique_ptr<ListStrategy> list_strategy_;
};

int main(){
	TextProcessor tp;
	tp.SetOutputFormat(OutputFormat::Markdown);
	tp.AppendList({"foo", "bar", "baz"});
	std::cout << tp.str() << "\n";

	tp.Clear();
	tp.SetOutputFormat(OutputFormat::HTML);
	tp.AppendList({"foo", "bar", "baz"});
	std::cout << tp.str() << "\n";

	return 0;
}
