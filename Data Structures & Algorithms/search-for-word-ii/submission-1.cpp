class Trie {
public:
    bool end;
    string word;
    Trie* next[26];

    Trie() {
        end = false;
        word = "";
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};

class Solution {
public:

    Trie* root = new Trie();
    vector<string> ans;

    void insert(string &word) {
        Trie* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->next[idx] == nullptr)
                node->next[idx] = new Trie();

            node = node->next[idx];
        }

        node->end = true;
        node->word = word;
    }

    void dfs(int i, int j, vector<vector<char>>& board, Trie* node) {
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size())
            return;

        char c = board[i][j];

        if(c == '#') return;

        node = node->next[c - 'a'];

        if(node == nullptr) return;

        if(node->end){
            ans.push_back(node->word);
            node->end = false;
        }

        board[i][j] = '#';

        dfs(i + 1, j, board, node);
        dfs(i - 1, j, board, node);
        dfs(i, j + 1, board, node);
        dfs(i, j - 1, board, node);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        for(string &word: words){
            insert(word);
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                dfs(i, j, board, root);
            }
        }
        return ans;
    }
};
