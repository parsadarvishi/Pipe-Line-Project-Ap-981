#ifndef TURNPIPE_H_INCLUDED
#define TURNPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
#include <SFML/Graphics.hpp>
class Turn : public Pipe
{
public:
    explicit Turn(unsigned short int R = 0);
    void fill_in();
    virtual char get_name () override;
    virtual void Rotate() override;
private:
     sf::Texture Pictxt;
};




#endif // TURNPIPE_H_INCLUDED
