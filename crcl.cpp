#include <iostream>
#include <vector>
#include<math.h>
#include"crcl.h"

void ccircle::PrintInfo()
{
	std::vector <Point>::iterator Iter;
	std::cout << std::endl;
	std::cout << "����� ����������: (" << a << "; " << b << ")" << std::endl;
	std::cout << "������ ���������� = " << r << std::endl;
	std::cout << "���������� \"���������\" �����:" << std::endl;
	for (Iter = points.begin(); Iter != points.end(); Iter++) //����� ������� ��������� �����
		std::cout << "(" << (*Iter).x << "; " << (*Iter).y << ");   ";
	std::cout << std::endl;
};


bool ccircle::AddPoint(Point p)

{
	std::vector <Point>::iterator Iter;
	for (Iter = points.begin(); Iter != points.end(); Iter++) //���������, ��� �� ����������� ����� � ������ ���������

		if (Iter->x == p.x && Iter->y == p.y) return(false);

	points.push_back(p);//��������� ����� � ������
	return true;
};



ccircle ccircle::operator-(const ccircle &c)
{
	ccircle res;
	float k1, k2, k3, C, d;
	float x1, y1, a1, b1;

	if (a == c.a && b == c.b && r == c.r) return(res); //���������, �� ��������� �� ����������
	a1 = c.a - a; //���������� ����� ����� �� ����������� � ������ ���������
	b1 = c.b - b;

	//������ ������� ���������� ��������� ���� ����������
	C = (c.r*c.r - r * r - a1 * a1 - b1 * b1) / (-2);

	if (a1 == 0)//������, ����� ������ ����������� ����� �� ����� ������
	{
		C = C / b1;
		if (r*r - C * C < 0) return(res);
		res.AddPoint(Point(sqrt(r*r - C) + a, C + b));//��������� ��������� ����� � ������ ����������
		res.AddPoint(Point(-sqrt(r*r - C) + a, C + b));
		res.a = a;
		res.b = b;
		res.r = r;
		return(res);
	}



	k1 = (1 + b1 * b1 / (a1 * a1));
	k2 = -2 * b1*C / a1; //-
	if (a1 < 0) k2 = -k2;
	k3 = C * C / (a1*a1) - r * r;
	d = k2 * k2 - 4 * k1*k3;
	if (d < 0) return(res);
	y1 = (-k2 + sqrt(d)) / (2 * k1);
	x1 = (C - b1 * y1) / a1;
	res.AddPoint(Point(x1 + a, y1 + b));//��������� ��������� ����� � ������ ����������
	y1 = (-k2 - sqrt(d)) / (2 * k1);
	x1 = (C - b1 * y1) / a1;
	res.AddPoint(Point(x1 + a, y1 + b));//��������� ��������� ����� � ������ ����������
	res.a = a;
	res.b = b;
	res.r = r;
	return(res);


};


ccircle ccircle::operator-()
{
	ccircle res;
	this->a = -this->a;
	this->b = -this->b;
	std::vector <Point>::iterator Iter;
	for (Iter = points.begin(); Iter != points.end(); Iter++) //���������� ��������� ����� ������������ ����
		res.AddPoint(Point(-(*Iter).x, -(*Iter).y));
	res.r = this->r;
	res.a = this->a;
	res.b = this->b;

	return(res);
};