#include <vector>


class Point {
public:
	float x, y; //координаты точки
				
	Point() { x = 0; y = 0; };
	Point(float x, float y) { this->x = x; this->y = y; };
	~Point() {};
};






class ccircle {
private:
	float r; //радиус
	float a, b; //координаты центра

public:
	std::vector <Point> points; //вектор с точками, которые выкалываются после нахождения несимметрической разности
								
	ccircle() {
		r = 0; a = 0; b = 0;
	};
	ccircle(float a, float b, float r) { this->a = a; this->b = b; this->r = r; };
	~ccircle() {};

	//доступ к полям (чтение)
	float geta() { return a; };
	float getb() { return b; };
	float getr() { return r; };

	
	void PrintInfo();

	//добавление точки в список "выколотых"
	bool AddPoint(Point);

	//несимметрическая разность
	ccircle operator-(const ccircle &c);
	//отображение относительно осей
	ccircle operator-();

};



