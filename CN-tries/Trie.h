#include"TrieNode.h"
using namespace std;
class Trie{
    TrieNode *root;
    void insertHelper(TrieNode *root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertHelper(child,word.substr(1));
    }
    void suffixInsertHelper(TrieNode *root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0],true);
            root->children[index]=child;
        }
        insertHelper(child,word.substr(1));
    }
    bool searchHelper(TrieNode *root,string word){
        if(word.length()==0 && root->isTerminal==true){
            return true;
        }
        int index=word[0]-'a';
        if(root->children[index]){
            TrieNode *child=root->children[index];
            return searchHelper(child,word.substr(1));
        }
        return false;
    }
    void removeHelper(TrieNode *root,string word){
        if(word.length()==0 && root->isTerminal==true){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]){
            child=root->children[index];
        }
        else 
            return;
        removeHelper(child,word.substr(1));

        if(root->isTerminal==false){
            for(int i=0;i<26;i++){
                if(root->children[i])
                    return;
            }
        }
        delete child;
        root->children[index]=NULL;
    }
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insert(string word){
        insertHelper(root,word);
    }
    bool search(string word){
        return searchHelper(root,word);
    }
    void remove(string word){
        removeHelper(root,word);
    }
    void suffixInsert(string word){
        for(int i=0;i<word.length();i++){
            if(!search(word.substr(i))){
                suffixInsertHelper(root,word.substr(i));
            }
        }
    }

};