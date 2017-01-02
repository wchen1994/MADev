#include<SFML/Graphics.hpp>

class GameObject{
protected:
	sf::Vector2<float> position;
	sf::Vector2<float> velocity;
	sf::RenderWindow *wnd;
public:
	GameObject(sf::RenderWindow *wnd);
	~GameObject();
	virtual void Draw();
	virtual void Update();
};
