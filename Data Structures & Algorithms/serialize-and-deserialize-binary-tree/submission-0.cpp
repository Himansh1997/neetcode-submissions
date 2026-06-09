class Codec {
    public:
    string join(const vector<string>& v, const string& delim){
        ostringstream s;
        for(const auto &i : v){
            if(&i != &v[0])
            s << delim;
            s << i;
        }
        return s.str();
    }
    void dfsSerialize(TreeNode* node, vector<string>& result){
        if(! node){
            result.push_back("#");
            return;
        }
        result.push_back(to_string(node->val));
        dfsSerialize(node->left, result);
        dfsSerialize(node->right, result);
    }
    string serialize(TreeNode* root){
        vector<string> result;
        dfsSerialize(root, result);
        return join(result, ",");
    }
    vector<string> split(const string& s, char delim){
        vector<string> elements;
        string item;
        stringstream ss(s);
        while(getline(ss, item, delim)){
            elements.push_back(item);
        }
        return elements;
    }
    TreeNode* dfsDeserialize(vector<string>& value, int& i){
        if(value[i] == "#"){
            i++;
            return NULL;
        }
        TreeNode* node= new TreeNode(stoi(value[i]));
        i++;
        node->left= dfsDeserialize(value, i);
        node->right= dfsDeserialize(value, i);
        return node;
    }
    TreeNode* deserialize(string data){
        vector<string> value= split(data, ',');
        int i=0;
        return dfsDeserialize(value, i);
    }
};