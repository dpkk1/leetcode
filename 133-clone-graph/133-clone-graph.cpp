/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;    //All adjacent Nodes
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    void dfs(Node *curr, Node *node, vector<Node*>&vis){
        vis[node->val] = node; //Marked Visited
        for(auto ele:curr->neighbors)
            if(vis[ele->val] == NULL){
                Node *newNode = new Node(ele->val);
                (node->neighbors).push_back(newNode);
                dfs(ele, newNode, vis);
            }
            else {
                (node->neighbors).push_back(vis[ele->val]);
            }
    }
    
    Node* cloneGraph(Node* node) {
        //Base Case
        if(node == NULL)
            return node;
        
        vector<Node*>vis(1000, NULL);
        //Starting Node
        Node *copy = new Node(node->val);
        vis[node->val] = copy; //Marked Visited
        for(auto curr:node->neighbors)
            if(vis[curr->val] == NULL){
                Node *newNode = new Node(curr->val);
                (copy->neighbors).push_back(newNode);
                dfs(curr, newNode, vis);
            }
            else {
                (copy->neighbors).push_back(vis[curr->val]);
            }
        return copy;
    }
};