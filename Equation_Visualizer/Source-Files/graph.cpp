#include "graph.h"

inline float convert_y_pixel_to_unit(float  y, int n, float center_x, float center_y) {

	return ((-y + center_y) / n);
}

inline float convert_x_pixel_to_unit(float x, int n, float center_x, float center_y) {
	return (((x - center_x)) / n);
}

inline float convert_x_unit_to_pixel(float x, int n, float center_x, float center_y) {
	return ((x * n) + center_x);
}

inline float convert_y_unit_to_pixel(float y, int n, float center_x, float center_y) {
	return (-((y * n) - center_y));
}

void  graph::DrawBoundry(RenderWindow& window)
{
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;
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


void graph::DrawVerticalLines(RenderWindow& window, graph gr, int n) {
	//float x_min = convert_x_pixel_to_unit(0, n, center_x, center_y);
	//float x_xmax = convert_x_pixel_to_unit(gr.xmax, n, center_x, center_y);
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;

	for (int ix = ((int)(convert_x_pixel_to_unit(0, n, center_x, center_y))); ix < ((int)convert_x_pixel_to_unit(xmax, n, center_x, center_y)); ix++) {
		VertexArray line1(LineStrip);
		if (ix <= xmax) {
			line1.append(Vertex(Vector2f(convert_x_unit_to_pixel(ix, n, center_x, center_y), 0), Color(128, 128, 128)));
			line1.append(Vertex(Vector2f(convert_x_unit_to_pixel(ix, n, center_x, center_y), ymax), Color(128, 128, 128)));
		}
		window.draw(line1);
	}
}

void graph::DrawHorizontalLines(RenderWindow& window, graph, int n) {
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;
	for (int iy = (static_cast<int>(-center_y / n)); iy < ((int)(center_y/n)); iy++) {
		VertexArray line2(Lines);
		line2.append(Vertex(Vector2f( 0, convert_y_unit_to_pixel(iy, n, center_x, center_y)), Color(128, 128, 128)));
		line2.append(Vertex(Vector2f( xmax, convert_y_unit_to_pixel(iy, n, center_x, center_y)), Color(128, 128, 128)));
		window.draw(line2);
	}
}


//The main curve of the equation
void graph::drawCurve(RenderWindow & window, graph gr, int n) {
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
	Curve_ptr->specialCurve(window, gr, n);
	delete Curve_ptr;
}

void graph::DrawAxis(RenderWindow& window, graph gr, int n) {
	//For X-Axis
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;
	VertexArray x_axis(Lines);
	x_axis.append(Vertex(Vector2f(0, gr.center_y), Color::Magenta));
	x_axis.append(Vertex(Vector2f(gr.xmax, gr.center_y), Color::Magenta));
	window.draw(x_axis);

	//For Y-Axis
	VertexArray y_axis(Lines);
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;
	y_axis.append(Vertex(Vector2f(gr.center_x, 0), Color::Magenta));
	y_axis.append(Vertex(Vector2f(gr.center_x, gr.ymax), Color::Magenta));
	window.draw(y_axis);
}

void graph::drawGraph(RenderWindow& window, graph gr, int n) {
	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;



	DrawBoundry(window); // To draw the boundry lines of the drawing area
	DrawHorizontalLines(window, gr, n);
	DrawVerticalLines(window, gr, n);
	DrawAxis(window, gr, n); // To draw the major axis of the 
	drawCurve(window, gr, n);

}
