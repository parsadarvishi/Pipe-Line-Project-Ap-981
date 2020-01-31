#include "LinePipe.h"
using namespace std;
 Line::Line(unsigned short int R)
 {
     Set_rotation(R);
     Set_changing_rotation(R);
 }
void Line::fill_in()
{
    Pictxt.loadFromFile("Assets/Line.png");
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
string Line::get_name()
{
    return "L";
}
