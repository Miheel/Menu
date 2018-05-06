#include "Player.hpp"
#pragma once

Player::Player()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setFillColor(sf::Color::White);
	rect.setPosition(100, 100);
	play = 1;
}

Player::~Player()
{
}

void Player::update(float dt, sf::RenderTarget & target)
{
	sf::Vector2f direction(0.0f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		direction.x = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		direction.x = 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		direction.y = -1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		direction.y = 1.0f;
	}
	rect.move(move*direction*dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
	{
		setplayingStatus(0);
	}
}

void Player::setplayingStatus(int play)
{
	this->play = play;
}

int Player::getPlayingStatus()
{
	return play;
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect, states);
}
