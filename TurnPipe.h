#ifndef TURNPIPE_H_INCLUDED
#define TURNPIPE_H_INCLUDED
#include "Pipe.h"
class Turn : public Pipe
{
public:
    explicit Turn(unsigned short int R = 0);
    void fill_in();
    string get_name ();
};


#endif // TURNPIPE_H_INCLUDED
