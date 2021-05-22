#include <iostream>

class Window{
};

template<class Base> class Animated: public Base{
	public:
		void Play(){
			std::cout << "Play Window\n";
		};
};

template<class Base> class Scrollable: public Base{
	public:
		void ScrollUp(){
			std::cout << "ScrollUp Window\n";
		};
		void ScrollDown(){
			std::cout << "ScrollDown Window\n";
		};
};

template<class Base> class Dockable: public Base{
	public:
		void Dock() {
			std::cout << "Dock Window\n";
		};
		void Undock() {
			std::cout << "Undock Window\n";
		};
};

using AnimatedWindow = Animated<Window>;
using ScrollableWindow = Scrollable<Window>;
using PerfectWindow = Dockable<Scrollable<Animated<Window>>>;

int main(){
	AnimatedWindow aw;
	aw.Play();

	PerfectWindow pw;
	pw.Dock();
	pw.ScrollUp();
	pw.Play();
	return 0;
}

