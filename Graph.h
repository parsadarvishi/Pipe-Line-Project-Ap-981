#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <array>
#include <list>
class Graph
{
private:
    static const short int game_size = 25;
public:
    //game board
    std::array < std::list<int> , game_size > graph;
    // putting a line between to vertex
    void add_path (const int ,const int);
    // deleting a line between two vertex
    void remove_path(const int ,const int);
    // deleting all the relations between a vertex and near vertices
    void remove_neighor (const int);
    // checking that if there is way from a vertex to end
    bool is_there_way (const int );

};


#endif // GRAPH_H_INCLUDED
