#include<Sfml\Graphics.hpp>
using namespace sf;
View view1;


View cordinate1(float x,float y)
{
	float a=x,b=y;
	if(x<160)a=160;
	if(x>800)a=800;
	if(y<160)b=160;
	if(y>480)b=480;

	view1.setCenter(a,b);
	return view1;
}
