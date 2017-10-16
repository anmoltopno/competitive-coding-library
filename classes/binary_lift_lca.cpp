#include<bits/stdc++.h>
using namespace std;
#define LG 15

vector<int> level;
vector<vector<int> > graph;
vector<vector<int> > p;
vector<bool> vis;

/********************************** zero indexed *************************************/

void dfs(int prnt,int u){
    vis[u] = true;
    level[u] = level[prnt] + 1;
    p[u][0] = prnt;
    for(auto v : graph[u]){
        if(!vis[v]){
            dfs(u,v); 
        }
    }
}

int lca(int n1,int n2){
    if(level[n2]>level[n1]) swap(n1,n2);
    // cout<<level[n2]<<' '<<level[n1];
    int diff = level[n1]-level[n2];
    int temp=n1;
    for(int i=0; i<15; i++){
        if((diff&1<<i)){
            temp = p[temp][i];
        }
    }
    // cout<<temp;
    if(temp == n2){
        return temp;
    }
    // temp n2
    for(int i=LG; i>=0; i--){
        if(p[temp][i] != p[n2][i]){
            temp = p[temp][i];
            n2 = p[n2][i];
        }
    }
    return p[temp][0];
}
                                   //root as 0
int dis_nds(int n1, int n2){
    int lc = lca(n1,n2);
    return level[n1]+level[n2]-2*level[lc];
}

int getancestor(int n, int rth){
    
    for(int i=0; i<15; i++){
        if(rth&(1<<i)){
            n = p[n][i];
        }
    }
    return n;
}

int main(){
    int nv;
    cin>>nv;
    
    level.assign(nv,0);
    level[0] = -1;
    p.resize(nv);
    for(int i=0; i<nv; i++) p[i].resize(LG+1);
    for(int i=0; i<nv; i++) for(int j=0; j<LG; j++) p[i][j] = -1;
    graph.resize(nv);
    vis.assign(nv,false);
    
    for(int i=0; i<nv-1; i++){
        int u,v;
        cin>>u>>v;
        //graph in 1 indexed
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0,0);
    
    for(int j=0; j<nv; j++)
    for(int i=0; i<LG; i++){
        if(p[j][i]!=-1){
            p[j][i+1] = p[p[j][i]][i];        
        }
    }
    
    //cout<<getancestor(5,4);
    return 0;
}
