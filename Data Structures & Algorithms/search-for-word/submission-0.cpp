class Solution {
public:
    bool back(int i, int j, int ind, vector<vector<char>>& board, string word) {
        if(ind == word.size()) return true;
        
        if(i < 0 || i >= board.size()
            || j < 0 || j >= board[0].size()) return false;
        

        if(board[i][j] != word[ind]){
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = back(i-1, j, ind + 1, board, word)||
                    back(i+1, j, ind + 1, board, word) ||
                    back(i, j-1, ind + 1, board, word) ||
                    back(i, j+1, ind + 1, board, word);

        board[i][j] = temp;
        
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (back(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};
