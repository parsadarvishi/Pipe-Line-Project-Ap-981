#ifndef LINEPIPE_H_INCLUDED
#define LINEPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
#include <SFML/Graphics.hpp>

class Line : public Pipe
{
public :
    explicit Line(unsigned short int R = 0);
    void fill_in();
    virtual char get_name () override;
    virtual void Rotate() override;
    virtual void Set_rotation(unsigned short int ) override ;
    virtual void Set_changing_rotation (unsigned short int) override;
private:
    sf::Texture Pictxt;
};

#endif // LINEPIPE_H_INCLUDED
