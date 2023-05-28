#include "graph.h"




void Circle::specialCurve(sf::RenderWindow& window, graph gr, int n) {
	float a = gr.coeff_of_x2;
	float b = gr.coeff_of_y2;
	float c = gr.constant;
	float g = (gr.coeff_of_x)/2.0;
	float f = (gr.coeff_of_y)/2.0;
	float h = (gr.coeff_of_xy)/2.0;

	xmax = (window.getSize().y);
	ymax = (window.getSize().y);
	center_x = xmax / 2;
	center_y = ymax / 2;

	// radius of the circle
	radius = sqrtf((g * g) + (f * f) - c);

	//cout << "Radius = " << radius << endl;

	center_of_circle_x = -g;// to find the center of the circle
	center_of_circle_y = -f;

	//cout << "Here : center_x = " << center_x << endl;

	float x = ((center_of_circle_x * n) + center_x);
	float y = (-((center_of_circle_y * n) - center_y));

	
	CircleShape circle(radius*n, 100);
	circle.setFillColor(Color::Transparent);
	circle.setPosition((x - (radius * n)), (y - (radius * n)));
	circle.setOutlineColor(Color::Red);
	circle.setOutlineThickness(2.f);
	window.draw(circle);
	//cout << "(" << circle.getPosition().x << " , " << circle.getPosition().y << ")" << endl;
}
