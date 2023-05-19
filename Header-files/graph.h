#pragma once
#include <SFML/Graphics.hpp>
#include "Equation.h"
#include <cmath>
#define PI 3.14159

using namespace std;
using namespace sf;



class graph : public Equation
{
private:
	void DrawAxis(RenderWindow& window);
	void DrawBoundry(RenderWindow& window);
	void drawCurve(RenderWindow& window, graph gr);

protected:

	float xmax, ymax, center_x, center_y;
	//void DrawVerticalLines(RenderWindow& window);
	//void DrawHorizontalLines(RenderWindow& window);
public:
	void drawGraph(RenderWindow& window, graph gr);

};




class Curve : public graph
{
public:
	virtual void specialCurve(sf::RenderWindow& window, graph gr) = 0;
};


class StLine : public Curve
{
public:
	void specialCurve(RenderWindow& window, graph gr);
};


class PairOfStLine : public Curve
{
private:
	float convert_y_pixel_to_unit(float  y, int n);
	float convert_x_pixel_to_unit(float x, int n);
	float convert_x_unit_to_pixel(float x, int n);
	float convert_y_unit_to_pixel(float y, int n);
public:
	void specialCurve(sf::RenderWindow& window, graph gr) {
		return;
	}
};


class Parabola : public Curve
{
private:
	float a, b, c;
	float focus;
	
public:
	void specialCurve(sf::RenderWindow& window, graph gr);
};


class Ellipse : public Curve
{
private:
	float a, b, h, k;
public:
	void specialCurve(sf::RenderWindow& window, graph gr);
};

class Circle : public Curve
{
private:
	float center_of_circle_x, center_of_circle_y, radius;
public:
	void specialCurve(sf::RenderWindow& window, graph gr);
};


class Hyperbola : public Curve
{
private:
	float a, b, c, h, k;
public:
	void specialCurve(sf::RenderWindow& window, graph gr);
};


class RectHyperbola : public Curve
{
private:
	float convert_y_pixel_to_unit(float  y, int n);
	float convert_x_pixel_to_unit(float x, int n);
	float convert_x_unit_to_pixel(float x, int n);
	float convert_y_unit_to_pixel(float y, int n);
public:
	void specialCurve(sf::RenderWindow& window, graph gr) {
		return;
	}
};
