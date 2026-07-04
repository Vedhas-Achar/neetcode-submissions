class Solution {
public:

    struct Node{
        int val;
        vector<Node*> neigh;
    };

    void dfs(vector<bool>& vis, Node* node){
        vis[node->val] = true;
        
        for(Node* n: node->neigh){
            if(!vis[n->val]) dfs(vis, n);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<Node*> vertices;

        for(int i = 0; i < n; i++){
            Node* n = new Node();
            n->val = i;
            vertices.push_back(n);
        }

        for(auto ed: edges){
            vertices[ed[0]]->neigh.push_back(vertices[ed[1]]);
            vertices[ed[1]]->neigh.push_back(vertices[ed[0]]);
        }

        int c = 0;

        for(Node* n: vertices){
            if(!vis[n->val]){
                c++;
                dfs(vis, n);
            }
        }
        return c;
    }
};
