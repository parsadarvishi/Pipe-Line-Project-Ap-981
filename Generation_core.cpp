#include "Generation_core.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iterator>
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
    for (int i = 0 ; i < 25 ; i++)
        {
            cout << i << " ";
            for (auto item : game.graph.at(i))
            {
                cout << item << " ";
            }
            cout << endl;
        }
}
int Generate_puzzle::random_number(int num)
{
    int i;
    i = rand()%num;
    return i ;

}
void Generate_puzzle::find_an_answer()
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
        random = random_number(possible_vertex.size());
        temp = possible_vertex.at(random);
        // removing last vertex neighbors
        game.remove_neighor(current);
        current = temp;
        solotion.push_back(temp);
        possible_vertex.clear();
        neighbor.clear();
    }
        for (int i = 0 ; i < 25 ; i++)
        {
            cout << i << " ";
            for (auto item : game.graph.at(i))
            {
                cout << item << " ";
            }
            cout << endl;
        }
    for (auto item : solotion)
    {
        cout << item << " ";
    }

}

