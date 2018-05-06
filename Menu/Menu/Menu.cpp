#include "Menu.hpp"

Menu::Menu(int sizeX, int sizeY)
{

	if (!font.loadFromFile("upheavtt.ttf"))
	{

	}
	this->selectedInedx = 0;

	for (int i = 0; i < MENU_COUNT_INDEX; i++)
	{
		menu[i].setCharacterSize(20);
		menu[i].setFont(font);
		menu[i].setFillColor(sf::Color::White);
		menu[i].setPosition(sizeX / 2, sizeY / (MENU_COUNT_INDEX + 1) * i);
		menu[i].setString(menuOptions[0][i]);
	}
	menu[0].setFillColor(sf::Color::Red);
}

Menu::~Menu()
{
}

void Menu::update(float dt, sf::RenderTarget & target)
{
	//menuTimeElaepd = +dt;
	//if (menuTimeElaepd >= menuTime)
	//{
	//	menuTimeElaepd = 0;
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	//{
	//	moveUp();
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	//{
	//	moveDown();
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	//{
	//	getSelectedMenu();
	//	if (getSelectedMenu() == 1)
	//	{
	//		//play
	//	}
	//	else if (getSelectedMenu() == 2)
	//	{
	//		//options
	//	}
	//	else if (getSelectedMenu() == 3)
	//	{
	//		//exit
	//	}
	//}
	//}
}

void Menu::moveUp()
{
	if (selectedInedx - 1 >= 0)
	{
		menu[selectedInedx].setFillColor(sf::Color::White);
		selectedInedx--;
		menu[selectedInedx].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()
{
	if (selectedInedx + 1 < MENU_COUNT_INDEX)
	{
		menu[selectedInedx].setFillColor(sf::Color::White);
		selectedInedx++;
		menu[selectedInedx].setFillColor(sf::Color::Red);
	}
}

int Menu::getSelectedMenu()
{
	return this->selectedInedx;
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i < MENU_COUNT_INDEX; i++)
	{
		target.draw(menu[i]);
	}
}
