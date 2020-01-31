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
    cout << "Turn";
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
    if(changing_rotation == 3)
        Set_changing_rotation(0);
}
