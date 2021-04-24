#include "SFML/Graphics.hpp"
#include <iostream>
#include <string>
#include <list>

const int window_w = 800;   //������ � ������ ����
const int window_h = 800;
const int framerame_limit = 60;   //����� ���
const sf::Vector2i centerMap(499, 499);  //����� �����, � ���� ����� ��� ���������, ��� ��� ����� ���������

// �� ���� ����������� ����� ����������, ��� ����� ���������� �������, � ����� ���� ������� �
const sf::Vector2i spawnN0(370, 0);
const sf::Vector2i spawnN1(429,48);
const sf::Vector2i spawnS0(371,751);
const sf::Vector2i spawnS1(429,799);
const sf::Vector2i spawnE0(749,371);
const sf::Vector2i spawnE1(799,429);
const sf::Vector2i spawnW0(0,371);
const sf::Vector2i spawnW1(45,429);

void game();


class CrossRoad //�����������, � �������� � ���������� � �������
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


class Cars //������, ��� ����� � ��������� ��������� � �������� �������
{
public:
	Cars(char);
	
	~Cars();
	
protected:
	sf::Vector2f position;
private:
	sf::Texture texture;
	enum class direction {North, South, East, West};
	direction direction; //������ �����������(� ����� ������ �����)
	static int count;   //������� �������(� ����� ������ �� �����)
	std::string car_number;



	void spawn_car();
};

Cars::Cars(char x)
{
	
	car_number = count + "_" + x;
	count++;
	switch (x) //���������, � ����� ������� ������ �������
	{
	case 'N': direction = direction::North; break;
	case 'S': direction = direction::South; break;
	case 'E': direction = direction::East; break;
	case 'W': direction = direction::West; break;
	default:
		std::cout << "�� �������. � ����� ������� ����?" << std::endl;
		break;
	}
}

Cars::~Cars()
{
}

void Cars::spawn_car() {

}
 

class Traffic_Lights //��������, �� ����� ������ ������� ����������� � ���, ����� ������ �������
{
public:
	Traffic_Lights(char,char);
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
	sf::Sprite update(){
		if (color == lights_color::GREEN){
			sprite.setTexture(texture_green);
			return sprite;
		}
		else {
			sprite.setTexture(texture_red);
			return sprite;
		}
	}

private:
	enum class lights_color {RED, GREEN}; // ������������� ��� ����� ����� ���������
	lights_color color;
	sf::Clock clock; //������ ��� ����� �����
	sf::Time time1; 
	sf::Texture texture_green;
	sf::Texture texture_red;
	sf::Sprite sprite;

};

Traffic_Lights::Traffic_Lights(char x, char y)
{
	texture_green.loadFromFile("img/traff_light_G.png");
	texture_red.loadFromFile("img/traff_light_R.png");
	switch (x) //���������, c ����� ������ ����� ��������
	{
	case 'R': 
		color = lights_color::RED;
		sprite.setTexture(texture_red);
		break;
	case 'G': 
		color = lights_color::GREEN;
		sprite.setTexture(texture_green);
		break;
	default:
		std::cout << "�� �������, ����� ����?" << std::endl;
		break;
	}
	std::cout << (color == lights_color::GREEN ? "GREEN" : "RED") << std::endl;
	switch (y) //���������, �� ����� ����������� ����� ��������
	{
	case 'S': 
		sprite.setPosition(440,350);

		break;
	case 'E': 
		sprite.setPosition(350, 350);

		break;
	default:
		std::cout << "�� �������, ����� �����������?" << std::endl;
		break;
	}
}

Traffic_Lights::~Traffic_Lights()
{
}


int Cars::count = 0;