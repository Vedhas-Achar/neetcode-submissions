class WordDictionary {
    bool end;
    WordDictionary* next[26];

public:
    WordDictionary() {
        this->end = false;
        for(int i = 0; i < 26; i++){
            next[i] = 0;
        }
    }

    bool helper(string &word, int i, WordDictionary* node){
        if(!node) return false;
        if(i == word.size()) return node->end;

        if(word[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(helper(word, i+1, node->next[j]))
                    return true;
            }
            return false;
        }
        int idx = word[i] - 'a';
        return helper(word, i + 1, node->next[idx]);
    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for(char c: word){
            int idx = c - 'a';

            if(node->next[idx] == nullptr) node->next[idx] = new WordDictionary();
            node = node->next[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        return helper(word, 0, this);

    }
};
