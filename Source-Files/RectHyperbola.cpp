#include "graph.h"

float RectHyperbola ::convert_y_pixel_to_unit(float  y, int n) {
	return (((float)-y + graph::center_y) / n);
}

float RectHyperbola ::convert_x_pixel_to_unit(float x, int n) {
	return (((float)(x - graph::center_x)) / n);
}

float RectHyperbola ::convert_x_unit_to_pixel(float x, int n) {
	return ((x * n) + graph::center_x);
}

float RectHyperbola ::convert_y_unit_to_pixel(float y, int n) {
	return (-((y * n) - graph::center_y));
}