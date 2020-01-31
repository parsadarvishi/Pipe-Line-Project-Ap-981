#include <iostream>
#include "Graph.h"
#include "Generation_core.h"
#include <map>
#include "Pipe.h"
#include  "LinePipe.h"
#include  "TurnPipe.h"
#include "CrossPipe.h"
#include <SFML/Graphics.hpp>
#include <array>
#include <fstream>
using namespace std;
using namespace sf;
bool Win();
int main()
{
    Vector2f offset(170, 170);
    int length = 108;
    char loaded = false;
    map <int , Pipe*> Board;
    Generate_puzzle G;
    array < array <Pipe* , 5 > , 5> Gamefinall;
    int A;
    fstream file ("Save.bin" , ios::binary | ios::in |ios::out );
    if(!file.is_open())
        cout << "file baz nashod ";
    cout << "Do you want new game or you want load game?  0 for new 1 for load";
    cin >>  A;
    if(A==0)
    {
        Board = G.find_an_answer();

        unsigned short int counter = 0;
        for (int i = 0 ; i < 5  ; i ++)
        {
            for (int j = 0 ; j < 5 ; j++)
            {
                Gamefinall.at(i).at(j) = Board[counter];
                counter++;

            }
        }
    }
    if ( A == 1 ) // loading
    {
        loaded = true;
        file.seekg(0);
        char nh;
        char rh;
        char zero = 0;
        while(file.good())
        {
            for (int i = 0 ; i < 5 ; i++)
            {
                for ( int j = 0 ; j < 5 ; j++)
                {
                     for (int k = 0 ; k <2 ; k++)
                    {
                        file.get(nh);
                        file.get(rh);
                        int rot = (int)rh - (int)zero;
                        switch (nh)
                        {
                        case('L'):
                            Gamefinall.at(i).at(j) = new Line(rot);
                            break;
                        case('C') :
                            Gamefinall.at(i).at(j) = new Cross(rot);
                            break;
                        case('T'):
                            Gamefinall.at(i).at(j) = new Turn(rot);
                            break;
                        }

                    }
                }
            }

        }
    }
       for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
           Gamefinall.at(i).at(j)->fill_in();
        }
    }
    if (loaded = false)
    {
    cout << "Do you want to save game ? 0 for yes 1 for no";
    cin >> A;
    }
    if (A == 0) // saving
    {
        for(int i = 0 ; i < 5 ; i++){
            for (int j = 0 ; j < 5 ; j++){
                file.put(Gamefinall.at(i).at(j)->get_name());
                file.put((char)(Gamefinall.at(i).at(j)->get_changing_rotation()));
            }
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
                    cout << pos.y << " " << pos.x << endl;
                }
        }

        window.clear(Color(0, 0, 0));

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                Pipe* p = Gamefinall[i][j];
                p->picture.setTextureRect(IntRect(0, 0, length, length));
                p->picture.setRotation(90 * p->get_changing_rotation());
                p->picture.setPosition(j * length, i *length);
                p->picture.move(offset);
                window.draw(p->picture);
            }
        }

        window.display();
    }
    return 0;
}
bool Win();
