#include "CrossPipe.h"
#include <string>
Cross::Cross(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
}
void Cross::fill_in()
{
    Pictxt.loadFromFile("Assets/Cross.png");
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
std::string Cross::get_name()
{
    return "C";
}
