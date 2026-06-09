class Solution{
    public:
    bool isCycleDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& dfsVisited, unordered_map<int, list<int>>& adj){
        visited[node]= true;
        dfsVisited[node]= true;

        for(auto i: adj[node]){
            if(!visited[i]){
                bool cycleFound= isCycleDFS(i, visited, dfsVisited, adj);
                if(cycleFound){
                    return true;
                }
            }else if(dfsVisited[i]){
                return true;
            }
        }
        dfsVisited[node]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        unordered_map<int, list<int>> adj;
        for(int i=0; i< prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[v].push_back(u);
        }

        unordered_map<int, bool> visited;
        unordered_map<int, bool>dfsVisited;

        for(int i=0; i <= numCourses; i++){
            if(!visited[i]){
                bool cycleFound= isCycleDFS(i, visited, dfsVisited, adj);
                if(cycleFound){
                    return false;
                }
            }
        }
        return true;
    }
};