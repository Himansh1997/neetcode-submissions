class Solution{
    public:
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(i<0 || j<0 || i >= row || j >= col || visited[i][j] || grid[i][j] == '0'){
            return;
        }
        visited[i][j]= true;
        DFS(i+1, j, grid, visited, row, col);
        DFS(i-1, j, grid, visited, row, col);
        DFS(i, j+1, grid, visited, row, col);
        DFS(i, j-1, grid, visited, row, col);
    }
    int numIslands(vector<vector<char>>& grid){
        int row= grid.size();
        int col= grid[0].size();
        int islands= 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]== '1' && !visited[i][j]){
                    DFS(i, j, grid, visited, row, col);
                    islands++;
                }
            }
        }
        return islands;
    }
};