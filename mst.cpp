#include <iostream>
#include <list>
#include <map>
using namespace std;

struct Edge
{
    int start;
    int end;
    int weight;

    bool operator<(struct Edge & eg) //operator overloading to sort
    {
        if(weight < eg.weight)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int Find_Set(int * set, int index) // find parent and return parent index
{
    while(set[index] > 0) //until find parent 
    {
         index = set[index];
    }
    return index;
}

// disjoint set's rank is represented in negative sign
void Union(int * set, int index1, int index2) // union two set
{
    if(set[index1] > set[index2]) // if index2 has higher height
    {
        set[index1] = index2;
    }
    else
    {
        if(set[index1]==set[index2]) //when two set have same rank
        {
            set[index1] = set[index1] -1; // increase rank
        }
        set[index2] = index1;
    }
}

int main(void)
{
    int n_edge, n_vertex,city_start,city_end,city_cost;
    int start_vertex, end_vertex;
    int start_parent, end_parent;
    int cost, tmp;
    int * disset;
    char same = 0;
    list<Edge> edge_list;
    map<pair<int,int>,int> input;
    while(1)
    {
        //get number of edge, vertex from input
        cin >> n_vertex;
        cin >> n_edge;
        

        //quit program when n_edge and  n_vertex  are 0  
        if((n_vertex == 0) || (n_edge == 0))
        {
            break;
        }

        //get edge information from input
        for(int i = 0 ; i <n_edge ; i++)
        {
            cin >> city_start;
            cin >> city_end;
            cin >> city_cost;
            if(city_start > city_end)//make undirect input
            {
                tmp = city_start;
                city_start = city_end;
                city_end = tmp;
            }

            input[make_pair(city_start,city_end)] = city_cost; // insert edge input in map to eliminate duplicate edge information
        }


        // insert input edges into edge list
        for (map<pair<int,int>,int> :: iterator it = input.begin() ; it != input.end(); ++it)
        {
            struct Edge tmp_edge = {it->first.first, it->first.second, it ->second};
            edge_list.push_back(tmp_edge);
        }
        
     
        //intiailize disjoint set
        disset = new int[n_vertex+1];
        for(int i = 0 ; i <= n_vertex; i++)
        {
            disset[i] = 0; //initial value is 0,
        }

        //sort edge 
        edge_list.sort();
        cost = 0;
        //kruskal algorithm
        for(list<Edge>::iterator it = edge_list.begin() ; it != edge_list.end(); ++it)
        {
            start_parent = Find_Set(disset,it->start);
            end_parent =  Find_Set(disset,it->end);
            if(start_parent != end_parent) //when they are not same tree
            {
                //include edge in tree
                cost = cost + it->weight;
                Union(disset,start_parent,end_parent);
            }
        }
        cout<<cost<<endl; //print cost 
       
        edge_list.clear();
        input.clear();
        delete[] disset;
    }
    return 0;
}
