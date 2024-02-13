#include <SFML/Graphics.hpp>
#include <iostream>



int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 450), "FUcking SFML IT Really works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) 
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) == true)
				{
					shape.move(-10.0f, 0.0f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) == true) 
				{
					shape.move(10.0f, 0.0f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == true)
				{
					shape.move(0.0f, -10.0f);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) == true)
				{
					shape.move(0.0f, +10.0f);
				}
				break;
			default:
				break;
			}
		}
		window.clear();
		window.draw(shape);
		window.display();
	}
	
}

