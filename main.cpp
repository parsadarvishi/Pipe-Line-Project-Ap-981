#include <iostream>
#include "Graph.h"
#include "Generation_core.h"
#include <map>
#include "Pipe.h"
#include  "LinePipe.h"
#include  "TurnPipe.h"
#include "CrossPipe.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <fstream>
#include <vector>
using namespace std;
using namespace sf;
bool Win();
array < array <Pipe* , 5 > , 5> Gamefinall;
vector<int> solotion;
int main()
{

    Vector2f offset(170, 170);
    int length = 108; //length of everu pipe picture
    map <int , Pipe*> Board; // map for save the return of find_an_answer function
    Generate_puzzle G;
    int A;
    ofstream fout ("Save.bin" , ios::binary );
    if(!fout.is_open())
        cout << "file baz nashod ";
    ifstream fin ("Save.bin" , ios::binary);
    if(!fin.is_open())
        cout << "file baz nashod";


        Board = G.find_an_answer(solotion);
        unsigned short int counter = 0;
        for (int i = 0 ; i < 5  ; i ++)
        {
            for (int j = 0 ; j < 5 ; j++)
            {
                Gamefinall.at(i).at(j) = Board[counter];
                counter++;

            }
        }

    /*if ( A == 1 ) // loading
    {
        fin.seekg(0 , ios::beg);
                char* A ;
                char* B;

                for (int i = 0 ; i < 5 ; i++)
                {
                    for ( int j = 0 ; j < 5 ; j++)
                    {
                         fin.read(A , 1);
                          fin.read(B, 1);
                          cout << A << B << endl;
                        switch ((int)A)
                        {
                        case('L'):
                            Gamefinall.at(i).at(j) = new Line((int) B);
                            break;
                        case('C') :
                            Gamefinall.at(i).at(j) = new Cross((int) B);
                            break;
                        case('T'):
                            Gamefinall.at(i).at(j) = new Turn((int) B);
                            break;

                        }
                    }
                }
    }*/


    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
           Gamefinall.at(i).at(j)->fill_in();

        }
    }

    RenderWindow window(VideoMode(780, 780), "Pipe Line");
    // ** Win Picture loading
        Texture Wintexture;
        Sprite Winsprite;
        if(!Wintexture.loadFromFile("Assets/Win.png"))
            cout << "Win picture did not open";
        Winsprite.setPosition(280 , 2);
    //** Start Picture loading
        Texture Starttxture;
        Sprite Startsprite;
        if(!Starttxture.loadFromFile("Assets/Start.png"))
            cout << " Eror picture didnot opened";
        Startsprite.setTexture(Starttxture);
        Startsprite.setPosition(116 , 8);
    // ** Finish picture loading
        Texture Finishtexture;
        Sprite Finishsprite;
        if(!Finishtexture.loadFromFile("Assets/Finish.png"));
        Finishsprite.setTexture(Finishtexture);
        Finishsprite.setPosition(548 ,656);
    // ** audio file for laying in background
    Music music;
    if(music.openFromFile("Assets/Billie-Eilish- Idontwannabeyouanymore-320.ogg"))
    {
        cout << "Music did not open" << endl;
    }

    music.setVolume(50);
    music.play();
    // ** defining audio file for Win effect
    Music Winmusic;
    if(Winmusic.openFromFile("Assets/Eurythmics-Sweet-Dreams-320.ogg"))
       {
           cout << "Win effect music did not open" << endl;
       }
    Winmusic.setVolume(100);

    bool have_i_won = false;
    while (window.isOpen())
    {

        Event event;
        while (window.pollEvent(event))
        {
            if(Win() && have_i_won == false)
                {
                     Winsprite.setTexture(Wintexture);
                     have_i_won = true;
                     music.pause();
                     Winmusic.play();
                }

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
             if(Keyboard::isKeyPressed(Keyboard::S))
                {
                    for(int i = 0 ; i < 5 ; i++)
                    {
                        for (int j = 0 ; j < 5 ; j++)
                            {
                                char a = Gamefinall.at(i).at(j)->get_name();
                                char b = (char)Gamefinall.at(i).at(j)->get_changing_rotation();
                                fout.write((char *) &a , sizeof(char));
                                fout.write((char *) &b , sizeof (char));
                            }
                    }
                }

        window.clear(Color(132, 238, 254));

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
        window.draw(Winsprite);
        window.draw(Startsprite);
        window.draw(Finishsprite);
        window.display();
    }

}
fout.close();
return 0;
}

// this function check that if we have won the game or not
bool Win()
{
    vector<bool> check_win ;
    bool  W = true;
    int counter = 0;
    for (int i = 0 ; i < 5 ; i++)
    {
        for (int j = 0 ; j < 5 ; j++)
        {
            for ( int k = 0 ; k < solotion.size() ; k++)
            {
                if (counter == solotion.at(k))
                    if(Gamefinall.at(i).at(j)->get_rotation() == Gamefinall.at(i).at(j)->get_changing_rotation())
                        check_win.push_back(true);
                    else
                        check_win.push_back(false);
            }
            counter++;
        }
    }
    for (auto item : check_win)
    {
        if (item == false)
        W = false;
    }
    return W;
}
