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
    cout << "Cross";
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
    if(changing_rotation == 2)
    Set_changing_rotation(0);
}
