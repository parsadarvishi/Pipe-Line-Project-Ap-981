#include "CrossPipe.h"
#include <string>
Cross::Cross(unsigned short int R)
{
    Set_rotation(R);
}
void Cross::fill_in()
{

}
std::string Cross::get_name()
{
    return "C";
}
