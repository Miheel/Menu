#include <windows.h>
#include <SFML\Graphics.hpp>
#include "Menu.hpp"
#include "Player.hpp"
const int winx = 1280, winy = 720;

int __stdcall WINAPI WinMain(HINSTANCE hInstance,		// HANDLE TO AN INSTANCE.  This is the "handle" to YOUR PROGRAM ITSELF.
	HINSTANCE hPrevInstance,							// USELESS on modern windows (totally ignore hPrevInstance)
	LPSTR szCmdLine,									// Command line arguments.  similar to argv in standard C programs
	int iCmdShow)										// Start window maximized, minimized, etc.
{
	sf::RenderWindow window(sf::VideoMode(winx, winy), "");
	window.setFramerateLimit(60);
	sf::Clock gameTime;
	int play = 0;
	Menu menu(window.getSize().x, window.getSize().y);
	Player player;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveUp();
					break;
				case sf::Keyboard::Down:
					menu.moveDown();
					break;
				case sf::Keyboard::Escape:
					play = player.getPlayingStatus();
					break;
				case sf::Keyboard::Return:
					switch (menu.getSelectedMenu())
					{
					case 0:
						play = 1; //play
						break;
					case 1:
						play = 2;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			}

		}
		if (play == 0)
		{
			menu.update(gameTime.restart().asSeconds(), window);

			window.clear();

			window.draw(menu);
		}
		else if (play == 1)
		{
			player.update(gameTime.restart().asSeconds(), window);

			window.clear();

			window.draw(player);
		}
		window.display();
	}
	return 0;
}