#ifndef GENERATION_CORE_H_INCLUDED
#define GENERATION_CORE_H_INCLUDED
#include "Graph.h"
#include "Pipe.h"
#include <map>
#include <vector>
class Generate_puzzle
{
public :
    // for Declaring neighbors of an vertex
    void creat_game_graph ();
    // finding a unique way from begin to the end of our graph
    std::map<int , Pipe*> find_an_answer (std::vector<int>&);
    // random function
    int random_number (int);
private:
    Graph game;
    std::map <int  , Pipe *> Board;
};


#endif // GENERATION_CORE_H_INCLUDED
