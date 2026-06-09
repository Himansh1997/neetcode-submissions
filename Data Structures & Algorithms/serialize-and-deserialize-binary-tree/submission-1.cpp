class Codec {
    public:
    string serialize(TreeNode* root){
        if(!root){
            return "#";
        }
        string result;
        queue<TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()){
            TreeNode* node= queue.front();
            queue.pop();
            if(!node){
                result += "#,";
            }else{
                result += to_string(node->val) + ",";
                queue.push(node->left);
                queue.push(node->right);
            }
        }
        return result;
    }
    TreeNode* deserialize(string data){
        stringstream ss(data);
        string value;
        getline(ss, value, ',');

        if(value == "#"){
            return NULL;
        }
        TreeNode* root= new TreeNode(stoi(value));
        queue<TreeNode*> queue;
        queue.push(root);


        while(getline(ss, value, ',')){
            TreeNode* node= queue.front();
            queue.pop();

            if(value != "#"){
                node->left= new TreeNode(stoi(value));
                queue.push(node->left);
            }
            getline(ss, value, ',');
            if(value != "#"){
                node->right= new TreeNode(stoi(value));
                queue.push(node->right);
            }
        } 
        return root;
    }
};