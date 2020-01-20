//#include<Sfml\Graphics.hpp>
//#include<utility>
//#include<string>
//#include<fstream>
//#include<iostream>
//#include<sstream>
//#include<cmath>
//#include<algorithm>
//#include<sstream>
//
//using namespace sf;
//using namespace std;
//
//int chooses(int mp,int me,int hp,int he,int arp,int are,int x,int y,int x1,int y1,int sk,bool prop,bool ice,bool nomagic)
//	{
//		if(prop)return 0;
//		if(he<=2 && me>=10)return 8;
//		if(he+are<=3 && me>=3 && !nomagic)return 6;
//		if((abs(x1-x)+abs(y1-y)<=2 && !ice)||(abs(x1-x)+abs(y1-y)<=1))return 1;//attack
//		if(abs(x1-x)+abs(y1-y)<=5 && sk>0)return 2;//suriken
//		if(hp<2 && me>=11 && !nomagic)return 3;//kiss vimpire
//		if(me>=11 && !nomagic)return 4;//meteor
//		if(me>=8 && !nomagic)return 5;//+mana
//		return 7;//turn
//	}
//void turn(int x,int y,int x1,int y1,int &a,int &b,bool ice)
//	{
//		int z=2;
//		if(ice)z=1;
//				if(x-1>x1 && x-1-x1>z){a=z;b=0;}
//				else if(x-1>x1 && x-1-x1<=z)
//				{
//					a=x-1-x1;
//					if(y+1<y1 && y1-y-1>z)b=-(z-a);
//					else if(y+1<y1 && y1-y-1<=z)b=-(y1-y-1);
//					if(y-1>y1 && y-y1-1>z)b=z-a;
//					else if(y-1>y1 && y-y1-1<=z)b=(y-y1-1);
//				}
//				else 
//				{
//					if(y+1<y1 && y1-y-1>z)b=-z;
//					else if(y+1<y1 && y1-y-1<=z)b=-(y1-y-1);
//					if(y-1>y1 && y-y1-1>z)b=z;
//					else if(y-1>y1 && y-y1-1<=z)b=(y-y1-1);
//				}
//
//				if(x+1<x1 && x1-1-x>z){a=-z;b=0;}
//				else if(x+1<x1 && x1-1-x<=z && x1-1-x>0)
//				{
//					a=-(x1-1-x);
//					if(y+1<y1 && y1-y-1>z)b=-(z-abs(a));
//					else if(y+1<y1 && y1-y-1<=z)b=-(y1-y-1);
//					if(y-1>y1 && y-y1-1>z)b=z-abs(a);
//					else if(y-1>y1 && y-y1-1<=z)b=(y-y1-1);
//				}
//				else 
//				{
//					if(y+1<y1 && y1-y-1>z)b=-z;
//					else if(y+1<y1 && y1-y-1<=z)b=-(y1-y-1);
//					if(y-1>y1 && y-y1-1>z)b=z;
//					else if(y-1>y1 && y-y1-1<=z)b=(y-y1-1);
//				}
//	}
//
//#define pi 3.14159265
//
//
////using namespace nmspace;
//
//bool ifmagic=false,ll=true,tut=true;
//int fightmap[9][9]={-1},col=0,col2=0,col3=0,col4=0,col5=0;
//bool prop=false,fast=false,ynee=false;
//int turns,z=1;
//bool arrow=false,att=false,kkd=true,vuborp=false,vubore=false,onoff=true;
//
//bool non=false,non1=false,non2=false,non3=false,non4=false,non5=false,non6=false,non7=false,non8=false,non9=false,non10=false,non11=false;
//
//int sgn(int n) {
//	return n < 0 ? -1 : n > 0 ? 1 : 0;
//}
//
//bool ef(double a,double b)
//{
//	return abs(a-b)<1;
//}
//
//struct Spell
//{
//	bool nomagic;
//	bool lightstorm;
//	bool firerain;
//	bool vampirekiss;
//	bool icesuriken;
//	bool tornado;
//	bool poisonarrow;
//	bool armor;
//	bool crestaliz;
//	bool miss;
//	bool reincarnation;
//	bool fastrun;
//};
//
//class Evil
//{
//private:
//	float x,y,h;
//public:
//	float sk,dx, dy, speed,mana,arm;
//	int dir;
//	String File;
//	Image image,image2;
//	Texture texture,texture2;
//	Sprite sprite;
//	Evil(float X, float Y)
//	{
//        dx=0; dy=0; speed=0; dir =0;
//		image.loadFromFile("ff/EvilPlayer.png");
//		texture.loadFromImage(image);
//		sprite.setTexture(texture);
//		image2.loadFromFile("ff/EvilPlayer1.png");
//		texture2.loadFromImage(image2);
//		x = X; y = Y;
//		sprite.setTextureRect(IntRect(32,32, 32, 32));
//		sprite.setScale(Vector2f(1.5f, 1.5f));
//		sk=4;h=7;arm=0;mana=20;
//	}
//	void setPEPX(double a)
//	{
//		x=a;
//	}
//	void setPEPY(double b)
//	{
//		y=b;
//	}
//	void setHelth(int h1)
//	{
//		h=h1;
//	}
//	int getHelth()
//	{
//		return h;
//	}
//	void setMana(int mana1)
//	{
//		if(mana1>20)mana1=20;
//		mana=mana1;
//	}
//	int getMana()
//	{
//		return mana;
//	}
//	void setArmor(int arm1)
//	{
//		if(arm1>5)arm1=5;
//		arm=arm1;
//	}
//	int getArmor()
//	{
//		return arm;
//	}
//	void setSurikens(int sk1)
//	{
//		sk=sk1;
//	}
//	int getSurikens()
//	{
//		return sk;
//	}
//	double getPEPX()
//	{
//		return x;
//	}
//	double getPEPY()
//	{
//		return y;
//	}
//	void swap(bool p)
//	{
//		if(p)sprite.setTexture(texture2);
//		else sprite.setTexture(texture);
//	}
//	bool interection(Sprite g)
//	{
//		if(sprite.getGlobalBounds().intersects(g.getGlobalBounds()))
//		{
//			return false;
//		}
//		return true;
//	}
//};
//
//class Player {
//private: float x, y,h,arm,mana,sk;
//public:
//	float dx, dy, speed;
//	int dir;
//	String File;
//	Image image,image2;
//	Texture texture,texture2;
//	Sprite sprite;
//	Player(float X, float Y)
//	{
//        dx=0; dy=0; speed=0; dir =0;
//		image.loadFromFile("ff/player.png");
//		texture.loadFromImage(image);
//		sprite.setTexture(texture);
//		image2.loadFromFile("ff/player1.png");
//		texture2.loadFromImage(image2);
//		x = X; y = Y;
//		sprite.setTextureRect(IntRect(32,64, 32, 32));
//		sprite.setScale(Vector2f(1.5f, 1.5f));
//		h=3;arm=2;mana=25;sk=4;
//	}
//	void setPPX(double a)
//	{
//		x=a;
//	}
//	void setPPY(double b)
//	{
//		y=b;
//	}
//	void setHelth(int h1)
//	{
//		h=h1;
//	}
//	int getHelth()
//	{
//		return h;
//	}
//	void setMana(int mana1)
//	{
//		if(mana1>25)mana1=25;
//		mana=mana1;
//	}
//	int getMana()
//	{
//		return mana;
//	}
//	void setSurikens(int sk1)
//	{
//		sk=sk1;
//	}
//	int getSurikens()
//	{
//		return sk;
//	}
//	void setArmor(int arm1)
//	{
//		if(arm1>5)arm1=5;
//		arm=arm1;
//	}
//	int getArmor()
//	{
//		return arm;
//	}
//	double getPPX()
//	{
//		return x;
//	}
//	double getPPY()
//	{
//		return y;
//	}
//	void swap(bool p)
//	{
//		if(p){sprite.setTexture(texture2);}
//		else sprite.setTexture(texture);
//	}
//};
//
//
//enum Startend
//{
//	startP,
//	attackPS,
//	attackPB,
//	attackPSw,
//	endP,
//	startE,
//	attackES,
//	attackEB,
//	attackESw,
//	endE
//};
//
//enum OM
//{
//	game
//};
//
//
//bool fight(RenderWindow &window)
//{
//	srand(time(0));
//
//	Font font; 
//    font.loadFromFile("brushshopregular.otf");
//    Text text("", font, 20),text1("", font, 20),text2("", font,40);
//    text.setStyle(Text::Bold);
//	text2.setStyle(Text::Bold);
//
//	int y=4,x=0;
//	double px1,py1,pex1,pey1,spx,spy;
//	int y1=4,x1=8;
//	bool attack=true;
//
//	window.setKeyRepeatEnabled(false);
//
//	Startend zz=endE;
//
//	OM aa=game;
//
//	Texture texture;
//	texture.loadFromFile("ff/background.png");
//	Sprite sprite;
//	sprite.setTexture(texture);
//
//	Texture texture1;
//	texture1.loadFromFile("ff/kletkapola.png");
//	Sprite sprite1;
//	sprite1.setTexture(texture1);
//
//
//	bool choose=false,choosespell=false;
//	bool canUSw=true,canUS=true,canUM=true;//canUS-use suriken ;canUM - use magic  ; canUSw - use sword
//	bool victory=false,defeat=false;
//	bool ikeypressedsheild=false,ikeypressedsword=false,ikeypressedsuriken=false,ikeypressedbook=false;
//
//	Player player(x*50+174,50*y+174);
//	Evil evilplayer(x1*50+174,y1*50+174);
//
//	RectangleShape sh,sh1,sh2,sh3;
//	
//	 sh.setSize(sf::Vector2f(230,5));
//	 sh.setFillColor(Color::Blue);
//	
//	 sh1.setSize(sf::Vector2f(230,5));
//	 sh1.setFillColor(Color::Blue);
//	 
//	 sh2.setSize(sf::Vector2f(5,54));
//	 sh2.setFillColor(Color::Blue);
//	 
//	 sh3.setSize(sf::Vector2f(5,54));
//	 sh3.setFillColor(Color::Blue);
//
//	Spell spell;
//
//	Texture texture4;
//	texture4.loadFromFile("ff/pushbutton.png");
//	Sprite sprite4;
//	sprite4.setTexture(texture4);
//	
//	
//
//	Texture texture5;
//	texture5.loadFromFile("ff/victory.png");
//	Sprite sprite5;
//	sprite5.setTexture(texture5);
//	
//	Texture texture6;
//	texture6.loadFromFile("ff/defeat.png");
//	Sprite sprite6;
//	sprite6.setTexture(texture6);
//	
// 	Texture surik;
//	surik.loadFromFile("ff/suriken.png");
//	Sprite suriken;
//	suriken.setTexture(surik);
//	spell.icesuriken=false;
//
//	Texture spellbook_;
//	spellbook_.loadFromFile("ff/spellbook.png");
//	Sprite spellbook;
//	spellbook.setTexture(spellbook_);
//
//	Texture magicl;
//	magicl.loadFromFile("ff/nomagic.png");
//	Sprite nomagi;
//	nomagi.setTexture(magicl);
//	spell.nomagic=false;
//
//	Texture magicl1;
//	magicl1.loadFromFile("ff/lightstorm.png");
//	Sprite lightstorm;
//	lightstorm.setTexture(magicl1);
//	spell.lightstorm=false;
//
//	Texture firerain1;
//	firerain1.loadFromFile("ff/firerain.png");
//	Sprite firerain;
//	firerain.setTexture(firerain1);
//	spell.firerain=false;
//
//	
//	Texture vampirekiss1;
//	vampirekiss1.loadFromFile("ff/vampirekiss.png");
//	Sprite vampirekiss;
//	vampirekiss.setTexture(vampirekiss1);
//	spell.vampirekiss=false;
//
//	
//	Texture tornado1;
//	tornado1.loadFromFile("ff/tornado.png");
//	Sprite tornado;
//	tornado.setTexture(tornado1);
//	spell.tornado=false;
//
//	
//	Texture poison1;
//	poison1.loadFromFile("ff/poison.png");
//	Sprite poisonarrow;
//	poisonarrow.setTexture(poison1);
//	spell.poisonarrow=false;
//
//	Texture armor1;
//	armor1.loadFromFile("ff/armor.png");
//	Sprite armor;
//	armor.setTexture(armor1);
//	spell.armor=false;
//
//	
//	Texture crestaliz1;
//	crestaliz1.loadFromFile("ff/crestaliz.png");
//	Sprite crestaliz;
//	crestaliz.setTexture(crestaliz1);
//	spell.crestaliz=false;
//
//	Texture miss1;
//	miss1.loadFromFile("ff/miss.png");
//	Sprite miss;
//	miss.setTexture(miss1);
//	spell.miss=false;
//	
//	Texture attacks1;
//	attacks1.loadFromFile("ff/attack.png");
//	Sprite attacks;
//	attacks.setTexture(attacks1);
//	attacks.setPosition(200,24);
//
//	Texture reincarnation1;
//	reincarnation1.loadFromFile("ff/reincarnation.png");
//	spell.reincarnation=false;
//
//	spell.fastrun=false;
//
//	Texture pressed1;
//	pressed1.loadFromFile("ff/pressed.png");
//	Sprite pressed;
//	pressed.setTexture(pressed1);
//
//
//	//////////////////////////////////////
//
//    float CurrentFrame = 0,pere=0,Frame1=0;
//    Clock clock;
//	Clock clock1;
//
//    while (window.isOpen())
//    {
//		Vector2i pozition = Mouse :: getPosition(window);
//
//		switch(aa)
//		{
//		case game:{
//
//		float sec = clock1.restart().asSeconds();
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time = time / 800;
//		pere+=0.005*time;
//		if(pere>5)pere-=5;
//		//clock2.restart();
//		//time1 = time1 / 800;
//
//		
//
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//			{
//                window.close();
//			}
//			if(event.type == Event::MouseButtonPressed)
//			{
//				if(event.key.code == Mouse::Button::Left && !tut && choose==false && pozition.x>42 && pozition.x<138 && pozition.y>30 && pozition.y<30+96 )ikeypressedsheild=true;
//				if(event.key.code == Mouse::Button::Left && !tut && choose==false && canUSw && pozition.x>42 && pozition.x<138 && pozition.y>192 && pozition.y<192+96 )ikeypressedsword=true;
//				if(event.key.code == Mouse::Button::Left && !tut && choose==false && canUS && !spell.reincarnation && pozition.x>42 && pozition.x<138 && pozition.y>192+96 && pozition.y<192+192 )ikeypressedsuriken=true;
//				if(event.key.code == Mouse::Button::Left && !tut && choose==false && canUM && !spell.reincarnation && pozition.x>42 && pozition.x<138 && pozition.y>192+192 && pozition.y<192+192+96){ikeypressedbook=true;ifmagic=true;}
//			}
//			if(event.type == Event::KeyPressed)
//			{
//				if(event.key.code == Keyboard::N && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=8){choosespell=true;spell.nomagic=true;player.setMana(player.getMana()-8);non=true;ifmagic=false;}
//				if(event.key.code == Keyboard::S && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=6){choosespell=true;spell.lightstorm=true;player.setMana(player.getMana()-6);non1=true;ifmagic=false;}
//				if(event.key.code == Keyboard::R && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=11){choosespell=true;spell.firerain=true;player.setMana(player.getMana()-11);non2=true;ifmagic=false;}
//				if(event.key.code == Keyboard::K && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=11){choosespell=true;spell.vampirekiss=true;player.setMana(player.getMana()-11);non3=true;ifmagic=false;}
//				if(event.key.code == Keyboard::I && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=4){choosespell=true;spell.icesuriken=true;player.setMana(player.getMana()-4);non4=true;ifmagic=false;}
//				if(event.key.code == Keyboard::T && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=13){choosespell=true;spell.tornado=true;player.setMana(player.getMana()-13);non5=true;ifmagic=false;}
//				if(event.key.code == Keyboard::A && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=9){choosespell=true;spell.poisonarrow=true;player.setMana(player.getMana()-9);non6=true;ifmagic=false;ll=true;}
//				if(event.key.code == Keyboard::U && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=7){choosespell=true;spell.armor=true;player.setMana(player.getMana()-7);non7=true;ifmagic=false;}
//				if(event.key.code == Keyboard::C && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=15){choosespell=true;spell.crestaliz=true;player.setMana(player.getMana()-15);non8=true;ifmagic=false;}
//				if(event.key.code == Keyboard::M && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=9){choosespell=true;spell.miss=true;player.setMana(player.getMana()-9);non9=true;ifmagic=false;}
//				if(event.key.code == Keyboard::L && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=14){choosespell=true;spell.reincarnation=true;player.setMana(player.getMana()-14);non10=true;ifmagic=false;}
//				if(event.key.code == Keyboard::F && !tut && ifmagic && ikeypressedbook==false && player.getMana()>=12){choosespell=true;spell.fastrun=true;player.setMana(player.getMana()-12);non11=true;ifmagic=false;}
//				if(event.key.code == Keyboard::Escape && !tut && ikeypressedbook==false  && ifmagic){choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;zz=endE;ifmagic=false;}
//				if(event.key.code == Keyboard::Escape && tut){tut=false;}
//
//				
//			}
//        }
//
//				CurrentFrame += 0.005 * time;
//                if (CurrentFrame > 3)CurrentFrame -= 3;
//
//		//////////intreaction////////
//		if(player.getSurikens()==0)canUS=false;
//
//				miss.setPosition(player.getPPX(),player.getPPY());
//				if(spell.reincarnation){player.sprite.setTexture(reincarnation1);player.sprite.setTextureRect(IntRect(0,96,48,48));player.sprite.setOrigin(16,16);}//player.setPPX(x*50+174-16);player.setPPY(y*50+174-16);}
//				else {player.swap(vuborp);player.sprite.setTextureRect(IntRect(32,64,32,32));player.sprite.setScale(Vector2f(1.5f, 1.5f));player.sprite.setOrigin(0,0);}
//
//		for(int i=0;i<9;i++)
//		for(int j=0;j<9;j++)
//		{
//			fightmap[i][j]=3;
//			if(abs(j-x)+abs(i-y)<=z+1)fightmap[i][j]=0;
//			if(i==y && j==x)fightmap[i][j]=1;
//			if(i==y1 && j==x1)fightmap[i][j]=2;
//		}
//
//
//		if(!victory && !defeat){
//
//		int xx=int((pozition.x-174)/50);
//		int yy=int((pozition.y-174)/50);
//		
//		if( ikeypressedsheild &&  (zz==endE||(zz==startP && !choose)))
//		{
//			int addarm;
//			addarm=rand()%100;
//			if(addarm<45 && player.getArmor()<=2)player.setArmor(player.getArmor()+1);
//			ikeypressedsheild=false;
//			zz=endP;
//			player.setMana(player.getMana()+1);
//		}
//
//		ynee=false;
//		canUSw=false;
//		if(spell.reincarnation)z=3;
//		else z=1;
//
//		for(int i=y-z;i<y+z+1;i++)
//		{
//			for(int j=x-z;j<x+z+1;j++)
//			{
//				if(j==x1 && i==y1)ynee=true;
//			}
//		}
//		if(ynee)canUSw=true;
//
//		static int sdga;
//		if(ikeypressedsword && (zz==endE||(zz==startP && !choose)))
//		{
//			//attack=false;
//			canUSw=false;
//			ikeypressedsword=false;
//			zz=attackPSw;
//			sdga=rand()%100;
//		}
//		if(zz==attackPSw)
//		{	
//			static float swordTime = 0;
//			swordTime += sec;
//			if(sdga<65)attacks.setTextureRect(IntRect(0,0,80,40));
//			else attacks.setTextureRect(IntRect(0,40,80,40));
//			if(swordTime > 1)
//			{
//				if(!spell.reincarnation){
//				if(sdga<65 && evilplayer.getArmor()==0)evilplayer.setHelth(evilplayer.getHelth()-1);
//				if(sdga<65 && evilplayer.getArmor()>0)evilplayer.setArmor(evilplayer.getArmor()-1);
//				}
//				if(spell.reincarnation){
//				if(sdga<90 && evilplayer.getArmor()==0)evilplayer.setHelth(evilplayer.getHelth()-2);
//				if(sdga<90 && evilplayer.getArmor()==1){evilplayer.setArmor(evilplayer.getArmor()-1);evilplayer.setHelth(evilplayer.getHelth()-1);}
//				if(sdga<90 && evilplayer.getArmor()>1)evilplayer.setArmor(evilplayer.getArmor()-2);
//				}
//				swordTime = 0;
//				zz=endP;
//				player.setMana(player.getMana()+1);
//			}
//		}
//		static int sdf,sad,sdg;
//		if(ikeypressedsuriken && zz==endE)
//		{
//			suriken.setPosition(x*50+174+16,y*50+174+16);
//			suriken.setOrigin(16,16);
//			canUS=false;
//			ikeypressedsuriken=false;
//			zz=attackPS;
//			if(col==0)suriken.setColor(Color::White);
//			if(col>0){suriken.setColor(Color::Blue);}
//			player.setSurikens(player.getSurikens()-1);	
//			
//			sdf=rand()%100;
//			sdg=rand()%100;
//			if(sdf<50)sad=1;
//			else sad=0;
//		}
//		if(zz==attackPS)
//		{	
//			if(sdg<65)attacks.setTextureRect(IntRect(0,0,80,40));
//			else attacks.setTextureRect(IntRect(0,40,80,40));
//			static float surikenTime = 0;
//			surikenTime += sec;
//			suriken.setPosition(suriken.getPosition().x + 50*(x1-x) * sec,suriken.getPosition().y+ 50*(y1-y) * sec);
//			suriken.rotate(1440*sec);
//			if(surikenTime > 1)
//			{
//				surikenTime = 0;
//				if(abs(x-x1)+abs(y-y1)>4 && sdg<65)evilplayer.setHelth(evilplayer.getHelth()-sad);
//				else if(sdg<65)evilplayer.setHelth(evilplayer.getHelth()-1);
//				zz=endP;
//				player.setMana(player.getMana()+1);
//			}
//		}
//		if(ikeypressedbook && zz==endE)
//		{
//			spellbook.setPosition(0,0);
//			firerain.setPosition(x1*50+170,y1*50+16);
//			nomagi.setPosition(x1*50+145,y1*50+100);
//			lightstorm.setPosition(x1*50+170,y1*50+16);
//			vampirekiss.setPosition(x1*50+174,y1*50+150);
//			tornado.setPosition(x1*50+34,y1*50+14);
//			poisonarrow.setPosition(x*50+174+16,y*50+174+16);
//			armor.setPosition(x*50+174+16,y*50+160);
//			crestaliz.setPosition(x1*50+170,y1*50+164);
//			canUM=false;
//			ikeypressedbook=false;
//			zz=attackPB;
//			
//		}
//		if(zz==attackPB)
//		{
//			if(non)
//			{
//				Frame1 += 12 * sec;
//				int a=0,b=0;
//				a = int(Frame1) % 4;
//				b = int(Frame1) / 4;
//				nomagi.setTextureRect(IntRect(a*120,b*140,120,140));
//
//			if(Frame1>12){Frame1-=12;non=false;zz=endP;col4=0;player.setMana(player.getMana()+1);}
//			}
//			if(non1)
//			{
//				Frame1 += 6 * sec;
//				
//				if(Frame1>4)
//				{
//					Frame1-=4;spell.lightstorm=false;non1=false;zz=endP;
//					if(evilplayer.getArmor()==0)evilplayer.setHelth(evilplayer.getHelth()-1);
//					if(evilplayer.getArmor()>0)evilplayer.setArmor(evilplayer.getArmor()-1);
//					player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					lightstorm.setTextureRect(IntRect(int(Frame1)*59,0,59,210));
//				
//				}
//			}
//			if(non2)
//			{
//
//				Frame1 += 10 * sec;
//				
//				int a=0,b=0;
//				a = int(Frame1) % 5;
//				b = int(Frame1) / 5;
//
//				if(Frame1>10)
//				{
//					Frame1-=10;spell.firerain=false;non2=false;
//					if(evilplayer.getArmor()==0)evilplayer.setHelth(evilplayer.getHelth()-2);
//					if(evilplayer.getArmor()==1){evilplayer.setArmor(evilplayer.getArmor()-1);evilplayer.setHelth(evilplayer.getHelth()-1);}
//					if(evilplayer.getArmor()>1)evilplayer.setArmor(evilplayer.getArmor()-2);
//					zz=endP;
//					player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					firerain.setTextureRect(IntRect(a*63,b*80,63,80));
//					if(Frame1<5)firerain.setPosition(x1*50+170,firerain.getPosition().y+256*sec);
//				}
//			}
//			if(non3)
//			{
//
//				Frame1 += 5*sec;
//				int a=0;
//				a=int(Frame1);
//				if(Frame1>5)
//				{
//					Frame1-=5;spell.vampirekiss=false;non3=false;zz=endP;
//					evilplayer.setHelth(evilplayer.getHelth()-1);
//					player.setHelth(player.getHelth()+1);
//					player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					vampirekiss.setOrigin(24,13);
//					if(a%2==0){vampirekiss.setPosition(x1*50+198,y1*50+148);vampirekiss.setRotation(0);}
//					if(a%5==1){vampirekiss.setPosition(x1*50+198-30,y1*50+158);vampirekiss.setRotation(-45);}
//					if(a%5==3){vampirekiss.setPosition(x1*50+198+30,y1*50+168);vampirekiss.setRotation(45);}
//				}
//			}
//			if(non4)
//			{
//				col=1;
//				non4=false;zz=endE;canUS=true;canUM=false;canUSw=false;choose=false;
//				player.setMana(player.getMana()+1);
//			}
//			if(non5)
//			{
//
//				Frame1 += 6 * sec;
//				
//				int a=0,b=0;
//				a = int(Frame1) % 2;
//				b = int(Frame1) / 2;
//
//				if(Frame1>6)
//				{
//					Frame1-=6;spell.tornado=false;non5=false;zz=endE;canUS=true;canUM=false;canUSw=false;choose=false;
//					x1=8;y1=4;
//					player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					tornado.setTextureRect(IntRect(a*270,b*220,270,220));
//					tornado.setPosition(tornado.getPosition().x+50*(8-x1)*sec,tornado.getPosition().y+50*(4-y1)*sec);
//					evilplayer.setPEPX(evilplayer.getPEPX()+50*(8-x1)*sec);
//					evilplayer.setPEPY(evilplayer.getPEPY()+50*(4-y1)*sec);
//				}
//			}
//				if(non6)
//			{
//
//				if(ll)
//				{
//					sdf=rand()%100;
//					sdg=rand()%100;
//					sad=0;
//			if(abs(x-x1)+abs(y-y1)<=4)sad=1;
//			if(sdf<50  && abs(x-x1)+abs(y-y1)>4)sad=1;
//			ll=false;
//			arrow=true;
//				}
//				double ygol;
//				ygol=(sqrt(double((x1-x1)*(x1-x1)+(y-y1)*(y-y1)))/sqrt(double((x-x1)*(x-x1)+(y-y1)*(y-y1))));//x2==x1 y2==y
//				poisonarrow.setRotation((((ygol))*180)/pi);
//			static float arrowTime = 0;
//			arrowTime += sec;
//			if(arrowTime < 1)poisonarrow.setTextureRect(IntRect(0,0,35,34));
//			if(arrowTime >1 && arrowTime <2)
//			{
//				poisonarrow.setTextureRect(IntRect(35,0,35,34));
//				poisonarrow.setPosition(poisonarrow.getPosition().x + 50*(x1-x) * sec,poisonarrow.getPosition().y+ 50*(y1-y) * sec);
//				//poisonarrow.setRotation(sqrt(double((x-x1)*(x-x1)+(y-y1)*(y-y1)))/sqrt(double((8-x1)*(8-x1)+(4-y1)*(4-y1))));
//			}
//			if(arrowTime > 2)
//			{
//				arrowTime = 0;
//				if(sad==1 && sdg<30)col5=0;
//				non6=false;zz=endP;
//				player.setMana(player.getMana()+1);
//				arrow=false;
//			}
//			}
//			if(non7)
//			{
//				Frame1 += 4 * sec;
//				
//				if(Frame1>4)
//				{
//					Frame1-=4;spell.armor=false;non7=false;zz=endP;player.setArmor(player.getArmor()+3);
//					player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					armor.setTextureRect(IntRect(int(Frame1)*32,0,32,36));
//					armor.setPosition(armor.getPosition().x,armor.getPosition().y-15*sec);
//				}
//			}
//			if(non8)
//			{
//				Frame1 += 0.5 * sec;
//				
//				if(Frame1>5)
//				{
//					Frame1-=5;spell.crestaliz=false;non8=false;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;zz=endE;prop=true;player.setMana(player.getMana()+1);
//				}
//				else
//				{
//					crestaliz.setTextureRect(IntRect(int(Frame1)*64,0,64,57));
//				}
//			}
//			if(non9)
//			{
//				non9=false;zz=endP;col2=0;player.setMana(player.getMana()+1);
//			}
//			if(non10)
//			{
//				non10=false;zz=endP;col3=0;player.setMana(player.getMana()+1);
//			}
//			if(non11)
//			{
//				if((fightmap[yy][xx]==0 || fightmap[yy][xx]==3) && (Mouse::isButtonPressed(Mouse::Button::Left)) && ef(player.getPPX(),px1) && ef(player.getPPY(),py1) && pozition.x>164 && pozition.y>164)
//			{
//				x=xx;
//				y=yy;
//				canUS=false;
//				canUM=false;
//				canUSw=true;
//				fast=true;
//			}
//			px1=x*50+174;
//			py1=y*50+174;
//
//		if(fast)
//		{
//		if(px1>player.getPPX())player.setPPX(player.getPPX()+256*sec);
//		if(px1<player.getPPX())player.setPPX(player.getPPX()-256*sec);
//		if(py1>player.getPPY())player.setPPY(player.getPPY()+256*sec);
//		if(py1<player.getPPY())player.setPPY(player.getPPY()-256*sec);
//
//		if(ef(player.getPPX(),px1) && ef(player.getPPY(),py1)){non11=false;spell.fastrun=false;fast=false;zz=endP;player.setMana(player.getMana()+1);}
//		}
//			}
//		}
//		if(evilplayer.getHelth()==0)victory=true;
//
//			if(!victory && !defeat && fightmap[yy][xx]==0 && !tut && zz==endE &&(Mouse::isButtonPressed(Mouse::Button::Left))&&(abs(xx-x)+abs(yy-y)<=z+1)&& ef(player.getPPX(),px1) && ef(player.getPPY(),py1) && pozition.x>164 && pozition.y>164)
//			{
//				x=xx;
//				y=yy;
//				choose=true;
//				canUS=false;
//				canUM=false;
//				canUSw=true;
//				zz=startP;
//			}
//			px1=x*50+174;
//			py1=y*50+174;
//
//		if(zz==startP)
//		{
//		if(px1>player.getPPX())player.setPPX(player.getPPX()+128*sec);
//		if(px1<player.getPPX())player.setPPX(player.getPPX()-128*sec);
//		if(py1>player.getPPY())player.setPPY(player.getPPY()+128*sec);
//		if(py1<player.getPPY())player.setPPY(player.getPPY()-128*sec);
//
//		if(ef(player.getPPX(),px1) && ef(player.getPPY(),py1) && choose){choose=false;}
//		}
//
//		if((zz==endP || zz==attackESw || zz==attackES || zz==attackEB) && !victory)
//		{
//			suriken.setColor(Color::White);
//			if(zz==endP){turns=chooses(player.getMana(),evilplayer.getMana(),player.getHelth(),evilplayer.getHelth(),player.getArmor(),evilplayer.getArmor(),x,y,x1,y1,evilplayer.getSurikens(),prop,spell.icesuriken,spell.nomagic);
//			if(spell.icesuriken)col++;
//			if(spell.miss)col2++;
//			if(spell.reincarnation)col3++;
//			if(spell.nomagic)col4++;
//			if(spell.poisonarrow)col5++;
//			if(col5<=2 && col5!=0 && spell.poisonarrow)evilplayer.setHelth(evilplayer.getHelth()-1);
//			}
//			if(turns==0){choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;zz=endE;prop=false;evilplayer.setMana(evilplayer.getMana()+4);}
//			if(turns==1)
//			{
//				static int asd,aas=27;
//				if(zz!=attackESw)
//				{
//					int asd=rand()%100;
//					if(spell.miss && col2<2){aas=rand()%100;}
//					zz=attackESw;
//					if(asd<65 && aas<30)attacks.setTextureRect(IntRect(0,0,80,40));
//					else attacks.setTextureRect(IntRect(0,40,80,40));
//					att=true;
//				}
//				else{
//				
//				int a=0,b=0;
//				turn(x,y,x1,y1,a,b,spell.icesuriken);
//
//				x1+=a;
//				y1+=b;
//
//			/*static float swordTime = 0;
//			swordTime += sec;*/
//		
//			if(aas<30 && asd<65 && ((x1-1==x && y1-1==y)||(x1+1==x && y1-1==y)||(x1==x && y1-1==y)||(x1-1==x && y1==y)||(x1+1==x && y1==y)||(x1-1==x && y1+1==y)||(x1==x && y1+1==y)||(x1+1==x && y1+1==y)))
//			{
//						if(player.getArmor()==0)player.setHelth(player.getHelth()-1);
//						else player.setArmor(player.getArmor()-1);
//			}
//				pex1=x1*50+174;
//				pey1=y1*50+174;
//				evilplayer.setMana(evilplayer.getMana()+2);
//
//				zz=startE;
//				}
//			}
//			if(turns==2)
//			{
//			static int asd,sdg,aas=27;
//			
//			if(zz!=attackES)
//			{
//			suriken.setPosition(x1*50+174+16,y1*50+174+16);
//			suriken.setOrigin(16,16);
//			
//			asd=rand()%100;
//			sdg=rand()%100;
//			if(spell.miss && col2<2){aas=rand()%100;}
//			evilplayer.setSurikens(evilplayer.getSurikens()-1);
//			evilplayer.setMana(evilplayer.getMana()+2);
//			zz=attackES;
//			}
//			else{
//				if(sdg<65 && aas<30)attacks.setTextureRect(IntRect(0,0,80,40));
//				else attacks.setTextureRect(IntRect(0,40,80,40));
//				static float surikenTime = 0;
//				surikenTime += sec;
//				suriken.setPosition(suriken.getPosition().x + 50*(x-x1) * sec,suriken.getPosition().y+ 50*(y-y1) * sec);
//				suriken.rotate(1440*sec);
//				if(surikenTime > 1)
//				{
//					surikenTime = 0;
//					if(sdg<65 && player.getArmor()==0)player.setHelth(player.getHelth()-1);
//					if(sdg<65 && player.getArmor()>0)player.setArmor(player.getArmor()-1);
//					choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;zz=endE;
//				}
//			}
//
//			}
//			if(turns>=3 && turns<=6)
//			{
//				if(zz!=attackEB)
//				{
//					zz=attackEB;
//				}
//				if(zz==attackEB)
//				{
//					static bool yes=true;
//					if(turns==3)
//					{
//						if(yes){evilplayer.setMana(evilplayer.getMana()-11);yes=false;spell.vampirekiss=true;}
//						if(!yes)
//						{
//							Frame1 += 5*sec;
//							int a=0;
//							a=int(Frame1);
//							if(Frame1>5)
//							{
//								Frame1-=5;spell.vampirekiss=false;zz=endE;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;
//								evilplayer.setHelth(evilplayer.getHelth()+1);
//								player.setHelth(player.getHelth()-1);
//								evilplayer.setMana(evilplayer.getMana()+2);
//							}
//							else
//							{
//								vampirekiss.setOrigin(24,13);
//								if(a%2==0){vampirekiss.setPosition(x*50+198,y*50+148);vampirekiss.setRotation(0);}
//								if(a%5==1){vampirekiss.setPosition(x*50+198-30,y*50+158);vampirekiss.setRotation(-45);}
//								if(a%5==3){vampirekiss.setPosition(x*50+198+30,y*50+168);vampirekiss.setRotation(45);}
//							}
//						}
//					}
//					if(turns==4)
//					{
//						if(yes){evilplayer.setMana(evilplayer.getMana()-11);yes=false;spell.firerain=true;firerain.setPosition(x*50+170,y*50+16);}
//						if(!yes)
//						{
//							Frame1 += 10 * sec;
//						
//							int a=0,b=0;
//							a = int(Frame1) % 5;
//							b = int(Frame1) / 5;
//	
//							if(Frame1>10)
//							{
//								Frame1-=10;spell.firerain=false;yes=true;zz=endE;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;
//								if(player.getArmor()==0)player.setHelth(player.getHelth()-2);
//								if(player.getArmor()==1){player.setArmor(player.getArmor()-1);player.setHelth(player.getHelth()-1);}
//								if(player.getArmor()>1)player.setArmor(player.getArmor()-2);
//								evilplayer.setMana(evilplayer.getMana()+2);
//							}
//							else
//							{
//								firerain.setTextureRect(IntRect(a*63,b*80,63,80));
//								if(Frame1<5)firerain.setPosition(x*50+170,firerain.getPosition().y+256*sec);
//							}
//						}
//					}
//					if(turns==5)
//					{
//						if(yes){evilplayer.setMana(evilplayer.getMana()-8);yes=false;}
//						if(!yes)
//						{
//							evilplayer.setMana(evilplayer.getMana()+16);yes=true;zz=endE;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;
//						}
//					}
//					if(turns==6)
//					{	
//						if(yes){evilplayer.setMana(evilplayer.getMana()-3);yes=false;spell.armor=true;armor.setPosition(x1*50+174+16,y1*50+160);}
//						if(!yes)
//						{
//							Frame1 += 4 * sec;
//	
//							if(Frame1>4)
//							{
//								Frame1-=4;spell.armor=false;yes=true;zz=endE;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;evilplayer.setArmor(evilplayer.getArmor()+1);
//							}
//							else
//							{
//								armor.setTextureRect(IntRect(int(Frame1)*32,0,32,36));
//								armor.setPosition(armor.getPosition().x,armor.getPosition().y-15*sec);
//							}
//						}			
//					}
//				}
//			}
//			if(turns==7)
//			{
//			int a=0,b=0;
//			turn(x,y,x1,y1,a,b,spell.icesuriken);
//
//				x1+=a;
//				y1+=b;
//
//				int addarm;
//				addarm=rand()%100;
//				if(addarm<35 && evilplayer.getArmor()<=2)evilplayer.setArmor(evilplayer.getArmor()+1);
//
//			pex1=x1*50+174;
//			pey1=y1*50+174;
//			evilplayer.setMana(evilplayer.getMana()+2);
//			zz=startE;
//			}
//			if(turns==8)
//			{
//				evilplayer.setMana(evilplayer.getMana()-10);
//				evilplayer.setHelth(evilplayer.getHelth()+3);
//				zz=endE;
//			}
//		}
//		if(zz==startE && !victory && !defeat)
//		{
//		static double time=0;
//		time+=sec;
//		if(pex1>evilplayer.getPEPX())evilplayer.setPEPX(evilplayer.getPEPX()+128*sec);
//		if(pex1<evilplayer.getPEPX())evilplayer.setPEPX(evilplayer.getPEPX()-128*sec);
//		if(pey1>evilplayer.getPEPY())evilplayer.setPEPY(evilplayer.getPEPY()+128*sec);
//		if(pey1<evilplayer.getPEPY())evilplayer.setPEPY(evilplayer.getPEPY()-128*sec);
//		
//		if(ef(evilplayer.getPEPX(),pex1) && ef(evilplayer.getPEPY(),pey1) && time>1){time=0;choosespell=false;canUS=true;canUM=true;canUSw=true;attack=true;zz=endE;if(att)att=false;}
//			
//		}
//
//		if(col==5){spell.icesuriken=false;col=0;}
//		if(col3==5)spell.reincarnation=false;
//		if(col2==4)spell.miss=false;
//		if(col4==3){spell.nomagic=false;col4=0;}
//		if(col5==2){spell.poisonarrow=false;col5=0;}
//
//		if(player.getHelth()==0)defeat=true;
//		
//		}
//		if(victory)
//		{
//			sprite5.setPosition(0,0);
//		}
//		if(defeat)
//		{
//			sprite6.setPosition(0,0);
//		}
//		//////////////interection evil////////////
//		
//		///////////draw////////////
//		window.clear();
//		window.draw(sprite);
//		if(!victory && !defeat){
//		if(pozition.x>42 && pozition.x<138 && pozition.y>30 && pozition.y<30+96)
//		{
//			sprite4.setTextureRect(IntRect(288,0,96,96));
//			sprite4.setPosition(42,30);
//			window.draw(sprite4);
//		}
//		if(canUSw && pozition.x>42 && pozition.x<138 && pozition.y>192 && pozition.y<192+96)
//		{
//			sprite4.setTextureRect(IntRect(192,0,96,96));
//			sprite4.setPosition(42,192);
//			window.draw(sprite4);
//		}
//		if(!canUSw)
//		{
//			sprite4.setTextureRect(IntRect(192,96,96,96));
//			sprite4.setPosition(42,192);
//			window.draw(sprite4);
//		}
//		if(canUS && pozition.x>42 && pozition.x<138 && pozition.y>192+96 && pozition.y<192+192)
//		{
//			sprite4.setTextureRect(IntRect(96,0,96,96));
//			sprite4.setPosition(42,192+96);
//			window.draw(sprite4);
//		}
//		if(!canUS || spell.reincarnation)
//		{
//			sprite4.setTextureRect(IntRect(96,96,96,96));
//			sprite4.setPosition(42,192+96);
//			window.draw(sprite4);
//		}
//		if(canUM && pozition.x>42 && pozition.x<138 && pozition.y>192+192 && pozition.y<192+192+96)
//		{
//			sprite4.setTextureRect(IntRect(0,0,96,96));
//			sprite4.setPosition(42,192+192);
//			window.draw(sprite4);
//		}
//		if(!canUM || spell.reincarnation)
//		{
//			sprite4.setTextureRect(IntRect(0,96,96,96));
//			sprite4.setPosition(42,192+192);
//			window.draw(sprite4);
//		}
//		}
//
//		for(int i=0;i<9;i++)
//			for(int j=0;j<9;j++)
//			{
//				if(fightmap[i][j]==0 && (zz==endE || (zz==startP && choose)))
//				{
//					
//					sprite1.setTextureRect(IntRect(48,0,48,48));
//					sprite1.setPosition(j*50+174,i*50+180);
//					window.draw(sprite1);
//				}
//				if(fightmap[i][j]==1)
//				{
//					
//					sprite1.setTextureRect(IntRect(0,0,48,48));
//					sprite1.setPosition(j*50+174,i*50+180);
//					window.draw(sprite1);
//				}
//				if(fightmap[i][j]==2)
//				{
//					
//					sprite1.setTextureRect(IntRect(96,0,48,48));
//					sprite1.setPosition(j*50+174,i*50+180);
//					window.draw(sprite1);
//				}
//				if((fightmap[i][j]==0 || fightmap[i][j]==3) && spell.fastrun && (zz==attackPB))
//				{
//					sprite1.setTextureRect(IntRect(144,0,48,48));
//					sprite1.setPosition(j*50+174,i*50+180);
//					window.draw(sprite1);
//				}
//			}
//		
//		player.sprite.setPosition(player.getPPX(),player.getPPY());
//		window.draw(player.sprite);
//		evilplayer.sprite.setPosition(evilplayer.getPEPX(),evilplayer.getPEPY());
//		window.draw(evilplayer.sprite);
//		if(zz==attackPSw || att || zz==attackPS || zz==attackES)
//		{
//			window.draw(attacks);
//		}
//		if(zz==attackPS || zz==attackES)
//		{
//			window.draw(suriken);
//		}
//		if(spell.miss)window.draw(miss);
//		if(zz==attackPB || zz==attackEB)
//		{
//			if(!choosespell && zz==attackPB)window.draw(spellbook);
//			if(spell.nomagic)window.draw(nomagi);
//			if(spell.lightstorm)window.draw(lightstorm);
//			if(spell.firerain)window.draw(firerain);
//			if(spell.vampirekiss)window.draw(vampirekiss);
//			if(spell.tornado)window.draw(tornado);
//			if(spell.poisonarrow && arrow)window.draw(poisonarrow);
//			if(spell.armor)window.draw(armor);
//			if(spell.crestaliz)window.draw(crestaliz);
//		}
//
//		ostringstream arp_,hep_,are_,hee_,mp_,me_;
//
//		
//		text.setColor(Color::Blue);
//		mp_ << player.getMana();
//		text.setString(mp_.str());
//		text.setPosition(340,60);
//		window.draw(text);
//		
//		text.setColor(Color::White);
//		text.setString("0");
//		text.setPosition(375,25);
//		window.draw(text);
//		if(player.getArmor()>0){
//		text.setColor(Color::Green);
//		arp_ << player.getArmor();
//		text.setString("+ " + arp_.str());
//		text.setPosition(390,25);
//		window.draw(text);
//		}
//
//		text.setColor(Color::White);
//		text.setString("3");
//		text.setPosition(440,25);
//		window.draw(text);
//		if(player.getHelth()<3)
//		{
//		text.setColor(Color::Red);
//		hep_<< 3-player.getHelth();
//		text.setString("- " + hep_.str());
//		text.setPosition(455,25);
//		window.draw(text);
//		}
//		if(player.getHelth()>3)
//		{
//		text.setColor(Color::Green);
//		hep_<< player.getHelth()-3;
//		text.setString("+ " + hep_.str());
//		text.setPosition(455,25);
//		window.draw(text);
//		}
//
//		text.setColor(Color::Blue);
//		me_ << evilplayer.getMana();
//		text.setString(me_.str());
//		text.setPosition(490,60);
//		window.draw(text);
//
//		text.setColor(Color::White);
//		text.setString("0");
//		text.setPosition(520,25);
//		window.draw(text);
//		if(evilplayer.getArmor()>0)
//		{
//		text.setColor(Color::Green);
//		are_<< evilplayer.getArmor();
//		text.setString("+ " + are_.str());
//		text.setPosition(535,25);
//		window.draw(text);
//		}
//
//		text.setColor(Color::White);
//		text.setString("7");
//		text.setPosition(590,25);
//		window.draw(text);
//		if(evilplayer.getHelth()<7)
//		{
//		text.setColor(Color::Red);
//		hee_<< 7-evilplayer.getHelth();
//		text.setString("- " + hee_.str());
//		text.setPosition(605,25);
//		window.draw(text);
//		}
//		if(evilplayer.getHelth()>7)
//		{
//		text.setColor(Color::Green);
//		hee_<< evilplayer.getHelth()-7;
//		text.setString("+ " + hee_.str());
//		text.setPosition(605,25);
//		window.draw(text);
//		}
//		if(victory)
//		{
//			window.draw(sprite5);
//			if(pozition.x>=200 && pozition.x<=430 && pozition.y>=500 && pozition.y<=554)
//				{ 
//					sh.setPosition(200,500);
//					sh1.setPosition(200,549);
//					sh2.setPosition(200,500);
//					sh3.setPosition(425,500);
//
//					window.draw(sh);
//					window.draw(sh1);
//					window.draw(sh2);
//					window.draw(sh3);
//					if(Mouse::isButtonPressed(Mouse::Left)){return true;}
//				}
//		}
//		if(defeat)
//		{
//			window.draw(sprite6);
//			if(pozition.x>=200 && pozition.x<=430 && pozition.y>=500 && pozition.y<=554)
//				{ 
//					sh.setPosition(200,500);
//					sh1.setPosition(200,549);
//					sh2.setPosition(200,500);
//					sh3.setPosition(425,500);
//
//					window.draw(sh);
//					window.draw(sh1);
//					window.draw(sh2);
//					window.draw(sh3);
//					if(Mouse::isButtonPressed(Mouse::Left)){return false;}
//				}
//		}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=150 && pozition.y<=150+40){pressed.setTextureRect(IntRect(1*90,1*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=200 && pozition.y<=200+40){pressed.setTextureRect(IntRect(0*90,2*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=250 && pozition.y<=250+40){pressed.setTextureRect(IntRect(0*90,0*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=300 && pozition.y<=300+40){pressed.setTextureRect(IntRect(0*90,4*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=350 && pozition.y<=350+40){pressed.setTextureRect(IntRect(0*90,1*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=80 && pozition.x<=80+200 && pozition.y>=400 && pozition.y<=400+40){pressed.setTextureRect(IntRect(0*90,3*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=150 && pozition.y<=150+40){pressed.setTextureRect(IntRect(0*90,5*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=200 && pozition.y<=200+40){pressed.setTextureRect(IntRect(1*90,2*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=250 && pozition.y<=250+40){pressed.setTextureRect(IntRect(1*90,5*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=300 && pozition.y<=300+40){pressed.setTextureRect(IntRect(1*90,3*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=350 && pozition.y<=350+40){pressed.setTextureRect(IntRect(1*90,4*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		if(!choosespell && zz==attackPB && pozition.x>=350 && pozition.x<=350+200 && pozition.y>=400 && pozition.y<=400+40){pressed.setTextureRect(IntRect(1*90,0*40,90,40));pressed.setPosition(pozition.x,pozition.y);window.draw(pressed);}
//		
//		window.display();
//		
//	}
//	break;
//	
//	}
//	}
//    return 0;
//}	
//
