#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
#include <string>
class Pipe
{
public :
    virtual void fill_in () = 0 ;
    explicit Pipe(unsigned short int R = 0);
    void Set_rotation (unsigned short int);
    unsigned short int get_rotation ();
//    virtual string get_name () = 0 ;
protected:
    unsigned short int rotation;
};

#endif // PIPE_H_INCLUDED
