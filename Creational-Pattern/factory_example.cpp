#include <iostream>
#include <cmath>

class Point{
	public:
		float x_, y_;
		friend class PointFactory;

		friend std::ostream& operator<<(std::ostream& os, const Point& p){
			return os << p.x_ << ", " << p.y_;
		}

	private:
		Point(float x, float y):x_(x), y_(y){}
};

class PointFactory{
	public:
		static Point NewCartesian(float x, float y){
			return Point{x, y};
		}

		static Point NewPolar(float r, float theta){
			return Point{ r*cos(theta), r*sin(theta) };
		}

};

int main(){
	PointFactory pf;

	std::cout << pf.NewCartesian(3.0, 5.2) << std::endl;
	std::cout << pf.NewPolar(3, 0.5) << std::endl;

	return 0;
}
