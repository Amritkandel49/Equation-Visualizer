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

void Parabola::specialCurve(RenderWindow& window, graph gr) {
	int n = 100;
	ymax = window.getSize().x;
	xmax = ymax;
	int numPoints = 100;

	center_x = xmax / 2;
	center_y = ymax / 2;

	VertexArray parabola(LineStrip);


	if (gr.coeff_of_y2 == 0) {//for y = ax^2 + bx + c
		a = gr.coeff_of_x2;
		b = gr.coeff_of_x;
		c = gr.constant;
		

		for (int i = 0; i <= numPoints; i++)
		{
			float t = static_cast<float>(i) / numPoints;
			float x = convert_x_pixel_to_unit(t * xmax, n, center_x, center_y);
			float y = a * x * x + b * x + c;


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_y_unit_to_pixel(y, n, center_x, center_y);
			if (y >= 0 && y <= ymax)
			{
				parabola.append(Vertex(Vector2f(x,y), Color::Red));
			}
		}

	}
	else if (gr.coeff_of_x2 == 0) {//for x = ay^2 + by + c
		a = gr.coeff_of_y2;
		b = gr.coeff_of_y;
		c = gr.constant;

		for (int i = 0; i <= numPoints; i++)
		{
			float t = static_cast<float>(i) / numPoints;
			float y = convert_x_pixel_to_unit(t * ymax, n, center_x, center_y);
			float x = a * y * y + b * y + c;


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_y_unit_to_pixel(y, n, center_x, center_y);
			if (x >= 0 && y <= ymax)
			{
				parabola.append(Vertex(Vector2f(x, y), Color::Red));
			}
		}
	}
	window.draw(parabola);
}