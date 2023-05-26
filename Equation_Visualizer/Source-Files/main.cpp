#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Equation.h"
#include "graph.h"


using namespace std;
using namespace sf;

int main() {
	//Equation eq;
	int n = 100;
	graph gr;
	RenderWindow window(VideoMode(900, 900), "Equaton Visualizer");
	window.setFramerateLimit(20);
	window.setPosition(Vector2i(0, 0));
	bool continueLoop = true;
	gr.readEquation();
	while (window.isOpen()) {
		//gr.readEquation();
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (n < 200)
				n += 10;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (n > 20)
				n -= 10;
		}

		if (Keyboard::isKeyPressed(Keyboard::N)) {
			gr.readEquation();
		}

		window.clear();

		if (continueLoop)
			gr.drawGraph(window, gr, n);


		window.display();
	}
	return 0;
}
