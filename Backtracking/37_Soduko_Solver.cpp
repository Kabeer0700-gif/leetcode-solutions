int static check = 0;
class Solution {
public:
    bool isValid(vector<vector<char>>& board,int sr,int sc,char ch){
        //checking rows
        for(int j=0;j<9;j++){
            if(board[sr][j] == ch) return false;
        }

        //checking columns
        for(int i=0;i<9;i++){
            if(board[i][sc] == ch) return false;
        }

        int sRow = sr/3*3;
        int sCol = sc/3*3;

        for(int i=sRow; i<sRow+3; i++){
            for(int j=sCol; j<sCol+3; j++){
                     if(board[i][j] == ch) return false;

            }
        }

        return true;
    }
public:
    void solve(vector<vector<char>>& board,int sr,int sc){
        if(sr == 9){
            check = 1;
            return;
        }
        if(board[sr][sc] != '.'){
            if(sc != 8){
                solve(board,sr,sc+1);
            }else{
                solve(board,sr+1,0);
            }
        }else{
            for(char ch = '1'; ch <= '9'; ch++){
               if(isValid(board,sr,sc,ch)){
                    board[sr][sc] = ch;
                    if(sc != 8) solve(board,sr,sc+1);
                    else solve(board,sr+1,0);
                    if(check==1) return;
                    board[sr][sc] = '.';
               }
            }

        }
       
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
        check = 0;
    }
};
