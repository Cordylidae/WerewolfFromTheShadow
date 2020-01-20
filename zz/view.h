#include<Sfml\Graphics.hpp>
using namespace sf;
View view;


View cordinate(float x,float y)
{
	float a=x,b=y;
	if(x<160)a=160;
	if(x>1312)a=1312;
	if(y<160)b=160;
	if(y>800)b=800;

	view.setCenter(a,b);
	return view;
}
