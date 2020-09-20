#include <iostream>
#include <map>

using namespace std;
#define INF 9999999


int main(void)
{
    int n_edge, n_vertex;
    int edge_start, edge_end, edge_cost;
    int* distance;
    int tmp;
    map <pair<int,int>,int> edge;
    while(1)
    {
        //get number of edge, vertex from input
        cin >> n_vertex;
        cin >> n_edge;

        //when get wrong input , quit program
        if((n_vertex == 0) || ( n_edge == 0))
        {
            break;
        }
        //get edge information from input
        for(int i = 0 ; i <n_edge ; i++)
        {
            cin >> edge_start;
            cin >> edge_end;
            cin >> edge_cost;
            if(edge_start > edge_end) //make undirect input
            {
                tmp = edge_start;
                edge_start = edge_end;
                edge_end = tmp;
            }
            edge[make_pair(edge_start,edge_end)] = edge_cost;
        }
        //initilize distance 
        distance = new int[n_vertex];
        for(int i = 0 ; i < n_vertex;i++)
        {
            distance[i] = INF;
        }
        
        //init source distance
        distance[0] = 0; 
        
        //bellman ford algorithm 
        for(int i = 0 ; i < n_vertex-1;i++) 
        {
            //relaxations for all edge
            for(map<pair<int,int>,int>::iterator it = edge.begin() ; it != edge.end(); ++it)
            {
                //relax in undirected edge (u,v)
                // d[v] > w + d[u]
                if(distance[it->first.second-1] > (it->second+distance[it->first.first-1]))
                {   
                    distance[it->first.second-1] = it->second+distance[it->first.first-1];
                }
                //d[u] > w + d[v]
                if(distance[it->first.first-1] > (it->second+distance[it->first.second-1]))
                {
                    distance[it->first.first-1] = it->second+distance[it->first.second-1];
                }
            }
        }
       

        if(distance[n_vertex-1] == INF)
        {
            cout<<"no path"<<endl;
        }
        else
        {
            cout<<distance[n_vertex-1]<<endl; //print cost
        }
        //deallocation
        delete[] distance;
        edge.clear();
     }
    return 0;
}
