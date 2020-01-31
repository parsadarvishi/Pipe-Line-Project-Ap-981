#include "Generation_core.h"
#include  "LinePipe.h"
#include  "TurnPipe.h"
#include "CrossPipe.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <map>
using namespace std;
void Generate_puzzle::creat_game_graph ()
{
     for(int i=0 ; i<25 ; i++)
    {
        if(!((i+1)%5 ==0))
        {
            game.add_path(i,i+1);
        }
    }
    for(int i = 0 ; i<25 ; i++)
    {
        if((i+5 )< 25 )
        {
            game.add_path(i,i+5);
        }
    }

}
int Generate_puzzle::random_number(int num)
{
    if (num == 0 )
        return 0;
    int i;
    i = rand()%num;
    return i ;

}

// *****************************************************************************************Puzzle maker***********
map<int , Pipe*> Generate_puzzle::find_an_answer()
{
    {
    creat_game_graph();
    short int current = 0;// shows the current vertex that we are on it
    int random ; // keeping the generated random number
    srand(time(0)); // producing the random function seed
    short int temp; // temp memory to keep the next vertex we are going too
    bool B;
    vector <int> possible_vertex ; // keeping the vertex that we can go from neighbors of that vertex
    vector <int> solotion; // keeping the whole game solution
    vector <int> neighbor; // keeping the neighbors of an vertex
    solotion.push_back(current);
    while (current < 24)
    {
        for(auto it = game.graph.at(current).begin() ; it != game.graph.at(current).end() ; it++) // test
        {
            neighbor.push_back(*it);
        }
        if (neighbor.size() == 4)
            B = true;
        else
            B = false;
        if(solotion.size() >2)
        {
            for (int i = 1 ; i < solotion.size()-1 ; i++)
                {

                    if ( (solotion.at(i) - solotion.at(i-1)) == 1 && (solotion.at(i+1) - solotion.at(i) == 1) && (B== true))
                    {
                        game.add_path(solotion.at(i), solotion.at(i)-5);
                        game.add_path(solotion.at(i), solotion.at(i)+5);
                    }
                }
                for (int i = 1 ; i < solotion.size()-1 ; i++)
                {
                    if ( (solotion.at(i) - solotion.at(i-1)) == 5 && (solotion.at(i+1) - solotion.at(i) == 5) && (B== true))
                    {
                        game.add_path(solotion.at(i), solotion.at(i)-1);
                        game.add_path(solotion.at(i), solotion.at(i)+1);
                    }
                }
        }
        // checking a vertex neighbos to see if there is way so we can go from it
        for (int i = 0 ; i < neighbor.size() ; i++)
        {

            game.remove_path(current , neighbor.at(i));
            if (game.is_there_way(neighbor.at(i)))
                possible_vertex.push_back(neighbor.at(i));
            game.add_path(current , neighbor.at(i));
        }
        // choosing a random verte to go
        if ( possible_vertex.size() > 0)
            {
        random = random_number(possible_vertex.size());

        temp = possible_vertex.at(random);
        // removing last vertex neighbors
        game.remove_neighor(current);
        current = temp;
        solotion.push_back(temp);
        }
        else if (possible_vertex.size() == 0)
        {
            solotion.push_back(24);
            current = 24;
        }
        possible_vertex.clear();
        neighbor.clear();
    }
    for (auto item : solotion)
    {
        cout << item << " ";
    }
    cout << endl;

// Declaring the first pipe at number 0 cell
    if (solotion.at(1) == 1)
    {
        Board[0]=new Turn(0) ;
    }
    else if ( solotion.at(1) == 5)
    {
        Board[0]=new Line(0);
    }
// Declaring the last Pipe at number 24 cell
    if ( solotion.at(solotion.size()-2) == 19 )
    {
        Board[24]=new Line(0);
    }
    else if (solotion.at(solotion.size()-2) == 23)
    {
        Board[ 24]= new Turn(2);
    }
 // Declaring other Pipes in the solotion;
        for (unsigned int r = 1 ; r < solotion.size()-1; r++ )
    {
        int random = 0; // choosing line pipe or cross pipe
       int A = solotion.at(r-1)-solotion.at(r);
       int B = solotion.at(r)-solotion.at(r+1);
// producing a Line pipe with 0 rotation ( -- )

        if((abs(A) == abs(B)) && abs(A) == 1)
        {
            random = random_number(2);
            if (random == 0)
            {
                Board[solotion.at(r)]= new Line(2);
            }
            if(random == 1)
            {
                Board[solotion.at(r)] = new Cross(0);
            }
        }
// producing a Line pipe with 180 rotation ( | )
        if((abs(A) == abs(B)) && abs(A) == 5)
        {
            random = random_number(2);
            if (random == 0)
            {
                Board[solotion.at(r)]= new Line(0);
            }
            if(random == 1)
            {
                Board[solotion.at(r)] = new Cross(0);
            }
        }
// producing a Turn Pipe with 0 rotation ( |_ )
        if( (A == -5 && B==-1) ||  (A == 1 && B==5) )
        {
            Board[solotion.at(r)]=new Turn(0);
        }
// producing a Turn pipe with 90 rotation ( |- )
        if((A == 5 && B==-1) ||  (A == 1 && B==-5))
        {
            Board[solotion.at(r)] = new Turn(1);
        }
// producing a Turn pipe with 180 rotation ( -| )
        if(( A == -1 && B==-5) ||  (A == 5 && B==1))
        {
            Board[solotion.at(r)] = new Turn(2);
        }
// producing a Turn pipe with 270 rotation ( _| )
        if((A == -1 && B==5) ||  (A == -5  && B== 1))
        {
            Board[solotion.at(r)] = new Turn(3);
        }
        if( r == 24)
        {
            break;
        }
    }

    map<int, Pipe*>::iterator it;



    // filliing the rest of the table with pipes
    for (int i =  0 ; i < 25 ; i++)
    {
        bool check = false;

        for (int j = 0 ; j < solotion.size() ; j++ )
        {
            if (solotion.at(j) == i)
                check = true;
        }
        if(check == false)
        {
            int r;
            r = random_number(3);
           switch(r)
           {
           case(0):
               Board[i]= new Cross();
                    break;
           case(1):
               Board[i]=new Line();
                    break;
            case(2):
                Board[i]=new Turn();
                    break;
           }
        }
    }
//shuffleeeeee
    for (it = Board.begin(); it!=Board.end() ; it++)
    {
        int rand;
        rand = random_number(4);
        it->second->Set_changing_rotation(rand);
        }
    }



    return Board;
}








