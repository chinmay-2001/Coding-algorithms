#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

class Node{
    public:
        char s;
        unordered_map<char,Node*> children;
        string word;
        bool isTerminal;
    
    Node(char s){
        this->s=s;
        isTerminal=false;
        word="";
    }
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node('\0');
    }
    
    void addWord(string word){
        Node* temp=root;
        for(auto ch:word){
            if(temp->children.count(ch)==0){
                temp->children[ch]=new Node(ch);
            }
            temp=temp->children[ch];
        }
        temp->isTerminal=true;
        temp->word=word;
    }
};

//main algorithms(8-way dfs + trie guided search)
void dfs(char board[M][N],Node* node,int i, int j,bool visited[][N],unordered_set<string>& output){
    //base case
    char ch=board[i][j];
    if(node->children.count(ch)==0){
        return;
    }
    
    //otherwise trie contains this node
    visited[i][j]=true;
    node=node->children[ch];
    
    // If it is a terminal node in the trie
    if(node->isTerminal){
        output.insert(node->word);
    }
    
    //
    int dx[]={0,1,1,1,0,-1,-1,-1};
    int dy[]={-1,-1,0,1,1,1,0,-1};
    
    for(int k=0;k<8;k++){
        int ni=i+dx[k];
        int nj=j+dy[k];
        //if it is in bound and not visited
        if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
            dfs(board,node,ni,nj,visited,output);
        }
    }
    
    //last Step (backtracking)
    visited[i][j]=false;
    return;
}

int main() {
	// Board Game
    string words[]={"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};
    char board[M][N]={{'S','E','R','T'},
                        {'U','N','K','S'},
                        {'T','C','A','T'}};
    //1. trie
    Trie t;
    for(auto w:words){
        t.addWord(w);
    }
    
    //2. Take a container to store word that are found in dfs search
    unordered_set<string> output;
    
    //3. Step (8-way dfs search)
    bool visited[M][N]={0};
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            dfs(board,t.root,i,j,visited,output);
            //reset the visited array after every call
        }
    }
    
    for(auto word:output){
        cout<<word<<endl;
    }
}
