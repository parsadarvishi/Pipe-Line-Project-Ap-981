#include "Pipe.h"
Pipe::Pipe(unsigned short int R)
{
    Set_rotation(R);
}
void Pipe::Set_rotation(unsigned short int R)
{
    if ( R == 0 || R == 90 || R == 180 || R == 270)
    rotation = R;
}
unsigned short int Pipe::get_rotation()
{
    return rotation;
}
