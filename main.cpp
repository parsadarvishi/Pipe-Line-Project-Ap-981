#include <iostream>
#include "Graph.h"
#include "Generation_core.h"
#include <map>
#include "Pipe.h"
#include <SFML/Graphics.hpp>
#include <array>
using namespace std;
using namespace sf;
int main()
{
    Vector2f offset(170, 170);
    int length = 108;
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
       RenderWindow window(VideoMode(780, 780), "Pipe Line");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
                if(event.key.code == Mouse::Left)
                {
                    Vector2i pos = Mouse::getPosition(window) + Vector2i(length/2, length/2) - Vector2i(offset);
                    pos/=length;
                    if(pos.x > 4 || pos.x < 0 || pos.y < 0 || pos.y > 4 || Mouse::getPosition(window).y < 117 || Mouse::getPosition(window).x < 117)
                    {
                        continue;
                    }
                    Gamefinall[pos.y][pos.x]->Rotate();
                }
        }

        window.clear(Color(255, 255, 255));

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                Pipe* p = Gamefinall[i][j];
                p->picture.setTextureRect(IntRect(0, 0, length, length));
                p->picture.setRotation( p->get_changing_rotation());
                p->picture.setPosition(j * length, i *length);
                p->picture.move(offset);
                window.draw(p->picture);
            }
        }

        window.display();
    }
    return 0;
}
