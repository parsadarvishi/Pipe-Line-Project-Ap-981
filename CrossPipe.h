#ifndef CROSSPIPE_H_INCLUDED
#define CROSSPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
class Cross : public Pipe
{
public:
    explicit Cross(unsigned short int R = 0);
    void fill_in();
    virtual std::string get_name () override;
};


#endif // CROSSPIPE_H_INCLUDED
