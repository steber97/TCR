// DFS num:
#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2
void graphCheck(int u){
    dfs_num[u] = EXPLORED;
    for (int j = 0; j<graphp[u].size(); j++){
        int v = graph[u][j];
        if (dfs_num[v] == UNVISITED){
            dfs_parent[v] = u;
            graphCheck(v);
        }
        else if (dfs_num[v] == EXPLORED){
            if (v == dfs_parent[u]){
                // edge to parent, not very useful
            }
            else {
                // back edge, graph is cyclic.
            }
        }
        else if(dfs_num[v] == VISITED){
            // Forward edge.
        }
    }
}
int main(){
    dfs_num.assign(V, UNVISITED);
    dfs_parent.assign(V, 0);
    for (int i = 0; i<V; i++){
        if (dfs_num[i] == UNVISITED)
            graphCheck(i);
    }
}