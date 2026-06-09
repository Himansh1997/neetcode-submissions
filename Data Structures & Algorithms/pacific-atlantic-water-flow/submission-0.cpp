class Solution {
public:
    vector<vector<int>> directions= {{1,0},{-1,0},{0,1},{0,-1}};
    void DFS(int i, int j, int prevCellValue, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(i<0 ||j<0 || i >= heights.size() || j >= heights[0].size() || heights[i][j] < prevCellValue || visited[i][j]){
            return;
        }
        visited[i][j]= true;

        for(auto dir: directions){
            int x= i + dir[0];
            int y= j + dir[1];

            DFS(x, y, heights[i][j], visited, heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row= heights.size();
        int col= heights[0].size();
        vector<vector<int>> result;

        vector<vector<bool>> pacificVisited(row, vector<bool>(col, false));
        vector<vector<bool>> atlanticVisited(row, vector<bool>(col, false));

        for(int j=0; j<col; j++){
            DFS(0, j, INT_MIN, pacificVisited, heights);
            DFS(row-1, j, INT_MIN, atlanticVisited, heights);
        }
        for(int i=0; i<row; i++){
            DFS(i, 0, INT_MIN, pacificVisited, heights);
            DFS(i, col-1, INT_MIN, atlanticVisited, heights);
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacificVisited[i][j] && atlanticVisited[i][j]){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
