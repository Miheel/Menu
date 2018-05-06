#include "SFML\Graphics.hpp"
class Player :public sf::Drawable
{
public:
	Player();
	~Player();
	void update(float dt, sf::RenderTarget &target);
	void setplayingStatus(int play);
	int getPlayingStatus();
private:
	void draw(sf::RenderTarget &target, sf::RenderStates states)const;
	float move = 180.0f;
	int play;
	sf::RectangleShape rect;
};