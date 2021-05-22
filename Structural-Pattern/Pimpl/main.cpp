#include "person.h"

int main(){
	Person p;
	p.name = "James";
	(p.impl)->greet(&p);

	return 0;
}
