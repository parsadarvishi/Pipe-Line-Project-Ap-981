#ifndef TURNPIPE_H_INCLUDED
#define TURNPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>

class Turn : public Pipe
{
public:
    explicit Turn(unsigned short int R = 0);
    void fill_in();
    virtual std::string get_name () override;
};




#endif // TURNPIPE_H_INCLUDED
