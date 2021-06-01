#include <vector>


class Point {
public:
	float x, y; //���������� �����
				
	Point() { x = 0; y = 0; };
	Point(float x, float y) { this->x = x; this->y = y; };
	~Point() {};
};






class ccircle {
private:
	float r; //������
	float a, b; //���������� ������

public:
	std::vector <Point> points; //������ � �������, ������� ������������ ����� ���������� ���������������� ��������
								
	ccircle() {
		r = 0; a = 0; b = 0;
	};
	ccircle(float a, float b, float r) { this->a = a; this->b = b; this->r = r; };
	~ccircle() {};

	//������ � ����� (������)
	float geta() { return a; };
	float getb() { return b; };
	float getr() { return r; };

	
	void PrintInfo();

	//���������� ����� � ������ "���������"
	bool AddPoint(Point);

	//���������������� ��������
	ccircle operator-(const ccircle &c);
	//����������� ������������ ����
	ccircle operator-();

};



