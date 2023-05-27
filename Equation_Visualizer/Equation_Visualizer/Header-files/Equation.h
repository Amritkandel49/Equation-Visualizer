#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <map>


class Equation
{
private:
	void analyze();
protected:
	enum type { t_StLine, t_PairOfStLine, t_Parabola, t_Circle, t_Ellipse, t_Hyperbola, t_RectHyperbola } t;
	std::string equation;
public:
	float coeff_of_x2, coeff_of_y2, coeff_of_xy, coeff_of_x, coeff_of_y, constant;

	//void readEquation();


	void readEquation();
};

