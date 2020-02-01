#include "CrossPipe.h"
#include <string>
#include <iostream>
using namespace std;
Cross::Cross(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
}
void Cross::fill_in()
{
    if(!Pictxt.loadFromFile("Assets/Cross.png"))
     cout << "Cannot load pic into program Cross class" << endl;
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
char Cross::get_name()
{
    return 'C';
}
void Cross::Rotate()
{
    changing_rotation++;
    if(changing_rotation == 1)
    Set_changing_rotation(0);
}
void Cross::Set_rotation(unsigned short int R)
{
    if ( R == 0)
        rotation = 0;
}
void Cross::Set_changing_rotation (unsigned short int R)
{
    changing_rotation = 0;
}
