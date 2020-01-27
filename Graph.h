#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <array>
#include <list>
class Graph
{
private:
    static const short int game_size = 25;
public:
    std::array < std::list<int> , game_size > graph;
    void add_path (int , int);
    void remove_path(int , int);
    bool is_there_way (int );

};


#endif // GRAPH_H_INCLUDED
