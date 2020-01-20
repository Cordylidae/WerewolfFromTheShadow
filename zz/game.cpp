#include<Sfml\Graphics.hpp>
#include<utility>
#include<string>
#include<fstream>
#include<iostream>
#include"view1.h"
#include"map1.h"
#include"view.h"
#include"map.h"
#include"grafa.h"//maketexture
//#include"fight.h"
#include <sstream>
using namespace sf;

enum State
{
   Tent, Outside, House , GMain , Bag , Save , Fight
};
///////////////////value for game/////////////////////
int insidebag[5][4];
int pozit = 2,atefood,havesuriken,movecivil=1,havegold=0;
bool  transformation = false, kalitkas = false,e=true,givefood = true,givesuriken=true;	
State state = GMain;
bool orbwater=true,orbform=true,orbfire=true,orblightning=true,orbwind=true,orbearth=true;
int howmuchsomething=2;
//int fightmap[11][11];
//////////////////////value for fight//////////////////////

////////////////////Sprite for fight//////////////////////
	//Texture background_=makeTexture("background");
	//Sprite background=makeSprite("background");

	//Texture kletkapola_=makeTexture("kletkapola");
	//Sprite kletkapola=makeSprite("kletkapola");
 ///////////////////Sprites/////////////////////////////////
	Texture civilianface1=makeTexture("civilian");

	Texture playerface=makeTexture("player");

	Texture dialogtable_1=makeTexture("dialogtable");
	Sprite dialogtable=makeSprite("dialogtable");

	Texture kalitka_1 = makeTexture("kalitka");
    Sprite kalitka = makeSprite("kalitka");

	Texture pol_1 = makeTexture("pol");
    Sprite pol = makeSprite("pol");

    Sprite windows = makeSprite("window");

    Sprite bed = makeSprite("bed");
   
    Sprite cupboard = makeSprite("cupboard");
    
    Sprite cupboar = makeSprite("cupboard1");
    
    Sprite table = makeSprite("table");
    
	Sprite zaslonka = makeSprite("zaslonka");

    Texture door_1 = makeTexture("door");
    Sprite door = makeSprite("door");
    
    Texture door_2 = makeTexture("door2");
    Sprite door2 = makeSprite("door2");

	Texture kafel_1 = makeTexture("kafel");
    Sprite kafel = makeSprite("kafel");

	Texture kafel_2 = makeTexture("kafel2");
    Sprite kafel2 = makeSprite("kafel2");

	Texture stena_1 = makeTexture("stena");
    Sprite stena = makeSprite("stena");

    Sprite lavka = makeSprite("lavka1");
    
    Sprite lavk2 = makeSprite("lavka2");

	Sprite peredevalka = makeSprite("peredevalka");

	Texture sosna_1 = makeTexture("sosna");
    Sprite sosna = makeSprite("sosna");

	Texture grass_1 = makeTexture("grass");
    Sprite grass = makeSprite("grass");

	Texture zabor_1 = makeTexture("zabor");
    Sprite zabor = makeSprite("zabor");

	Texture zabor_2 = makeTexture("zabor2");
    Sprite zabo2 = makeSprite("zabor2");

	Texture zabor_3 = makeTexture("zabor3");
    Sprite zabo3 = makeSprite("zabor3");

	Texture kover_1 = makeTexture("kover");
    Sprite kover = makeSprite("kover");

	Texture sand_1 = makeTexture("sand");
    Sprite  sand = makeSprite("sand");

    Sprite magicalcircle = makeSprite("magicalcircle");
    
    Sprite  talktree = makeSprite("talktree");

	Texture hous = makeTexture("house");
    Sprite house = makeSprite("house");
    
	Sprite clouse = makeSprite("clouse");

    Sprite clouse1 = makeSprite("clouse1");

    Texture ophous1 = makeTexture("openhouse");

    Sprite house2 = makeSprite("house2");
    
    Sprite house3 = makeSprite("house3");
    
    Sprite house4 = makeSprite("house4");

	Sprite toilet = makeSprite("toilet");

	Sprite bath = makeSprite("bath");

	Sprite rukmoyka = makeSprite("rukmoyka");

	Sprite zerkalo = makeSprite("zerkalo");

	Sprite polot = makeSprite("polot");

	Sprite cupboard3 = makeSprite("cupboard3");
	
	Sprite bed2 = makeSprite("bed2");

	Texture worktabl = makeTexture("work table");
	Sprite worktable = makeSprite("work table");

	Texture table21 = makeTexture("table2");
	Sprite table2 = makeSprite("table2");

	Sprite chair = makeSprite("chair");

	Sprite bigwindow = makeSprite("bigwindow");

	Sprite cover = makeSprite("cover");

	Sprite hole = makeSprite("hole");

	Sprite buket = makeSprite("buket");

	Sprite svechka = makeSprite("svechka");

	Sprite grile = makeSprite("grile");

	Sprite ctol = makeSprite("stol");

	Sprite flowers = makeSprite("flowers");

	Sprite table3 = makeSprite("table3");

	Sprite chairs = makeSprite("chairs");

	Sprite window2 = makeSprite("window2");

	Sprite piano = makeSprite("piano");

	Sprite bilyard = makeSprite("bilyard");

	Sprite comp = makeSprite("comp");

	Sprite kiy = makeSprite("kiy");

	Sprite darts = makeSprite("darts");

	Sprite man =makeSprite("main");

	Sprite help =makeSprite("help");

	Texture food_ = makeTexture("food");
	Sprite food = makeSprite("food");

	Sprite bag = makeSprite("bag");


	Sprite orbofwater = makeSprite("orbofwater");
	Sprite orbofwater2 = makeSprite("orbofwater");

	Sprite orbofform = makeSprite("orbofform");
	Sprite orbofform2 = makeSprite("orbofform");

	Sprite orboflightning = makeSprite("orboflightning");
	Sprite orboflightning2 = makeSprite("orboflightning");

	Sprite orbofearth = makeSprite("orbofearth");
	Sprite orbofearth2 = makeSprite("orbofearth");

	Sprite orbofwind = makeSprite("orbofwind");
	Sprite orbofwind2 = makeSprite("orbofwind");

	Sprite orboffire = makeSprite("orboffire");
	Sprite orboffire2 = makeSprite("orboffire");

	Sprite save = makeSprite("save");

	Sprite suriken = makeSprite("suriken");

	Sprite foodline = makeSprite("foodline");
	
	Sprite gold=makeSprite("gold");
