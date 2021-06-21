#include <iostream>
#include <string>

using std::string;

template <typename T>
class BinaryTree;

template <typename T>
class Node{
	public:
		T value_ = T();
		Node<T>* left_ = nullptr;
		Node<T>* right_ = nullptr;
		Node<T>* parent_ = nullptr;
		BinaryTree<T>* tree_ = nullptr;

		explicit Node(const T& value)
			:value_(value) {}

		Node(const T& value, Node<T>* const left, Node<T>* const right)
			:value_(value), left_(left), right_(right){
				left_->tree_ = right_->tree_ = tree_;
				left_->parent_ = right_->parent_ = this;
			}

		void SetTree(BinaryTree<T>* t){
			tree_ = t;
			if(left_) left_->SetTree(t);
			if(right_) right_->SetTree(t);
		}

		~Node(){
			if(left_) delete left_;
			if(right_) delete right_;
		}
};

template <typename T>
class BinaryTree{
	public:
		Node<T>* root_ = nullptr;

		explicit BinaryTree(Node<T>* const root)
			:root_ { root }{
			root->SetTree(this);
		}

		~BinaryTree(){
			if(root_) delete root_;
		}

		
		template <typename U>
		class PreOrderIterator{
			public:
				Node<U>* current_;

				explicit PreOrderIterator(Node<U>* current)
					:current_(current){}

				bool operator!=(const PreOrderIterator<U>& other){
					return current_ != other.current_;
				}

				PreOrderIterator<U>& operator++(){
					if(current_->right_){
						current_ = current_-> right_;
						while(current_->left_) current_ = current_->left_;
					}
					else{
						Node<T>* p = current_->parent_;
						while(p && current_ == p->right_){
							current_ = p;
							p = p->parent_;
						}
						current_ = p;
					}
					return *this;
				}

				Node<U>& operator*() {
					return *current_;
				}
		};

		using iterator = PreOrderIterator<T>;

		iterator end(){
			return iterator{nullptr};
		}

		iterator begin(){
			Node<T>* n = root_;

			if(n){
				while(n->left_) n = n->left_;
			}
			return iterator{n};
		}

};

int main(){
	BinaryTree<string> family{
		new Node<string>{"me",
			new Node<string>{"mother",
				new Node<string>{"mother's mother"},
				new Node<string>{"mother's father"}
			},
			new Node<string>{"father"}
		}
	};

	for(auto it = family.begin(); it != family.end(); ++it){
		std::cout << (*it).value_ << std::endl;
	}


	return 0;
}
