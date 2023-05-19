#include "graph.h"


void  graph::DrawBoundry(RenderWindow& window)
{
	//Boundy of Left X
	Vertex left_x_boundry[] = {Vertex(Vector2f(0, ymax), Color::Blue), Vertex(Vector2f(xmax, ymax), Color::Blue)};
	window.draw(left_x_boundry, 2, Lines);

	//Boundy of Left X
	Vertex right_x_boundry[] = { Vertex(Vector2f(0, 0), Color::Blue), Vertex(Vector2f(0, ymax), Color::Blue) };
	window.draw(right_x_boundry, 2, Lines);

	//Boundry of Lower Y
	Vertex lower_y_boundry[] = {Vertex(Vector2f(xmax, 0), Color::Blue), Vertex(Vector2f(xmax, ymax), Color::Blue)};
	window.draw(lower_y_boundry, 2, Lines);
	//Boundry of Upper Y
	Vertex upper_y_boundry[] = { Vertex(Vector2f(0, 0), Color::Blue), Vertex(Vector2f(xmax, 0), Color::Blue) };
	window.draw(upper_y_boundry, 2, Lines);
}



//The main curve of the equation
void graph::drawCurve(RenderWindow & window, graph gr) {
	Curve* Curve_ptr;
	if (t == Equation::t_StLine)
		Curve_ptr = new StLine;
	else if (t == Equation::t_PairOfStLine)
		Curve_ptr = new PairOfStLine;
	else if (t == Equation::t_Parabola)
		Curve_ptr = new Parabola;
	else if (t == Equation::t_Ellipse) 
		Curve_ptr = new Ellipse;
	else if (t == Equation::t_Circle)
		Curve_ptr = new Circle;
	else if (t == Equation::t_Hyperbola)
		Curve_ptr = new Hyperbola;
	else
		Curve_ptr = new RectHyperbola;
	Curve_ptr->specialCurve(window, gr);
	delete Curve_ptr;
}

void graph::DrawAxis(RenderWindow& window) {
	//For X-Axis
	Vertex x_axis[] = {Vector2f(0, center_y), Vector2f(xmax, center_y)};
	window.draw(x_axis, 2, Lines);

	//For Y-Axis
	Vertex y_axis[] = {Vector2f(center_x, 0), Vector2f(center_x, ymax)};
	window.draw(y_axis, 2, Lines);
}

void graph::drawGraph(RenderWindow& window, graph gr) {
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;



	DrawBoundry(window); // To draw the boundry lines of the drawing area
	DrawAxis(window); // To draw the major axis of the 
	drawCurve(window, gr);

}
