#include "Pipe.h"
Pipe::Pipe(unsigned short int R)
{
    Set_rotation(R);
    Set_changing_rotation(R);
}
void Pipe::Set_rotation(unsigned short int R)
{
    if ( R == 0 || R == 1 || R == 2 || R == 3)
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
