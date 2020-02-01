#ifndef CROSSPIPE_H_INCLUDED
#define CROSSPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
#include <SFML/Graphics.hpp>
class Cross : public Pipe
{
public:
    explicit Cross(unsigned short int R = 0);
    void fill_in();
    virtual char get_name () override;
    virtual void Rotate() override;
    virtual void Set_rotation(unsigned short int) override;
    virtual void Set_changing_rotation (unsigned short int) override;
private:
     sf::Texture Pictxt;
};


#endif // CROSSPIPE_H_INCLUDED
