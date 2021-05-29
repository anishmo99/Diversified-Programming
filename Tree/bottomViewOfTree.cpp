vector <int> bottomView(Node *root)
{
   if(!root)
    return vector<int> ();
    
    map<int, int> mp;
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        
        int hd = temp.second;
        mp[hd] = node -> data;
        
        if(node -> left)
            q.push({node -> left, hd - 1});
            
        if(node -> right)
            q.push({node -> right, hd + 1});
    }
    
    vector<int> ans;
    for(auto x : mp)
        ans.push_back(x.second);
        
    return ans;
}