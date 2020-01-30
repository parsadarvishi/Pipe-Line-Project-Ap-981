#ifndef GENERATION_CORE_H_INCLUDED
#define GENERATION_CORE_H_INCLUDED
#include <vector>
#include <map>
#include "Pipe.h"
class Generate_puzzle
{
public :
    // for Declaring neighbors of an vertex
    void creat_game_graph ();
    // finding a unique way from begin to the end of our graph
    vector<int> find_an_answer ();
    // random function
    int random_number (int);
    // creating pipes and save their arengment
    map<int , Pipe*> Table_maker (vector<int>);
private:
    Graph game;
};

#endif // GENERATION_CORE_H_INCLUDED
