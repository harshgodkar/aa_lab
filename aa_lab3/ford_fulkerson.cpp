#include <bits/stdc++.h>
using namespace std;

#define V 6

bool bfs(int r_graph[V][V], int s, int t, int parent[]){
    int visited[V];
    for(int i=0; i < V; i++)
        visited[i] = 0;
    
    std::queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=0; v < V; v++){
            if(visited[v] == 0 && r_graph[u][v] > 0){
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
            
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V], int s, int t){
    int r_graph[V][V];
    for(int u=0; u < V; u++){
        for(int v=0; v < V; v++){
            r_graph[u][v] = graph[u][v];
        }
    }
    
    int parent[V];
    int max_flow = 0;
    
    while(bfs(r_graph, s, t, parent)){
        int path_flow = INT_MAX;
        
        for(int v=t; v != s; v = parent[v]){
            int u = parent[v];
            path_flow = min(path_flow, r_graph[u][v]);
        }
        for(int v=t; v != s; v = parent[v]){
            int u = parent[v];
            r_graph[u][v] -= path_flow;
            r_graph[v][u] += path_flow;
        }
        
        max_flow += path_flow;
    }
    
    return max_flow;
    
}

int main() {
    
    int graph[V][V]
        = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
            { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
            { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 } };
    
    cout << "Maximum Flow of the graph is : " << fordFulkerson(graph, 0, V-1) << endl;
    return 0;
}
