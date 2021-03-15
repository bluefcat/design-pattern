#include <iostream>

class Iterator{
	public:
		virtual int First() = 0;
		virtual int Next() = 0;
		virtual int IsDone() = 0;
		virtual int CurrentItem() = 0;
};

class Aggregate{
	public:
		//virtual Iterator* CreateIterator() = 0;
};

class ConcreteAggregate: public Aggregate{
	private:
		int items[10];
	
	public:
		int Count(){
			return 10;
		}

		void SetItem(int index, int item){
			items[index] = item;
		}

		int GetItem(int index){
			return items[index];
		}
};

class ConcreteIterator: public Iterator{
	private:
		ConcreteAggregate* aggregate;
		int current = 0;

	public:
		ConcreteIterator(ConcreteAggregate* aggregate){
			this->aggregate = aggregate;
		}

		int First(){
			return aggregate->GetItem(0);
		}

		int Next(){
			int result = 0;
			if(current < aggregate->Count()){
				result = aggregate->GetItem(++current);
			}
			return result;
		}

		int IsDone(){
			return current >= aggregate->Count();
		}

		int CurrentItem(){
			return aggregate->GetItem(current);
		}
};


int main(){
	ConcreteAggregate a;
	for(int i = 0; i < 10; i ++){
		a.SetItem(i, 2*i);
	}

	ConcreteIterator i(&a);

	std::cout << "Iterating over collection:\n";
	while(i.IsDone() != true){
		std::cout << i.CurrentItem() << "\n";
		i.Next();
	}

	return 0;
}
