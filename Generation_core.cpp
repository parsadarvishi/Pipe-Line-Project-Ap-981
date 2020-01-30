#include "Generation_core.h"
#include "Pipe.h"
#include "LinePipe.cpp"
#include "TurnPipe.cpp"
#include "CrossPipe.cpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
#include <map>
//using namespace std;
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


//**********************************************
int Generate_puzzle::random_number(int num)
{
    srand(time(0)); // producing the random function seed
    int i;
    i = rand()%num;
    return i ;

}
//**********************************************


//**********************************************
void Generate_puzzle::find_an_answer()
{
    creat_game_graph();
    short int current = 0;// shows the current vertex that we are on it
    int random ; // keeping the generated random number

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
            for (unsigned int i = 1 ; i < solotion.size()-1 ; i++)
                {
                    if ( (solotion.at(i) - solotion.at(i-1)) == 1 && (solotion.at(i+1) - solotion.at(i) == 1) && (B== true))
                    {
                        game.add_path(solotion.at(i), solotion.at(i)-5);
                        game.add_path(solotion.at(i), solotion.at(i)+5);
                    }
                }
                for (unsigned int i = 1 ; i < solotion.size()-1 ; i++)
                {
                    if ( (solotion.at(i) - solotion.at(i-1)) == 5 && (solotion.at(i+1) - solotion.at(i) == 5) && (B== true))
                    {
                        game.add_path(solotion.at(i), solotion.at(i)-1);
                        game.add_path(solotion.at(i), solotion.at(i)+1);
                    }
                }
        }
        // checking a vertex neighbos to see if there is way so we can go from it
        for (unsigned int i = 0 ; i < neighbor.size() ; i++)
        {
            game.remove_path(current , neighbor.at(i));
            if (game.is_there_way(neighbor.at(i)))
                possible_vertex.push_back(neighbor.at(i));
            game.add_path(current , neighbor.at(i));
        }
        // choosing a random verte to go
        random = random_number(possible_vertex.size());
        temp = possible_vertex.at(random);
        // removing last vertex neighbors
        game.remove_neighor(current);
        current = temp;
        solotion.push_back(temp);
        possible_vertex.clear();
        neighbor.clear();
    }

    for (auto item : solotion)
    {
        cout << item << " ";
    }
}
//************************************


//************************************
/*map<int , Pipe * > Generate_puzzle::Table_maker(vector<int> Solotion)
{
    map <int  , Pipe *> Board;
// Declaring the first pipe at number 0 cell
    if (Solotion.at(1) == 1)
    {
        Board[0]=new Turn(270) ;
    }
    else if ( Solotion.at(1) == 5)
    {
        Board[0]=new Line(0);
    }
// Declaring the last Pipe at number 24 cell
    if ( Solotion.at(Solotion.size()-2) == 19 )
    {
        Board[Solotion.size()]=new Line(0);
    }
    else if (Solotion.at(Solotion.size()-2) == 23)
    {
        Board.at(Solotion.size())= new Turn(180);
    }
 // Declaring other Pipes in the solotion;
        for (unsigned int r = 1 ; r < Solotion.size()-1 ; r++ )
    {
        int random = 0; // choosing line pipe or cross pipe
        int first = Solotion.at(r-1);
        int middle = Solotion.at(r);
        int next = Solotion.at(r+1);
// producing a Line pipe with 0 rotation ( | )
        if(middle - first == 5 && next - middle == 5)
        {
            random = random_number(2);
            if (random == 0)
            {
                Board[r]= new Line(0);
            }
            if(random == 1)
            {
                Board[r] = new Cross(180);
            }
        }
// producing a Line pipe with 180 rotation ( -- )
        if( middle - first == 1 && next - middle == 1)
        {
            random = random_number(2);
            if (random == 0)
            {
                Board[r]= new Line(0);
            }
            if(random == 1)
            {
                Board[r] = new Cross(180);
            }
        }
// producing a Turn Pipe with 0 rotation ( |_ )
        if(next - first == 6 && next - middle == 1)
        {
            Board[r]=new Turn(0);
        }
// producing a Turn pipe with 90 rotation ( |- )
        if(first - next == 4 && next - middle == 1)
        {
            Board[r] = new Turn(90);
        }
// producing a Turn pipe with 180 rotation ( -| )
        if( next - first == 6 && middle - first == 1)
        {
            Board[r] = new Turn(180);
        }
// producing a Turn pipe with 270 rotation ( _| )
        if(first - next == 4 && middle - first == 1)
        {
            Board[r] = new Turn(270);
        }
    }
    return Board;
}*/
