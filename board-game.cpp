#include <bits/stdc++.h>
using namespace std;
#define M 3;
#define N 4;

struct Node{
    Node* arr[26];
    int flag=false;
    
    bool containsKey(chra ch){
        return arr[ch-'a']!==NULL;
    }
    Node* get(char ch){
        return arr[ch-'a'];
    }
    
    void put(char ch,Node* node){
        arr[ch-'a']=node;
    }
    
    void setEnd(){
        flag=true;
    }
    
    void isEnd(){
        return flag;
    }
}

class Trie{
    private:
    Node* root;
    int* visited;
    
    public:
    Trie(){
        root=new Node();
    }
    public: 
    void insert(string word){
        Node* node =root;
        for(int i=0;i<word.length();i++){
            if(!containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    public: 
    bool checkIfPrefixExits(string word){
        bool fl=true;
        for(int i=0;i<word.length();i++){
            if(node->containsKey(word)[i]){
                node=node->get(word[i]);
                if(node->isEnd()==false)return false;
            }
            else {
                return false;
            }
        }
        return false;
    }
    public:
    bool checkValidString(string word){
        
    }
}
int main() {
    int n;
    vector<string> a;
    Trie trie;
    for(auto &it:a){
        trie.insert(it);
    }
    ///longest common prefix
    // string longest="";
    // for(auto &it:a){
    //     if(trie.checkIfPrefixExits(it)){
    //         if(it.length()>longest.length()){
    //             longest=it;
    //         }else if(it.length()==longest.length() && it<longest){
    //             longest=it;
    //         }
    //     }
    // }
    // if(longest=="")return "None";
    
    //Board Game
    
    string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
    char boggle[M][N]={{'S','E','R','T'},
                        {'U','N','K','S'},
                        {'T','U','A','T'}};
    
    for(auto &it:a){
        if(trie.checkValidString(it)){
            cout<<"true"<<endl;
        }
    }
}
