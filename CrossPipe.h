#ifndef CROSSPIPE_H_INCLUDED
#define CROSSPIPE_H_INCLUDED
#include "Pipe.h"
class Cross : public Pipe
{
public:
    explicit Cross(unsigned short int R = 0);
    void fill_in();
    string get_name ();
};

#endif // CROSSPIPE_H_INCLUDED
