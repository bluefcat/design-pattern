#include <iostream>

class Renderer{
	public:
		virtual void render_circle(float x, float y, float radius) = 0;
};

class VectorRenderer: public Renderer{
	void render_circle(float x, float y, float radius) override {
		std::cout << "Drawing a vector cicle of radius " << radius << std::endl;
	}
};

class Shape{
	protected:
		Renderer& renderer_;
		Shape(Renderer& renderer): renderer_{renderer} {}
	public:
		virtual void draw() = 0;
		virtual void resize(float factor) = 0;
};

class Circle: public Shape{
	public:
		Circle(Renderer& renderer, float x, float y, float radius)
			:Shape(renderer), x_(x), y_(y), radius_(radius){}
	
		void draw() override{
			renderer_.render_circle(x_, y_, radius_);
		}

		void resize(float factor) override{
			radius_ *= factor;
		}

	private:
		float x_, y_, radius_;
};

int main(){
	VectorRenderer vr;
	Circle c{vr, 5, 5, 5};

	c.draw();
	c.resize(2);
	c.draw();
	return 0;
}
