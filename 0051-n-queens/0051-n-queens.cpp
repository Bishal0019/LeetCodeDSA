class Solution {
public:
    void solve(vector<vector<string>>& board, vector<int>& cols, int n, int col){
        if(n==col){
            vector<string> temp;
            
            for(int i=0; i<n; i++){
                string ans(n, '.');
                ans[cols[i]] = 'Q';
                temp.push_back(ans);
            }
            
            board.push_back(temp);
            return;
        }
        
        for(int i=0; i<n; i++){
            int placed = 1;
            for(int j=0; j<col; j++){
                if(cols[j] == i){
                    placed = 0;
                    break;
                } else if(i - col == cols[j] - j){
                    placed = 0;
                    break;
                }
                else if(i+col == cols[j] + j){
                    placed = 0;
                    break;
                }
            }
            if(placed){
                cols[col] = i;
                solve(board, cols, n, col+1);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols(n, -1);
        vector<vector<string>> board;

        solve(board, cols, n, 0);
        return board;
    }
};