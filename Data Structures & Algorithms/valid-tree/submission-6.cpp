class Solution {
public:
    bool isCycleDFS(int n, int parent, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj){
        visited[n]=true;
        for(auto i:adj[n]){
            if(!visited[i]){
                bool cycleFound= isCycleDFS(i, n, visited, adj);
                if(cycleFound){
                    return true;
                }
            }else if(i != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1){
            return false;
        }
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        for(int i=0; i<n; i++){
            if(! visited[i]){
                bool cycleFound= isCycleDFS(i, -1, visited, adj);
                if(cycleFound){
                    return false;
                }
            }
        }
        return true;
    }
};
