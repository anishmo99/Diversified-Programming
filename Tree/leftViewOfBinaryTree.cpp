/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   if(!root)
        return vector<int> ();
        
    vector<int> ans;
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i < size; i++){
            auto node = q.front();
            q.pop();
            
            if(i == 0)
                ans.push_back(node -> data);
                
            if(node -> left)
                q.push(node -> left);
                
            if(node -> right)
                q.push(node -> right);
        }
    }
    
    return ans;
}