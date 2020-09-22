
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

std::vector<vector<int>> vec;
std::vector<bool> visited;

void dfs_r(int s){
    
    int i;
    visited[s] = true;
    
    cout << "\nVisited: "<< s; 

    for(i=0; i < vec[s].size(); ++i ){
        if (visited[vec[s][i]] == false )
            dfs_r(vec[s][i]);
    }
}

void dfs(const std::vector<vector<int>> vec, int s){
    int node, i;
    std::stack<int> stk;
    stk.push(s);

    visited[s] = true;

    while(!stk.empty()){
        node = stk.top();
        stk.pop();
        cout << "\nVisited: "<< node;
        for(int i=0; i < vec[node].size(); ++i)
        {
            if(visited[vec[node][i]] == false)
            {
                stk.push(vec[node][i]);
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

    // setting default for simplicity
    nodes = 10;
    edges = 12;

    vec.resize(nodes+1);
    visited.resize(nodes+1);

    // Creating adjacency matrix
    for(int i=0; i<edges; ++i)
    {
    
        vec[x[i]].push_back(y[i]);
        vec[y[i]].push_back(x[i]);
    }

    int start;
    cout << "Enter starting node, [1,10] : ";
    cin >> start;

    if( start>0 && start <11)
    {

     cout << "\nDFS -->\n";

        init_visited();

        cout << "Recursive dfs\n";
        dfs_r(start);

        init_visited();

        cout<< "\n\niterative dfs\n";
        dfs(vec, start);
    }
    else cout << "\nNo such node.\n";

    return 0;
}