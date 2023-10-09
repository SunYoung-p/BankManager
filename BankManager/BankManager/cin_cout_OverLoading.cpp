#include <iostream>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y)
	{}
	void ShowInfo()
	{
		cout << "x: " << x << ", y: " << y << endl;
	}

	friend istream& operator >> (istream& in, Point& p);
	friend ostream& operator<<(ostream& out, const Point& p);

};

istream& operator >> (istream& in, Point& p)
{
	cout << "x: ";
	in >> p.x;
	cout << "y: ";
	in >> p.y;

	return in;
}

ostream& operator<<(ostream& out, const Point& p)
{
	out << "x: " << p.x << ", y: " << p.y << endl;

	return out;
}

int cin_cout_OverLoading()
{
	Point p1(2, 5);

	std::cout << p1;

	cout << endl;

	std::cin >> p1;
	std::cout << p1;

	int a;

	cin >> a;
	cout << a << endl;

	return 0;
}