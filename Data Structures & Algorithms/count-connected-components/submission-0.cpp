class Solution {
public:
    void DFS(int n, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj){
        visited[n]=true;
        for(auto i:adj[n]){
            if(!visited[i]){
                DFS(i, visited, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u= edges[i][0];
            int v= edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int, bool> visited;
        int count=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFS(i, visited, adj);
                count++;
            }
        }
        return count;
    }
};
