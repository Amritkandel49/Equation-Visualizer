#pragma once
#include <SFML/Graphics.hpp>
#include "Equation.h"
#include <cmath>
#define PI 3.14159

using namespace std;
using namespace sf;

class Curve;

class graph : public Equation
{
private:
	void DrawAxis(RenderWindow& window, graph gr, int n);
	void DrawBoundry(RenderWindow& window);
	void drawCurve(RenderWindow& window, graph gr, int n);
	void DrawVerticalLines(RenderWindow& window, graph, int n);
	void DrawHorizontalLines(RenderWindow& window, graph, int n);

protected:

	float xmax, ymax, center_x, center_y, xmin, ymin;
	//void DrawVerticalLines(RenderWindow& window);
	//void DrawHorizontalLines(RenderWindow& window);
public:
	void drawGraph(RenderWindow& window, graph gr, int n);

};




class Curve : public graph
{
public:
	virtual void specialCurve(sf::RenderWindow& window, graph gr, int n) = 0;
};


class StLine : public Curve
{
public:
	StLine(){ }
	StLine(RenderWindow& window, float m, float c, int n);
	void specialCurve(RenderWindow& window, graph gr, int n);
};


class PairOfStLine : public Curve
{
private:
	float m1, c1, m2, c2;
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};


class Parabola : public Curve
{
private:
	float a, b, c;
	float focus;
	
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};


class Ellipse : public Curve
{
private:
	float a, b, h, k;
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};

class Circle : public Curve
{
private:
	float center_of_circle_x, center_of_circle_y, radius;
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};


class Hyperbola : public Curve
{
private:
	float a, b, c, h, k;
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};


class RectHyperbola : public Curve
{
private:
	float a, b, h, k;
public:
	void specialCurve(sf::RenderWindow& window, graph gr, int n);
};
