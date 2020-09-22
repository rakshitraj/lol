#include <iostream>
#include <vector>
#include <queue>

using namespace std;

std::vector<vector<int>> vec;
std::vector<bool> visited;

void bfs(int node){

    std::queue<int> lst;
    lst.push(node);

    visited[node] = true;

    while(!lst.empty())
    {
        node = lst.front();
        lst.pop();

        cout << "\nVisited: " << node;

        for (int i = 0; i < vec[node].size(); i++)
        {
            if ( ! visited[vec[node][i]] )
            {
                lst.push(vec[node][i]);
                visited[vec[node][i]] = true;
            }
        }
    }
}

void init_visited(){
    // Initialize visited vector
    for (int i=0; i<visited.size(); i++)
    {
        visited[i] = false;
    }
}

int main()
{
    int nodes, edges;
    int x[] = {1,1,2,2,3,4,4,5,5,6,6,8};
    int y[] = {2,4,3,4,6,5,6,7,9,7,8,10};

    // setting default values for graph
    nodes = 10; edges = 12;

    vec.resize(nodes + 1);
    visited.resize(nodes + 1);

    // Create adjacency matrix
    for (int i=0; i<edges; i++)
    {
        vec[x[i]].push_back(y[i]);
        vec[y[i]].push_back(x[i]);
    }

    init_visited();

    int start;
    cout << "Enter starting node: ";
    cin >> start;

    if( start>0 && start <11)
    {
        cout << "\nBFS -->\n";
        bfs(start);
    }
    else cout << "\nNo such node.\n";

    return 0;
}