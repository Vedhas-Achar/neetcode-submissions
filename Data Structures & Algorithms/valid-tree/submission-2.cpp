
class Solution {
public:

    struct Node{
        int val;
        vector<Node*> neigh;
    };

    bool dfs(vector<bool>& vis, Node* node, Node* par){
        vis[node->val] = true;
        
        for(Node* n: node->neigh){
            if(n != par) {
            
                if(vis[n->val]) return true;

                
                if(dfs(vis, n, node)) return true;
            }


        }
        return false;
    }
        
    

    bool validTree(int n, vector<vector<int>>& edges) {
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
        if(dfs(vis, vertices[0], nullptr)) return false;

        

        for(Node* n: vertices){
            if(!vis[n->val]){
                return false;
            }
        }
        return true;
    }
};
