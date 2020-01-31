#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
#include <string>
#include <SFML/Graphics.hpp>
class Pipe
{
public :
    virtual void fill_in () = 0 ;
    explicit Pipe(unsigned short int R = 0);
    void Set_rotation (unsigned short int) ;
    void Set_changing_rotation (unsigned short int);
    unsigned short int get_changing_rotation ();
    unsigned short int get_rotation ();
    virtual char get_name () = 0 ;
    virtual void Rotate() = 0 ;
    sf::Sprite picture;
protected:
     unsigned short int rotation;
    unsigned short int changing_rotation;
};

#endif // PIPE_H_INCLUDED
