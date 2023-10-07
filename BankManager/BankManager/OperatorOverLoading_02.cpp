#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

	Point& operator++()
	{
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point& operator-()
	{
		xpos *= -1;
		ypos *= -1;
		return *this;
	}

	const Point operator++(int)
	{
		const Point refpos(xpos, ypos);
		xpos += 1;
		ypos += 1;
		return refpos;
	}

	friend Point& operator--(Point &ref);
	friend Point& operator~(Point &ref);
	friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref)
{
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point& operator~(Point &ref)
{
	ref.xpos = ~ref.xpos;
	ref.ypos = ~ref.ypos;

	return ref;
}

const Point operator--(Point& ref, int)
{
	const Point refpos(ref.xpos, ref.ypos);

	ref.xpos -= 1;
	ref.ypos -= 1;

	return refpos;
}

int OperatorOverLoading_02(void)
{
	Point pos(1, 2);
	++pos;
	pos.ShowPosition();
	--pos;
	pos.ShowPosition();

	++(++pos);
	pos.ShowPosition();
	--(--pos);
	pos.ShowPosition();

	Point pos2 = -pos;
	pos2.ShowPosition();

	Point pos3 = ~pos;
	pos3.ShowPosition();

	Point pos_(3, 5);
	Point cpy;

	cpy = pos_--;
	cpy.ShowPosition();
	pos_.ShowPosition();

	cpy = pos_++;
	cpy.ShowPosition();
	pos_.ShowPosition();

	return 0;
}