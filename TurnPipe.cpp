#include "TurnPipe.h"
#include <string>
#include <iostream>
using namespace std;
Turn::Turn(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
}

void Turn::fill_in()
{
    if(!Pictxt.loadFromFile("Assets/Turn.png"))
         cout << "Cannot load pic into program Turn class" << endl;
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
char Turn::get_name()
{
    return 'T';
}
void Turn::Rotate()
{
    changing_rotation++;
    if(changing_rotation == 4)
        Set_changing_rotation(0);
}
void Turn::Set_rotation(unsigned short int R)
{
    if ( R == 0 || R == 1 || R == 2 || R == 3 )
    {
        rotation = R;
    }
}
void Turn::Set_changing_rotation (unsigned short int R)
{
    changing_rotation = R;
}
