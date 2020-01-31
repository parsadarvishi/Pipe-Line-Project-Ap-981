#ifndef LINEPIPE_H_INCLUDED
#define LINEPIPE_H_INCLUDED
#include "Pipe.h"
#include <string>
#include <SFML/GpuPreference.hpp>

class Line : public Pipe
{
public :
    explicit Line(unsigned short int R = 0);
    void fill_in();
    virtual std::string get_name () override;
private:
    sf::Texture Pictxt;
};

#endif // LINEPIPE_H_INCLUDED
