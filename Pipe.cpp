#include "Pipe.h"
Pipe::Pipe(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
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
void Pipe::Set_changing_rotation(unsigned short int R)
{
    changing_rotation = R;
}
unsigned short int Pipe::get_changing_rotation ()
{
    return changing_rotation;
}
void Pipe::Rotate()
{
    changing_rotation + 90;
    if (changing_rotation == 360 )
        changing_rotation = 0;
}
