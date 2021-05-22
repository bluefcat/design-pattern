#include <iostream>
#include <string>

class Person{
	public:
		std::string name;

		class PersonImpl;
		PersonImpl* impl;

		Person();
		~Person();

		void greet();
};
