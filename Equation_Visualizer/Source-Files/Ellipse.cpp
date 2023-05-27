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



void Ellipse::specialCurve(RenderWindow& window, graph gr, int n){
	center_x = (window.getSize().y / 2);
	center_y = (window.getSize().y / 2);

	b = sqrt(gr.coeff_of_x2);
	a = sqrt(gr.coeff_of_y2);
	h = (gr.coeff_of_x / (2 * gr.coeff_of_x2));
	k = (gr.coeff_of_y / (2 * gr.coeff_of_y2));


	// converting units to pixels
	h = ((h * n) + graph::center_x);
	k = (-((k * n) - graph::center_y));

	float rotationAngle = atan(gr.coeff_of_xy / (gr.coeff_of_x - gr.coeff_of_y));
	
	int numPoints = 150; // Number of points to approximate the ellipse

	sf::VertexArray ellipse(sf::LineStrip);
	ellipse.setPrimitiveType(sf::LineStrip);
	

	// Calculate the points of the ellipse
	for (int i = 0; i <= numPoints; ++i) {
		float angle = 2.f * PI * i / numPoints;
		float x = h + (a*n * std::cos(angle));
		float y = k + (b * n * std::sin(angle));


		ellipse.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Red));
	}

	window.draw(ellipse);
}