#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch - 'a']!=NULL);
    }
    
    void put(char ch,Node* node){
        links[ch - 'a']=node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void setEnd(){
        flag=true;
    }
    
    isEnd(){
        return flag;
    }
}

class Trie{
    
    private: Node* root;

    
    public:
    
        Trie(){
            root=new Node();            
        }
        
        /* Inserts a word into the trie */
        // tc -> O(len)
        
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        
        /**return  if the word is in the trie*/
        // O(len)
        
        bool search(string word){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return node->isEnd();
        }
        
        /** Returns if there is any word in the trie that startWith the given word */
        // O(len)
        
        bool startWith(string prefix){
            Node* node=root;
            for(int i=0;i<word.length();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node=node->get(word[i]);
            }
            return true;
        }
}

int main() {
    
}