/////////////////////////fuction for food////////////////////
Sprite randfood(Sprite a)
{
	int randox= rand()%9+0;
	int randoy= rand()%9+0;
	a.setTextureRect(IntRect(randox*16,randoy*16,16,16));
	return a;
}

/////////////////////////////Player/////////////////////////
class Player {
private: float x, y;
		 int a,b;
public:
	float dx, dy, speed;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Player(float X, float Y)
	{
        dx=0; dy=0; speed=0; dir =0;
		image.loadFromFile("C:/ff/player.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
	void update(float time)
	{
		a=31;b=31;
		if(dir==0)
		{
			dx = speed;
			dy = 0;
			b=32;
		}
		if(dir==1)
		{
			dx = -speed;
			dy = 0;
		} 
		if(dir==2)
		{
			dx = 0;
			dy = speed;
			a=32;
		} 
		if(dir==3)
		{
			dx = 0;
			dy = -speed;
		}
		
 x += dx*time;
 y += dy*time;
		
		
 
		speed = 0;
		sprite.setPosition(x,y);
		interactionWithMap();
	}

bool fsib(Sprite sprite1,bool sprite_,int a)
{
	if(sprite.getGlobalBounds().intersects(sprite1.getGlobalBounds()))
		{
			
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(!sprite_)break;
				if(::insidebag[i][j]==0)
				{
					if(a==8 && state==Outside){::insidebag[i][j]=8;sprite_=false;howmuchsomething++;}
					if(a==7 && state==Outside){::insidebag[i][j]=7;sprite_=false;howmuchsomething++;}
					if(a==6 && state==Outside){::insidebag[i][j]=6;sprite_=false;howmuchsomething++;}
					if(a==5 && state==Outside){::insidebag[i][j]=5;sprite_=false;howmuchsomething++;}
					if(a==4 && state==Outside){::insidebag[i][j]=4;sprite_=false;howmuchsomething++;}
					if(a==3 && state==Outside){::insidebag[i][j]=3;sprite_=false;howmuchsomething++;}

				}
				
			}
			if(!sprite_)break;
		}
		}
	return sprite_;
}
 
