#include "TurnPipe.h"
#include <string>
using namespace std;
Turn::Turn(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
}

void Turn::fill_in()
{
    Pictxt.loadFromFile("Assets/Turn.png");
    picture.setTexture(Pictxt);
    picture.setOrigin(54,54);
}
string Turn::get_name()
{
    return "T";
}
