class TrieNode{
    public:
    char word;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char data){
        word= data;
        for(int i=0; i<26; i++){
            children[i]= NULL;
        }
        isTerminal= false;
    }
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root= new TrieNode('\0');
    }
    
    void insertWord(TrieNode* root, string word){
        if(word.length() == 0){
            root->isTerminal= true;
            return;
        }
        int index= word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child= root->children[index];
        }else{
            child= new TrieNode(word[0]);
            root->children[index]= child;
        }
        return insertWord(child, word.substr(1));
    }
    void insert(string word) {
        return insertWord(root, word);
    }
    
    bool searchWord(TrieNode* root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index= word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child= root->children[index];
        }else{
            return false;
        }
        return searchWord(child, word.substr(1));
    }
    bool search(string word) {
        return searchWord(root, word);
    }
    
    bool prefixWord(TrieNode* root, string word){
        if(word.length() == 0){
            return true;
        }
        int index= word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){
            child= root->children[index];
        }else{
            return false;
        }
        return prefixWord(child, word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixWord(root, prefix);
    }
};
