class Solution {
public:
    int row;
    int col;
    bool exist(vector<vector<char>>& board, string word) {
        row= board.size();
        col= board[0].size();
        for(int x=0; x< row; x++){
            for(int y=0; y< col; y++){
                if(dfs(board, word, x, y, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int index){
        if(index == word.length()){
            return true;
        }
        if(x < 0 || y < 0 || x >= row | y >= col || board[x][y] != word[index]
           || board[x][y] == '#'){
            return false;
        }
        board[x][y]= '#';

        bool result= dfs(board, word, x+1, y, index+1) ||
                     dfs(board, word, x-1, y, index+1) ||
                     dfs(board, word, x, y+1, index+1) ||
                     dfs(board, word, x, y-1, index+1);

        board[x][y]= word[index];
        return result;             
    }
};