	void interactionWithMap()
	{
		if(sprite.getGlobalBounds().intersects(food.getGlobalBounds()) && state==2)
		{
			atefood++;
			givefood=true;
			food=randfood(food);
			if(atefood>10)atefood=10;
		}
			if(sprite.getGlobalBounds().intersects(suriken.getGlobalBounds()) && state==2)
		{
			havesuriken++;
			givesuriken=true;
			if(havesuriken>10)havesuriken=10;
		}


		orbwater=fsib(orbofwater,orbwater,3);
		orbform=fsib(orbofform,orbform,4);
		orbfire=fsib(orboffire,orbfire,5);
		orblightning=fsib(orboflightning,orblightning,6);
		orbwind=fsib(orbofwind,orbwind,7);
		orbearth=fsib(orbofearth,orbearth,8);
	

		for (int i = y / 32; i < (y + a) / 32; i++)
			for (int j = x / 32; j<(x + b) / 32; j++)
			{
				switch(state){
					case Outside:{
				if ((TileMap[i][j] != 'q' && TileMap[i][j] != 'a' && TileMap[i][j] != 'o' && TileMap[i][j] != 'p' && TileMap[i][j] != 'd'  && TileMap[i][j] != 'f' && TileMap[i][j] != 'k'))
				{
					if (dy>0 && i<(y+32)/32)
					{
						y = i * 32 - 32;
					}
					if (dy<0)
					{
						y = i * 32 + 32;
					}
					if (dx>0)
					{
						x = j * 32 - 32;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}
				 if (TileMap[i][j] == 'z')
                        {
                            pozit = 2;
                        }
                        if (TileMap[i][j] == 'k')
                        {
                            kalitka.setTexture(grass_1);
                        }
                        if (TileMap[i][j] != 'k')
                        {
                            kalitka.setTexture(kalitka_1);
                        }
						if (TileMap[i][j] == 'o' && (Keyboard::isKeyPressed(Keyboard::E)))

                        {
                            transformation = !transformation;
							if (transformation){TileMap[8][32] = 'a';house.setTexture(ophous1);}
							else {TileMap[8][32] = '*';house.setTexture(hous);}
                        }
				}
				break;
					case House:
						{
							if ((i >= 0 && i < HEIGHT_MAP1 && j >= 0 && j < WIDTH_MAP1 && TileMap1[i][j] != 'a' && TileMap1[i][j] != 'o' && TileMap1[i][j] != 'k' && TileMap1[i][j] != 'p' && TileMap1[i][j] != 'h' && TileMap1[i][j] != 'r' && TileMap1[i][j] != 'd'))
				{
					if (dy>0 && i<(y+32)/32)
					{
						y = i * 32 - 32;
					}
					if (dy<0)
					{
						y = i * 32 + 32;
					}
					if (dx>0)
					{
						x = j * 32 - 32;
					}
					if (dx < 0)
					{
						x = j * 32 + 32;
					}
				}
						if (TileMap1[i][j] == 'z')
                        {
                            pozit = 1;
                        }
                        if (TileMap1[i][j] == 'k')
                        {
                            door.setTexture(pol_1);
                        }
                        if (TileMap1[i][j] != 'k')
                        {
                            door.setTexture(door_1);
                        }
                        if (TileMap1[i][j] == 'p')
                        {
                            door2.setTexture(pol_1);
                        }
                        if (TileMap1[i][j] != 'p')
                        {
                            door2.setTexture(door_2);
                        }
					 }
				}
			}
	}
	
 
    float getPlayerCoordinateX()
	{	
		return x;
	}
	float getPlayerCoordinateY()
	{	
		return y;
	}
	void setPlayerCoordinateX(float a)
	{	
		 x=a;
	}
	void setPlayerCoordinateY(float b)
	{	
		y=b;
	}

};
///////////////////state -> int && int->state/////////////////
int stateint(State a)
{
	switch(a)
	{
	case House: return 2;
		break;
	case Outside: return 1;
		break;
	}
}
State intstate(int a)
{
	switch(a)
	{
	case 1: return Outside;
		break;
	case 2: return House;
		break;
	}
}
///////////////////Save////////////////////////
State Saved(State state,int x,int y,int howmuchsomething)
{
	            int xx=x;
				int yy=y;
				int k = stateint(state);
				int howmuchsomething1=howmuchsomething;

				FILE* file1=fopen("C:\\ff\\Continue.doc","w+");
				fprintf(file1,"%d %d %d ",xx,yy,k);
				fprintf(file1,"%d ",howmuchsomething);
				for(int i=0;i<5;i++)
				{
					for(int j=0;j<4;j++)
					{
						if(howmuchsomething1==0)break;
						if(insidebag[i][j]==1)fprintf(file1,"%d ",atefood);
						if(insidebag[i][j]==2)fprintf(file1,"%d ",havesuriken);
						if(insidebag[i][j]!=1 && insidebag[i][j]!=2)fprintf(file1,"%d ",insidebag[i][j]);
						howmuchsomething1--;
					}
					if(howmuchsomething1==0)break;
				}
				fclose(file1);
				state=Save;
				return state;

}
///////////////////civilian move////////////////
class Civilian
{
private:
int points,h,d,l,punction;
int z;
double x,y,speedx,speedy,a,b;
public:
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Civilian(float X, float Y,string s)
	{   
		image.loadFromFile("C:/ff/"+s+".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;speedx=0;speedy=0;points=0;a=X;b=Y;h=0;d=0;punction=0;z=0;
		sprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
	void move(int point,double x1,double y1,double x2,double y2,double x3,double y3)
	{
		switch(point)
		{
		case 0:
			{
			}
			break;
		case 1:
			{
				switch(points)
				{
				case 0:
					{
						h=0;d=0;
						if(pointtopoint(a,b,x1,y1)==1)points=1;
					}
				break;
				case 1:
					{
						h=0;d=0;
						if(pointtopoint(x1,y1,a,b)==1)points=0;
					}
				break;
				}
			}
			break;
		case 2:
			{
				switch(points)
				{
				case 0:
				{
					h=0;d=0;
					if(pointtopoint(a,b,x1,y1)==1)points=1;
				}
				break;
				case 1:
					{
						h=0;d=0;
						if(pointtopoint(x1,y1,x2,y2)==1)points=2;
					}
				break;
				case 2:
				{
					h=0;d=0;
					if(pointtopoint(x2,y2,a,b)==1)points=0;
				}
				break;
			}
			}
			break;
		case 3:
				switch(points)
				{
				case 0:
					{
						h=0;d=0;
						if(pointtopoint(a,b,x1,y1)==1)points=1;
					}
			   break;
			   case 1:
					{
						h=0;d=0;
						if(pointtopoint(x1,y1,x2,y2)==1)points=2;
					}
			   break;
			   case 2:
					{
						h=0;d=0;
						if(pointtopoint(x2,y2,x3,y3)==1)points=3;
					}
			   break;
			   case 3:
					{
						h=0;d=0;
						if(pointtopoint(x3,y3,a,b)==1)points=0;
					}
			   break;
				}
				break;
		}
	}
	

	int pointtopoint(double x1,double y1,float x2,float y2)
	{
		
		if(l==1){speedy=0;speedx=0;}
		else
		{
		if(y2>y1)speedy=0.1;
		if(y2<y1)speedy=-0.1;
		if(x2>x1)speedx=0.1;
		if(x2<x1)speedx=-0.1;
		if(x2==x1){speedx=0;d=1;}
		if(y2==y1){speedy=0;h=1;}
		}

		if(speedx<0)
		{
			if(x>x2)x=x+speedx;
			else d=1;
		}
		if(speedx>0)
		{
			if(x<x2)x=x+speedx;
			else d=1;
		}
		if(speedy<0)
		{
			if(y>y2)y=y+speedy;
			else h=1;
		}
		if(speedy>0)
		{
			if(y<y2)y=y+speedy;
			else h=1;
		}
				
			sprite.setPosition(x,y);
			if(d==1 && h==1){cout<<45<<endl;return 1;}
		    return 0;
	}
	int interactionWithPlayer(Sprite g)
	{
		if(sprite.getGlobalBounds().intersects(g.getGlobalBounds()))
		{
			l=1;
		}
		else l=0;
		return l;
	}
	String speak()
	{
		String text;

		switch(punction)
		{
		case 0:
			{
				if(z==0)text="Stive: Hello.Help me.Please.\n\nYes/y\t\t\t\tNo/n";
				if(Keyboard::isKeyPressed(Keyboard::Y))z=1;
				if(z==1){text="Max: Hello.Okey I can help you.\nDon't worry.";if(Keyboard::isKeyPressed(Keyboard::L))punction=1;}
				if(Keyboard::isKeyPressed(Keyboard::N))z=2;
				if(z==2){text="Max: Hello.Sorry I can't help you.";if(Keyboard::isKeyPressed(Keyboard::L))punction=2;}
			}
		break;
		case 1:
			{
				text="Stive: Start your mission.\nYou must go to old cave.";
			}
		break;
		case 2:
			{
				text="Stive: error.";
			}
		}
		return text;
	}
	void effect(int CurrentFrame)
	{
		if (speedx>0)
			{ 
				sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
			}   
		if (speedx<0)
			{
                sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
			}
		if (speedy<0)
			{
				sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
			}
		if (speedy>0)
			{
				sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
			}
	}
};
class Evil
{
private:
int l;
double x,y,speedx,speedy,a,b;
bool backtopoint;
public:
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Evil(float X, float Y,string s)
	{   
		image.loadFromFile("C:/ff/"+s+".png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;speedx=0;speedy=0;a=X;b=Y;backtopoint=true;
		sprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
	void move(double x1,double y1)
	{
		backtopoint=true;
		if(x1>=x && x1<=x+100 &&((y1>=y && y1<=y+100)||(y1<=y && y1>=y-100))){x=x+0.2;backtopoint=false;}
		if(x1<=x && x1>=x-100 &&((y1>=y && y1<=y+100)||(y1<=y && y1>=y-100))){x=x-0.2;backtopoint=false;}
		if(y1>=y && y1<=y+100 &&((x1<=x && x1>=x-100)||(x1>=x && x1<=x+100))){y=y+0.2;backtopoint=false;}
		if(y1<=y && y1>=y-100 &&((x1<=x && x1>=x-100)||(x1>=x && x1<=x+100))){y=y-0.2;backtopoint=false;}
		if(backtopoint)
		{
			if(x>a){x=x-0.2;}
			if(x<a){x=x+0.2;}
			if(y>b){y=y-0.2;}
			if(y<b){y=y+0.2;}
		}

		sprite.setPosition(x,y);
	}
	int interactionWithPlayer(Sprite g)
	{
		if(sprite.getGlobalBounds().intersects(g.getGlobalBounds()))
		{
			l=1;
		}
		else l=0;
		return l;
	}
};
///////////////////Main/////////////////////////

int main()
{
	srand(time(0));


	//////////font////////////
	Font font; 
    font.loadFromFile("brushshopregular.otf");
    Text text("", font, 20),text1("", font, 20),text2("",font, 10);
    text.setColor(Color::Blue);
    text.setStyle(Text::Bold);
	text1.setColor(Color::Blue);
    text1.setStyle(Text::Bold);
	text2.setColor(Color::White);
    text2.setStyle(Text::Bold);

    RenderWindow window(VideoMode(640, 640), "Werewolf from Shadow");
    view1.reset(FloatRect(320, 320, 320, 320));
    view.reset(FloatRect(900, 320, 320, 320));
	


	
	Civilian civilian1(500,500,"civilian");
	civilian1.sprite.setPosition(500,500);
	
	Evil evil1(560,560,"EvilPlayer");
	evil1.sprite.setPosition(560,560);

	Player shape(26*32,64);
	shape.sprite.setPosition(26*32,64);

	int x=70,d=0;
	int xfood,yfood,xsuriken,ysuriken;

	
	Sprite face;

	RectangleShape sh,sh1,sh2,sh3;
	

	 sh.setSize(sf::Vector2f(230,5));
	 sh.setFillColor(Color::Blue);
	
	 sh1.setSize(sf::Vector2f(230,5));
	 sh1.setFillColor(Color::Blue);
	 
	 sh2.setSize(sf::Vector2f(5,54));
	 sh2.setFillColor(Color::Blue);
	 
	 sh3.setSize(sf::Vector2f(5,54));
	 sh3.setFillColor(Color::Blue);

	//background.setPosition(0,0);
	lavka.setPosition(320, 128);
    bed.setPosition(864, 32);
	house4.setPosition(544, 84);
	house3.setPosition(650, 84);
	house2.setPosition(762, 84);
	house.setPosition(960, 32);
	cupboard.setPosition(32, 16);
	cupboar.setPosition(384, 4);
	table.setPosition(800, 12);
	lavk2.setPosition(192, 128);
	magicalcircle.setPosition(400, 400);
	peredevalka.setPosition(832,128);
	bath.setPosition(768,214);
	zaslonka.setPosition(794,192);
	toilet.setPosition(899,214);
	rukmoyka.setPosition(834,200);
	zerkalo.setPosition(806,194);
	polot.setPosition(867,194);
	clouse.setPosition(544,512);
	clouse1.setPosition(544,548);
	cupboard3.setPosition(832,400);
	worktable.setPosition(804,490);
	bed2.setPosition(320,164);
	hole.setPosition(615,170);
	cover.setPosition(22*32,9*32);
	grile.setPosition(4*32,6*32-20);
	ctol.setPosition(2*32,9*32+2);
	flowers.setPosition(32+16,5*32+16);
	table3.setPosition(6*32+16,8*32);
	window2.setPosition(32,7*32+16);
	piano.setPosition(12*32,14*32);
	comp.setPosition(3*32+16,14*32-16);
	kiy.setPosition(7*32,13*32);
	darts.setPosition(10*32+6,13*32+6);
	
	man.setPosition(0,0);
	bag.setPosition(0,0);
	save.setPosition(0,0);

	

    float CurrentFrame = 0;
    Clock clock;

    while (window.isOpen())
    {

        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
			{
                window.close();
			}
        }
		CurrentFrame += 0.005 * time;
                if (CurrentFrame > 3)CurrentFrame -= 3;
				

        switch (state)
        {
		case Save:
			{
				Vector2i pozition1 = Mouse :: getPosition(window);

				window.clear();
				window.setView(window.getDefaultView());
				window.draw(save);
				
				if(pozition1.x>=200 && pozition1.x<=430 && pozition1.y>=500 && pozition1.y<=554)
				{
					sh.setPosition(200,500);
					sh1.setPosition(200,549);
					sh2.setPosition(200,500);
					sh3.setPosition(425,500);

					window.draw(sh);
					window.draw(sh1);
					window.draw(sh2);
					window.draw(sh3);
				}
				if(pozition1.x>=200 && pozition1.x<=430 && pozition1.y>=500 && pozition1.y<=554 && (Mouse::isButtonPressed(Mouse::Button::Left)))
				{
				if(pozit==1)state=Outside;
				if(pozit==2)state=House;
				}
				window.display();
			}
			break;

		case Bag:
			{
				Vector2i pozition1 = Mouse :: getPosition(window);

				window.clear();
				window.setView(window.getDefaultView());
				window.draw(bag);
				for(int i=0;i<5;i++)
					for(int j=0;j<4;j++)
					{
						if(insidebag[i][j]==3){orbofwater2.setPosition(130+(j*96),130+(96*i));orbofwater2.setScale(Vector2f(4.f,4.f));window.draw(orbofwater2);}
						if(insidebag[i][j]==4){orbofform2.setPosition(130+(j*96),130+(96*i));orbofform2.setScale(Vector2f(4.f, 4.f));window.draw(orbofform2);}
						if(insidebag[i][j]==5){orboffire2.setPosition(130+(j*96),130+(96*i));orboffire2.setScale(Vector2f(4.f, 4.f));window.draw(orboffire2);}
						if(insidebag[i][j]==6){orboflightning2.setPosition(130+(j*96),130+(96*i));orboflightning2.setScale(Vector2f(4.f, 4.f));window.draw(orboflightning2);}
						if(insidebag[i][j]==7){orbofwind2.setPosition(130+(j*96),130+(96*i));orbofwind2.setScale(Vector2f(4.f, 4.f));window.draw(orbofwind2);}
						if(insidebag[i][j]==8){orbofearth2.setPosition(130+(j*96),130+(96*i));orbofearth2.setScale(Vector2f(4.f, 4.f));window.draw(orbofearth2);}
					}

				if(pozition1.x>=410 && pozition1.x<=640 && pozition1.y>=586 && pozition1.y<=640)
				{
					sh.setPosition(410,586);
					sh1.setPosition(410,635);
					sh2.setPosition(410,586);
					sh3.setPosition(635,586);

					window.draw(sh);
					window.draw(sh1);
					window.draw(sh2);
					window.draw(sh3);
				}
				if(pozition1.x>=410 && pozition1.x<=640 && pozition1.y>=586 && pozition1.y<=640 && (Mouse::isButtonPressed(Mouse::Button::Left)))
				{
				if(pozit==1)state=Outside;
				if(pozit==2)state=House;
				}
				ostringstream atefood_,havesuriken_;
		        atefood_ << atefood;
				havesuriken_<< havesuriken;
				text.setString(atefood_.str());
				text.setPosition(152,162);
				window.draw(text);
				text1.setString(havesuriken_.str());
				text1.setPosition(248,162);
				window.draw(text1);

				window.display();
			}
			break;

		case GMain:
			{
				Vector2i pozition = Mouse :: getPosition(window);


				window.clear();
				window.setView(window.getDefaultView());
				window.draw(man);

				if(pozition.x>=52 && pozition.x<=282 &&( (pozition.y>=327 && pozition.y<=381)||(pozition.y>=397 && pozition.y<=451)||(pozition.y>=467 && pozition.y<=521)||(pozition.y>=537 && pozition.y<=591)))
				{
					d=int((pozition.y-327)/70);

		 sh.setPosition(52,327+x*d);
		 sh1.setPosition(52,376+x*d);
		 sh2.setPosition(52,327+x*d);
		 sh3.setPosition(282,327+x*d);

		window.draw(sh);
		window.draw(sh1);
		window.draw(sh2);
		window.draw(sh3);
				}
				if(pozition.x>=52 && pozition.x<=282 &&((pozition.y>=327 && pozition.y<=381)) && (Mouse::isButtonPressed(Mouse::Button::Left)))
				{
					atefood=0;
					havesuriken=0;
					pozit=2;
					state = House;
					shape.sprite.setPosition(26*32,64);
					shape.setPlayerCoordinateX(26*32);
					shape.setPlayerCoordinateY(64);
					door.setTexture(door_1);
					shape.sprite.setTextureRect(IntRect(32 * 2, 0, 32, 32));
					food=randfood(food);
					givefood=true;
					givesuriken=true;

					orbofwater.setPosition(560,560);
					orbofform.setPosition(580,560);
					orboffire.setPosition(600,560);
					orboflightning.setPosition(620,560);
					orbofwind.setPosition(640,560);
					orbofearth.setPosition(660,560);

					for(int i=0;i<5;i++)
						for(int j=0;j<4;j++)
						{
							insidebag[i][j]=0;
						}
						insidebag[0][0]=1;
						insidebag[0][1]=2;
					
					orbwater=true;
					orbform=true;
					orbfire=true;
					orblightning=true;
					orbwind=true;
					orbearth=true;
				}
				if(pozition.x>=52 && pozition.x<=282 &&((pozition.y>=397 && pozition.y<=451)) && (Mouse::isButtonPressed(Mouse::Button::Left)))
				{
					int xx;
					int yy;
					int k;
					int howmuchsomething1;

					orbwater=true;
					orbform=true;
					orbfire=true;
					orblightning=true;
					orbwind=true;
					orbearth=true;
					

					FILE* file=fopen("C:\\ff\\Continue.doc","r+");
					fscanf(file,"%d %d %d ",&xx,&yy,&k);
					fscanf(file,"%d ",&howmuchsomething);
					howmuchsomething1=howmuchsomething;
					/////continius///////////

						for(int i=0;i<5;i++)
						{
							for(int j=0;j<4;j++)
							{
								if(howmuchsomething1==0)break;
								int a;
								fscanf(file,"%d ",&a);
								if(i==0 && j==0){atefood=a;insidebag[i][j]=1;}
								else
								{
									if(i==0 && j==1){havesuriken=a;insidebag[i][j]=2;}
									else
									{
										insidebag[i][j]=a;
										if(a==3)orbwater=false;
										if(a==4)orbform=false;
										if(a==5)orbfire=false;
										if(a==6)orblightning=false;
										if(a==7)orbwind=false;
										if(a==8)orbearth=false;
									}
								}
								howmuchsomething1--;
							}
							if(howmuchsomething1==0)break;
						}

					fclose(file);
					state = intstate(k);
					shape.setPlayerCoordinateX(xx);
					shape.setPlayerCoordinateY(yy);
					shape.sprite.setPosition(xx,yy);
					pozit=k;
					food=randfood(food);
					if(orbwater)orbofwater.setPosition(560,560);
					if(orbform)orbofform.setPosition(580,560);
					if(orbfire)orboffire.setPosition(600,560);
					if(orblightning)orboflightning.setPosition(620,560);
					if(orbwind)orbofwind.setPosition(640,560);
					if(orbearth)orbofearth.setPosition(660,560);
				}
				if(pozition.x>=52 && pozition.x<=282 &&((pozition.y>=537 && pozition.y<=591)) && (Mouse::isButtonPressed(Mouse::Button::Left)))
				{
					window.close();
				}
				if(pozition.x>=517 && pozition.x<=605 && pozition.y>=569 && pozition.x<=621)
				{
					help.setPosition(517,569);
					window.draw(help);
				}
				window.display();
			} 
			break;

        case House:
        {
			
			cordinate1(shape.getPlayerCoordinateX(), shape.getPlayerCoordinateY());
            window.setView(view1);

            if (Keyboard::isKeyPressed(Keyboard::D))
			{ 
				shape.dir = 0; shape.speed = 0.1;
				shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
				shape.update(time);
			}   
                       
            
            if (Keyboard::isKeyPressed(Keyboard::A))
			{
				shape.dir = 1; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
				shape.update(time);
			}
            

            if (Keyboard::isKeyPressed(Keyboard::W))
			{
				shape.dir = 3; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
				shape.update(time);
			}

            if (Keyboard::isKeyPressed(Keyboard::S)) 
			{
				shape.dir = 2; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				shape.update(time);
			}
			
			
	
            window.clear();

            for (int i = 0;i<HEIGHT_MAP1;i++)
                for (int j = 0;j<WIDTH_MAP1;j++)
                {
                    if (TileMap1[i][j] == 'o' || TileMap1[i][j] == '*' || TileMap1[i][j] == 'a' || TileMap1[i][j] == 'k' || TileMap1[i][j] == 'p' || TileMap1[i][j] == 'h' || TileMap1[i][j] == 'z') { pol.setPosition(j * 32, i * 32);window.draw(pol); }
                    if (TileMap1[i][j] == '0') { stena.setPosition(j * 32, i * 32);window.draw(stena); }
                    if (TileMap1[i][j] == 'k') { door.setPosition(j * 32, i * 32);window.draw(door); }
                    if (TileMap1[i][j] == 'p') { door2.setPosition(j * 32, i * 32);window.draw(door2); }
                    if (TileMap1[i][j] == 'o' || TileMap1[i][j] == 'j') { kafel.setPosition(j * 32, i * 32);window.draw(kafel); }
                    if (TileMap1[i][j] == 'h' || TileMap1[i][j] == 'f') { kafel2.setPosition(j * 32, i * 32);window.draw(kafel2); }
					if (TileMap1[i][j] == 'd' || TileMap1[i][j] == 'u') { kover.setTextureRect(IntRect(0,0,32,32));kover.setPosition(j * 32, i * 32);window.draw(kover); }
                    if (TileMap1[i][j] == 'r' || TileMap1[i][j] == 'q') { kover.setTextureRect(IntRect(32,0,32,32));kover.setPosition(j * 32, i * 32);window.draw(kover); }
				}
			
			if(givefood)
			{
				xfood=((rand()%30*32+0));
				yfood=((rand()%20*32+0));
				while(TileMap1[yfood/32][xfood/32]!='a' && TileMap1[yfood/32][xfood/32]!='r' && TileMap1[yfood/32][xfood/32]!='d' && TileMap1[yfood/32][xfood/32]!='o' && TileMap1[yfood/32][xfood/32]!='h')
				{
				xfood=((rand()%30*32+0));
				yfood=((rand()%20*32+0));
				}
				givefood=false;
			}
			food.setPosition(xfood,yfood-1*CurrentFrame);
			window.draw(food);

			if(givesuriken)
			{
				xsuriken=((rand()%30*32+0));
				ysuriken=((rand()%20*32+0));
				while(TileMap1[ysuriken/32][xsuriken/32]!='a' && TileMap1[ysuriken/32][xsuriken/32]!='r' && TileMap1[ysuriken/32][xsuriken/32]!='d' && TileMap1[ysuriken/32][xsuriken/32]!='o' && TileMap1[ysuriken/32][xsuriken/32]!='h')
				{
				xsuriken=((rand()%30*32+0));
				ysuriken=((rand()%20*32+0));
				}
				givesuriken=false;
			}
			suriken.setPosition(xsuriken,ysuriken-1*CurrentFrame);
			window.draw(suriken);

			window.draw(darts);

			window.draw(kiy);

			window.draw(comp);

			window.draw(piano);

			chairs.setPosition(6*32-8,8*32+8);
			window.draw(chairs);

			chairs.setPosition(6*32-8,8*32+40);
			window.draw(chairs);

			chairs.setPosition(6*32-8,8*32+72);
			window.draw(chairs);

			chairs.setPosition(7*32+24,8*32+8);
			window.draw(chairs);

			chairs.setPosition(7*32+24,8*32+40);
			window.draw(chairs);

			chairs.setPosition(7*32+24,8*32+72);
			window.draw(chairs);

			window.draw(grile);

			window.draw(hole);

			window.draw(cover);

			chair.setPosition(504,272);
			window.draw(chair);
			chair.setPosition(564,272);
			window.draw(chair);

			worktable.setTextureRect(IntRect(0,39,124,40));
			worktable.setPosition(804,529);
			window.draw(worktable);

			table2.setTextureRect(IntRect(0,32,64,32));
			table2.setPosition(512,280);
			window.draw(table2);

			chair.setPosition(506,294);
			window.draw(chair);
			chair.setPosition(534,302);
			window.draw(chair);
			chair.setPosition(558,294);
			window.draw(chair);

			buket.setPosition(440,160);
			window.draw(buket);
			buket.setPosition(540,160);
			window.draw(buket);
			buket.setPosition(640,160);
			window.draw(buket);

			svechka.setPosition(386,164);
			window.draw(svechka);
			svechka.setPosition(486,164);
			window.draw(svechka);
			svechka.setPosition(586,164);
			window.draw(svechka);

			window.draw(bed2);
			window.draw(cupboard3);
			window.draw(clouse);
			window.draw(polot);
			window.draw(zerkalo);
			window.draw(rukmoyka);
			window.draw(zaslonka);
			window.draw(bath);
			window.draw(toilet);
            window.draw(table);
            window.draw(cupboard);
            window.draw(cupboar);
			window.draw(flowers);
			
			bigwindow.setPosition(670,0);
            window.draw(bigwindow);

			bilyard.setTextureRect(IntRect(0,9,97,70));
			bilyard.setPosition(6*32,16*32);
			window.draw(bilyard);

            window.draw(shape.sprite);

			bilyard.setTextureRect(IntRect(0,0,97,9));
			bilyard.setPosition(6*32,16*32-8);
			window.draw(bilyard);

			buket.setPosition(32,4*32-20);
			window.draw(buket);


            windows.setPosition(304, 2);
            window.draw(windows);
            windows.setPosition(838, 2);
            window.draw(windows);
            
			window.draw(bed);
			window.draw(peredevalka);
			window.draw(clouse1);

			table2.setTextureRect(IntRect(0,0,64,32));
			table2.setPosition(512,248);
			window.draw(table2);

			worktable.setTextureRect(IntRect(0,0,124,39));
			worktable.setPosition(804,490);
			window.draw(worktable);

			window.draw(ctol);
			
			window.draw(table3);

			window.draw(window2);

			gold.setPosition(view1.getCenter().x-160,view1.getCenter().y-160);
			window.draw(gold);

            window.display();
            if (pozit == 1) 
			{	
				shape.setPlayerCoordinateX(1024),shape.setPlayerCoordinateY(288);
				state = Outside; 
			}

			if(Keyboard::isKeyPressed(Keyboard::Escape)){state=GMain;}
			if(Keyboard::isKeyPressed(Keyboard::Q)){state=Bag;}
			if(Keyboard::isKeyPressed(Keyboard::U))
			{
				state=Saved(state,shape.getPlayerCoordinateX(),shape.getPlayerCoordinateY(),howmuchsomething);
			}
        }
        break;
        case Outside:
        {
			
            if (Keyboard::isKeyPressed(Keyboard::D))
			{ 
				shape.dir = 0; shape.speed = 0.1;
				shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
				shape.update(time);
			}   
                       
            
            if (Keyboard::isKeyPressed(Keyboard::A))
			{
				shape.dir = 1; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
				shape.update(time);
			}
            

            if (Keyboard::isKeyPressed(Keyboard::W))
			{
				shape.dir = 3; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
				shape.update(time);
			}

            if (Keyboard::isKeyPressed(Keyboard::S))
			{
				shape.dir = 2; shape.speed = 0.1;
                shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
				shape.update(time);
			}   
			
            cordinate(shape.getPlayerCoordinateX(), shape.getPlayerCoordinateY());
			//bots move
			evil1.move(shape.sprite.getPosition().x,shape.sprite.getPosition().y);

			window.setView(view);
            window.clear();

			

            for (int i = 0;i<HEIGHT_MAP;i++)
                for (int j = 0;j<WIDTH_MAP;j++)
                {
                    if (TileMap[i][j] == 'q' || TileMap[i][j] == 'k' || TileMap[i][j] == 'd' || TileMap[i][j] == 'o' || TileMap[i][j] == '*' || TileMap[i][j] == 'a' || TileMap[i][j] == '0' || TileMap[i][j] == 'p' || TileMap[i][j] == 'h' || TileMap[i][j] == 'l')
					{ 
						grass.setPosition(j * 32, i * 32);
						grass.setTextureRect(IntRect(0,0,32,32));
						window.draw(grass); 
					}
                }




            for (int i = 0;i<HEIGHT_MAP;i++)
                for (int j = 0;j<WIDTH_MAP;j++)
                {
                    if (TileMap[i][j] == 'p') { zabor.setPosition(j * 32, i * 32);window.draw(zabor); }
                    if (TileMap[i][j] == '0' || TileMap[i][j] == 'h' || TileMap[i][j] == 'l') { sosna.setPosition(j * 32, i * 32);window.draw(sosna); }
                    if (TileMap[i][j] == 'l') { zabo2.setPosition(j * 32, i * 32);window.draw(zabo2); }
                    if (TileMap[i][j] == 'h') { zabo3.setPosition(j * 32, i * 32);window.draw(zabo3); }
                    if (TileMap[i][j] == 'f') { sand.setPosition(j * 32, i * 32);window.draw(sand); }
                    if (TileMap[i][j] == 'k') { kalitka.setPosition(j * 32, i * 32);window.draw(kalitka); }
                }

				
            window.draw(lavka);
            window.draw(lavk2);


            window.draw(magicalcircle);
			


            talktree.setTextureRect(IntRect(0, 120, 156, 36));
            talktree.setPosition(800, 512);
            window.draw(talktree);

            window.draw(house);
            window.draw(house2);
            window.draw(house3);
            window.draw(house4);
			
			if(orbwater)window.draw(orbofwater);
			if(orbform)window.draw(orbofform);
			if(orbfire)window.draw(orboffire);
			if(orbwind)window.draw(orbofwind);
			if(orbearth)window.draw(orbofearth);
			if(orblightning)window.draw(orboflightning);

			window.draw(evil1.sprite);
			window.draw(civilian1.sprite);
			window.draw(shape.sprite);

            talktree.setTextureRect(IntRect(0, 0, 156, 120));
            talktree.setPosition(800, 392);
            window.draw(talktree);

            for (int i = 0;i<HEIGHT_MAP;i++)
                for (int j = 0;j<WIDTH_MAP;j++)
                {
                    if (TileMap[i][j] == 'd') { zabor.setPosition(j * 32, i * 32);window.draw(zabor); }
                }

			civilian1.move(3,500,700,1000,700,1000,500);
			civilian1.effect(CurrentFrame);

			if(evil1.interactionWithPlayer(shape.sprite)==1)
			{
				state=Fight;
			}

			if(civilian1.interactionWithPlayer(shape.sprite)==1)
			{
				dialogtable.setPosition(shape.getPlayerCoordinateX()-160,shape.getPlayerCoordinateY()+92);
				window.draw(dialogtable);

				face.setTexture(civilianface1);
				face.setTextureRect(IntRect(35,0,27,19));
	            face.setScale(Vector2f(2.f, 2.f));
				face.setPosition(shape.getPlayerCoordinateX()-150,shape.getPlayerCoordinateY()+111);
				window.draw(face);

				face.setTexture(playerface);
				face.setTextureRect(IntRect(35,0,27,19));
	            face.setScale(Vector2f(2.f, 2.f));
				face.setPosition(shape.getPlayerCoordinateX()+98,shape.getPlayerCoordinateY()+111);
				window.draw(face);

				text2.setString(civilian1.speak());
				text2.setPosition(shape.getPlayerCoordinateX()-74,shape.getPlayerCoordinateY()+111);
				window.draw(text2);
			}
			
			gold.setPosition(view.getCenter().x-160,view.getCenter().y-160);
			window.draw(gold);

            window.display();
            if (pozit == 2)
			{ 
				shape.setPlayerCoordinateX(480);
				shape.setPlayerCoordinateY(544);
				state = House; 
			}
			if(Keyboard::isKeyPressed(Keyboard::Escape)){state=GMain;}
			if(Keyboard::isKeyPressed(Keyboard::Q)){state=Bag;}
			if(Keyboard::isKeyPressed(Keyboard::U))
			{
				state=Saved(state,shape.getPlayerCoordinateX(),shape.getPlayerCoordinateY(),howmuchsomething);
			}
        }
        break;
		case Fight:
			{
				/*if(pozit==2)
				fight();
				window.clear();
				window.setView(window.getDefaultView());
				window.draw(background);
				/*for(int i=0;i<11;i++)
					for(int j=0;j<11;j++)
					{
						if(fightmap[i][j]==0)
						{
							kletkapola.setTextureRect(IntRect(64,0,64,64));
							window.draw(kletkapola);
						}
												
						if(fightmap[i][j]==1)
						{
							kletkapola.setTextureRect(IntRect(0,0,64,64));
							window.draw(kletkapola);
						}
					}
				window.display();*/
			}
			break;
        }
    
	}
    return 0;
}
