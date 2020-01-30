#include <iostream>
#include "Graph.h"
#include "Generation_core.h"
#include <map>
#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <array>
using namespace std;

int main()
{
    map <int , Pipe*> Board;
    Generate_puzzle G;
    Board = G.find_an_answer();
    array < array <Pipe* , 5 > , 5> Gamefinall;
    unsigned short int counter = 0;
    for (int i = 0 ; i < 4  ; i ++)
    {
        for (int j = 0 ; j < 4 ; j++)
        {
            Gamefinall.at(i).at(j) = Board[counter];
            counter++;
        }
    }
    sf::RenderWindow win(sf::VideoMode(200, 200), "SFML Test");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }

        win.clear();
        win.draw(shape);
        win.display();
    }
    return 0;
}
