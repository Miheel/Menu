#ifndef MENU_H
#define MENU_H
#define MENU_COUNT_INDEX 3
#include "SFML/Graphics.hpp"
class Menu :public sf::Drawable
{
public:
	Menu(int sizeX, int sizeY);
	~Menu();
	void update(float dt, sf::RenderTarget &target);
	void moveUp();
	void moveDown();
	int getSelectedMenu();

private:
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	int selectedIndex;
	float sizeX;
	float sizeY;
	float menuTime = 0.5f;
	float menuTimeElapsed;

	sf::Font font;
	sf::Text menu[MENU_COUNT_INDEX];
	std::string menuOptions[1][MENU_COUNT_INDEX] = { "play", "Options", "Exit" };
};
#endif // !MENU_H
