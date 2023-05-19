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


void StLine::specialCurve(RenderWindow& window, graph gr) {
    int n = 100;
    
    ymax = window.getSize().y;
    cout << ymax << endl;
    xmax = ymax;
    center_x = xmax / 2;
    center_y = ymax / 2;


    float a = gr.coeff_of_x;
    float b = gr.coeff_of_y;
    float c = gr.constant;

    float slope = -(a / b);
    float y_intercept = -(c / b);

    sf::VertexArray line(sf::Lines, 2); // Line segment with 2 vertices

    //The two points form the straight lines
    // but there are four possible points along the boundry among which two form line
    sf::Vector2f p1(convert_x_pixel_to_unit(0, n, center_x, center_y), ((slope * convert_x_pixel_to_unit(0, n, center_x, center_y)) + y_intercept));
    sf::Vector2f p2(convert_x_pixel_to_unit(xmax, n, center_x, center_y), (slope * convert_x_pixel_to_unit(xmax, n, center_x, center_y) + y_intercept));
    sf::Vector2f p3((convert_y_pixel_to_unit(0, n, center_x, center_y) - (y_intercept / slope)), convert_y_pixel_to_unit(0, n, center_x, center_y));
    sf::Vector2f p4((convert_y_pixel_to_unit(ymax, n, center_x, center_y) - y_intercept) / slope, convert_y_pixel_to_unit(ymax, n, center_x, center_y));


    //Againg we have to convert unit to pixel
    p1.x = convert_x_unit_to_pixel(p1.x, n, center_x, center_y);
    p1.y = convert_y_unit_to_pixel(p1.y, n, center_x, center_y);

    p2.x = convert_x_unit_to_pixel(p2.x, n, center_x, center_y);
    p2.y = convert_y_unit_to_pixel(p2.y, n, center_x, center_y);

    p3.x = convert_x_unit_to_pixel(p3.x, n, center_x, center_y);
    p3.y = convert_y_unit_to_pixel(p3.y, n, center_x, center_y);

    p4.x = convert_x_unit_to_pixel(p4.x, n, center_x, center_y);
    p4.y = convert_y_unit_to_pixel(p4.y, n, center_x, center_y);


    // Find the valid segment within the workspace
    sf::Vector2f start, end;
    if (p1.y >= 0 && p1.y <= ymax) {
    start = p1;
    }
    else if (p3.x >= 0 && p3.x <= xmax) {
        start = p3;
    }
    if (p2.y >= 0 && p2.y <= ymax) {
        end = p2;
    }
    else if (p4.x >= 0 && p4.x <= xmax) {
        end = p4;
    }

    line[0] = Vertex(start, Color::Red);
    line[1] = Vertex(end, Color::Red);
    

    window.draw(line);
}