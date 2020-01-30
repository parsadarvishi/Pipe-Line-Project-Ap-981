#ifndef LINEPIPE_H_INCLUDED
#define LINEPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
class Line : public Pipe
{
public :
    explicit Line(unsigned short int R = 0);
    void fill_in();
    string get_name ();

};


#endif // LINEPIPE_H_INCLUDED