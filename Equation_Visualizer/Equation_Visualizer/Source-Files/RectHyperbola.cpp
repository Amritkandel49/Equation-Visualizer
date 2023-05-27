#include "graph.h"
#include <conio.h>


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

inline float sec(float angle) {
	return (1 / cos(angle));
}

void RectHyperbola::specialCurve(RenderWindow& window, graph gr, int n) {
	int numPoints = 400; // Number of points to approximate the hyperbola
	ymax = window.getSize().y;
	xmax = ymax;

	center_x = xmax / 2;
	center_y = ymax / 2;

	if (gr.coeff_of_x2 < 0) {
		gr.coeff_of_x2 *= -1;
		gr.coeff_of_xy *= -1;
		gr.coeff_of_y2 *= -1;
		gr.coeff_of_x *= -1;
		gr.coeff_of_y *= -1;
		gr.constant *= -1;
	}


	b = sqrt(gr.coeff_of_x2);
	a = sqrt(-gr.coeff_of_y2);
	h = -gr.coeff_of_x / (2 * gr.coeff_of_x2);
	k = gr.coeff_of_y / (2 / (-gr.coeff_of_y2));

	float rotationAngle = 0.5 * atan(gr.coeff_of_xy / (gr.coeff_of_x2 - gr.coeff_of_y2));

	float start = convert_x_pixel_to_unit(0, n, center_x, center_y);
	float end = convert_x_pixel_to_unit(xmax, n, center_x, center_y);


	VertexArray hyperbola1(LineStrip);
	VertexArray hyperbola2(LineStrip);
	VertexArray hyperbola3(LineStrip);
	VertexArray hyperbola4(LineStrip);



	// Calculate the points of the hyperbola
	if (gr.constant == ((b * b * h * h) - (a * a * k * k) - (a * a * b * b))) {
		for (float i = 0; i <= ((numPoints) / 4); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = (h + a * sec(angle));
			float y = (k + b * tan(angle));
			x = (x)*cos(rotationAngle) - (y)*sin(rotationAngle);
			y = (x)*sin(rotationAngle) + (y)*cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola1.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = ((numPoints / 4) + 1); i <= 2 * (numPoints) / 4; i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = (h + a * sec(angle));
			float y = (k + b * tan(angle));
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola2.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = ((numPoints) / 2) + 1; i <= (3 * (numPoints) / 4); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = (h + a * sec(angle));
			float y = (k + b * tan(angle));
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola3.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = (3 * (numPoints) / 4) + 1; i <= (numPoints); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = (h + a * sec(angle));
			float y = (k + b * tan(angle));
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola4.append(Vertex(Vector2f(x, y), Color::Red));


		}
	}
	else if (gr.constant == ((b * b * h * h) - (a * a * k * k) + (a * a * b * b))) {
		for (float i = 0; i <= ((numPoints) / 4); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = h + b * tan(angle);
			float y = k + a * sec(angle);
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola1.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = ((numPoints / 4) + 1); i <= 2 * (numPoints) / 4; i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = h + b * tan(angle);
			float y = k + a * sec(angle);
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola2.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = ((numPoints) / 2) + 1; i <= (3 * (numPoints) / 4); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = h + b * tan(angle);
			float y = k + a * sec(angle);
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola3.append(Vertex(Vector2f(x, y), Color::Red));


		}

		for (float i = (3 * (numPoints) / 4) + 1; i <= (numPoints); i++)
		{
			float angle = 2 * PI * i / numPoints;
			float x = h + b * tan(angle);
			float y = k + a * sec(angle);
			x = x * cos(rotationAngle) - y * sin(rotationAngle);
			y = x * sin(rotationAngle) + y * cos(rotationAngle);


			x = convert_x_unit_to_pixel(x, n, center_x, center_y);
			y = convert_x_unit_to_pixel(y, n, center_x, center_y);

			hyperbola4.append(Vertex(Vector2f(x, y), Color::Red));


		}
	}
	else {
		cout << "The Constant term of Hyperbola may be incorrect. Please re-enter after checking" << endl;
	}

	window.draw(hyperbola1);
	window.draw(hyperbola2);
	window.draw(hyperbola3);
	window.draw(hyperbola4);
}