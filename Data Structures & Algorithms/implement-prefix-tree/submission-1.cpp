class PrefixTree {
public:
    bool end;
    PrefixTree* next[26];

    PrefixTree() {
        end = false;
        for(int i = 0; i<26; i++){
            next[i] = nullptr;
        }
    }
    
    void insert(string word) {
        PrefixTree* node = this;
        for(char c: word){
            int idx = c - 'a';

            if(node->next[idx] == nullptr){
                node->next[idx] = new PrefixTree();
            }
            node = node->next[idx];
        }
        node->end = true;
    }
    
    bool search(string word) {
        PrefixTree* node = this;
        for(char c: word){
            int idx = c - 'a';

            if(node->next[idx] == nullptr) return false;

            node = node->next[idx];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* node = this;
        for(char c: prefix){
            int idx = c - 'a';

            if(node->next[idx] == nullptr) return false;

            node = node->next[idx];
        }
        return true;
    }
};
