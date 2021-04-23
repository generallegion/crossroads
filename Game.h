#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <list>

const int window_w = 800;
const int window_h = 800;
const int framerame_limit = 60;

void game();

class CrossRoad
{
private:
	
	class Cars;
	class Traffic_Lights;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	CrossRoad();
	~CrossRoad();
	sf::Sprite update() {
		texture.loadFromFile("img/Crossroad(1).png");

		sprite.setTexture(texture);

		return sprite;
	}

};

CrossRoad::CrossRoad()
{
	
	

}

CrossRoad::~CrossRoad()
{
}

class Cars : CrossRoad
{
public:
	Cars();
	~Cars();

private:
	sf::Texture texture;
	int car_number;

};

Cars::Cars()
{
}

Cars::~Cars()
{
}

 

class Traffic_Lights : CrossRoad
{
public:
	Traffic_Lights();
	~Traffic_Lights();
	void change_light() { //����� ����� ���������
		time1 = clock.getElapsedTime();
		if (time1.asSeconds() > 5) {  //������ 5 ������ ������ ����
			std::cout << "������ 5 ������, ������ ���� ���������!" << std::endl;
			clock.restart();
			color = (color == lights_color::GREEN) ? lights_color::RED : lights_color::GREEN;
			std::cout << (color == lights_color::GREEN ? "GREEN" : "RED") << std::endl;
		} 

		//std::cout << time1.asSeconds()<<std::endl;  //������ ������� � �������
	}

private:
	enum class lights_color {RED, GREEN}; // ������������� ��� ����� ����� ���������
	lights_color color;
	sf::Clock clock; //��������� ������ ��� ����� �����
	sf::Time time1; 

};

Traffic_Lights::Traffic_Lights()
{
	lights_color color = lights_color::RED;
	std::cout << "RED" << std::endl;

	
}

Traffic_Lights::~Traffic_Lights()
{
}


