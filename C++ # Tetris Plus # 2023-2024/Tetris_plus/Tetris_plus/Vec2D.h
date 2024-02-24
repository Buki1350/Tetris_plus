#pragma once
class Vec2D
{
public:
	float x, y;

	Vec2D(float x = 0.0f, float y = 0.0f);

	const bool operator==(const Vec2D& otherVector)
	{
		if (x == otherVector.x && y == otherVector.y)
			return true;
		else
			return false;
	}

	const bool operator!=(const Vec2D& otherVector)
	{
		if (x == otherVector.x && y == otherVector.y)
			return false;
		else
			return true;
	}

	const Vec2D operator+(const Vec2D& otherVector)
	{
		return Vec2D(x + otherVector.x, y + otherVector.y);
	}

	const Vec2D operator-(const Vec2D& otherVector)
	{
		return Vec2D(x - otherVector.x, y - otherVector.y);
	}

	const Vec2D operator+=(const Vec2D& otherVector)
	{
		x += otherVector.x;
		y += otherVector.y;
		return *this;
	}

	const Vec2D operator-=(const Vec2D& otherVector)
	{
		x -= otherVector.x;
		y -= otherVector.y;
		return *this;
	}
};

class Vec2Di
{
public:
	int x, y;

	Vec2Di(int x = 0.0f, int y = 0.0f);

	const bool operator==(const Vec2Di& otherVector)
	{
		if (x == otherVector.x && y == otherVector.y)
			return true;
		else
			return false;
	}

	const bool operator!=(const Vec2Di& otherVector)
	{
		if (x == otherVector.x && y == otherVector.y)
			return false;
		else
			return true;
	}

	const Vec2Di operator+(const Vec2Di& otherVector)
	{
		return Vec2Di(x + otherVector.x, y + otherVector.y);
	}

	const Vec2Di operator-(const Vec2Di& otherVector)
	{
		return Vec2Di(x - otherVector.x, y - otherVector.y);
	}

	const Vec2Di operator+=(const Vec2Di& otherVector)
	{
		x += otherVector.x;
		y += otherVector.y;
		return *this;
	}

	const Vec2Di operator-=(const Vec2Di& otherVector)
	{
		x -= otherVector.x;
		y -= otherVector.y;
		return *this;
	}
};