
#include <iostream>
using namespace std;

class Rectangle
{
private:
	double width;
	double height;
public:
	Rectangle(double wid, double hei) : width(wid), height(hei)
	{
		if (wid < 0 || hei < 0)
			throw std::runtime_error("값이 0 이하 입니다.");
	}
	void ShowArea() const
	{
		cout << "가로 : " << width << ", 세로 : " << height << ", 넓이 : " << width*height << endl;
	}

	Rectangle operator+(const Rectangle& rect)
	{
		return Rectangle(width + rect.width, height + rect.height);
	}

	Rectangle operator-(const Rectangle& rect)
	{
		return Rectangle(width - rect.width, height - rect.height);
	}

	Rectangle operator*(const double& scalar)
	{
		return Rectangle(width *	 scalar, height * scalar);
	}
};

int OperatorOverLoading()
{
	try
	{
		Rectangle sample(-5, 6);
		Rectangle sample2(4, 2);

		sample.ShowArea();
		sample2.ShowArea();
		cout << endl;

		(sample + sample2).ShowArea();
		(sample - sample2).ShowArea();
		cout << endl;

		(sample * 0.5).ShowArea();
		(sample * 2.0).ShowArea();
	}
	catch (const std::exception& e)
	{
		cerr << "예외 발생 : " << e.what() << endl;
	}

	return 0;
}