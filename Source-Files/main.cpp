#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Equation.h"
#include "graph.h"

using namespace std;
using namespace sf;

int main() {
	//Equation eq;
	graph g;
	RenderWindow window(VideoMode(900, 900), "Equaton Visualizer");
	window.setFramerateLimit(100);
	window.setPosition(Vector2i(0, 0));
	bool continueLoop = true;
	//g.readEquation();
	while (window.isOpen()) {
		g.readEquation();
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		window.clear();

		if (continueLoop)
			g.drawGraph(window, g);


		window.display();
	}
	return 0;
}
