#include "TurnPipe.h"
#include <string>
using namespace std;
Turn::Turn(unsigned short int R)
{
    Set_rotation(R);
}

void Turn::fill_in()
{

}
string Turn::get_name()
{
    return "T";
}
