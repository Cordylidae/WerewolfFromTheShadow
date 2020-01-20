#pragma once
#include<SFML/Graphics.hpp>
#include<string>

using namespace sf;
using namespace std;

Sprite makeSprite(string s)
{
	Image a;
	a.loadFromFile("C:/ff/" + s + ".png");
	Texture * b = new Texture;
	b->loadFromImage(a);
	Sprite sosna;
	sosna.setTexture(*b);
	return sosna;
}

Texture makeTexture(string s)
{
	Image a;
	a.loadFromFile("C:/ff/" + 	s + ".png");
	Texture * b = new Texture;
	b->loadFromImage(a);
	return *b;
}

void  movement() 
{

}