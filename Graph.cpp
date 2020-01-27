#include "Graph.h"
#include <array>
#include <list>
#include <iterator>
using namespace std ;

void Graph::add_path (const int first ,const int next)
{
    graph.at(first).push_back(next);
    graph.at(next).push_back(first);
    return;
}
void Graph::remove_path ( const int first ,const int next)
{
    graph.at(first).remove(next);
    graph.at(next).remove(first);
}
bool Graph::is_there_way (const int f)
{
    int first = f;
    array <bool , game_size> checked = {false} ;

    list<int> queue ;
    checked.at(first)=true;
    queue.push_back(first);

    while(!queue.empty())
    {
        first = queue.front();
        queue.pop_front();

        list<int> :: iterator i;
        for (i = graph[first].begin(); i != graph[first].end(); i++)
        {
            if (*i == 24)
                return true;

            if (!checked[*i])
            {
                checked[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return false;
}


