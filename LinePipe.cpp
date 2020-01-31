#include "LinePipe.h"
#include <iostream>
using namespace std;
 Line::Line(unsigned short int R)
 {
     Set_rotation(R);
     Set_changing_rotation(R);
 }
void Line::fill_in()
{
    cout << "Line";
    if(!Pictxt.loadFromFile("Assets/Line.png"))
        cout << "Cannot load pic into program Line class" << endl;
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
char Line::get_name()
{
    return 'L';
}
void Line::Rotate()
{
    changing_rotation++;
    if(changing_rotation == 2)
        Set_changing_rotation(0);
}
