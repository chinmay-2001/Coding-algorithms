#include <bits/stdc++.h>
using namespace std;

const int N=1e5+1;
vector<int> gr[N];
int vis[N];
bool cycle=false;
void dfs(int cur,int par){
    cout<<cur<<endl;
    vis[cur]=1;
    for(auto x:gr[cur]){
        if(!vis[x]){
            dfs(x,cur);
        }else if(x!=par){
            //backedge
            cout<<cur<<" "<<x<<endl;
            cycle=true;
            
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    cout<<"cycle found:"<<cycle<<endl;
    return 0;
    
}
