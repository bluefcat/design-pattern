#include <iostream>
#include <string>
#include <map>

typedef uint32_t key;

class User{
	public:
		User(const std::string& first_name, const std::string& last_name)
			:first_name_(Add(first_name)), last_name_(Add(last_name)){
		}

		const std::string& GetFirstName() const{
			return names.find(first_name_)->second;
		}

		const std::string& GetLastName() const{
			return names.find(last_name_)->second;
		}

		friend std::ostream& operator<<(std::ostream& os, const User& obj){
			return os << "(first name, last name): " << obj.GetFirstName() << " " << obj.GetLastName();
		}
	protected:
		static key Add(const std::string& s){
			auto itr = names.begin();
			for(itr; itr != names.end(); ++ itr){
				if(itr->second == s) break;
			}
			if(itr != names.end()) return itr->first;

			key id = ++seed;
			names.insert(std::pair<key, std::string>(seed, s));
			
			return id;
		}

	protected:
		static std::map<key, std::string> names;
		static key seed;

		key first_name_, last_name_;
};

key User::seed = 0;
std::map<key, std::string> User::names{};

int main(){
	User user1("John", "Kim");
	User user2("Jane", "Kim");

	std::cout << user1 << std::endl;
	std::cout << user2 << std::endl;

	return 0;
}
