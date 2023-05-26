#include "graph.h"


void PairOfStLine::specialCurve(RenderWindow& window, graph gr, int n) {
	float a = gr.coeff_of_x2;
	float b = gr.coeff_of_y2;
	float h = (gr.coeff_of_xy) / 2;
	float g = (gr.coeff_of_x) / 2;
	float f = (gr.coeff_of_y) / 2;
	float c = gr.constant;

	a /= b;
	b /= b;
	c /= b;
	g /= b;
	f /= b;
	h /= b;

	if ((((h * h) - (a * b)) >= 0) && (((f * f) - c) >= 0)) {
		m1 = ((-h) + sqrt((h * h) - a));
		m2 = ((-h) - sqrt((h * h) - a));
		c1 = ((-f) + sqrt((f * f) - c));
		c2 = ((-f) - sqrt((f * f) - c));
		
		StLine(window, m1, c1, n);
		StLine(window, m2, c2, n);
	}
}