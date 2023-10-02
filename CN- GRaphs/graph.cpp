#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printDFS(int **edges,int n,int sv,bool *visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv)continue;
        if(edges[sv][i]==1){
            if(visited[i]==true)continue;
            printDFS(edges,n,i,visited);
        }
    }
}
void printBFS(int **edges,int n,int sv,bool *visited){
    queue<int> pending;
    pending.push(sv);
    visited[sv]=true;
    while(!pending.empty()){
        int currentVertex=pending.front();
        cout<<currentVertex<<" ";
        pending.pop();
        for(int i=0;i<n;i++){
            if(i==currentVertex)continue;
            if(edges[currentVertex][i] && !visited[i]){
                pending.push(i);
                visited[i]=1;
            }
        }
        cout<<endl;
    }
}
void DFS(int ** edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i])
            printDFS(edges,n,i,visited);
    }
    delete []visited;
}
void BFS(int ** edges,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    for(int i=0;i<n;i++){
        if(!visited[i])
            printBFS(edges,n,i,visited);
    }
    delete []visited;
}
bool hasPath(int ** edges,int n,int s,int e,bool * visited){
    if(s==e)return true;
    visited[s]=true;
    for(int i=0;i<n;i++){
        if(i==s)continue;
        if(edges[s][i]==1){
            if(visited[i]==true)continue;
            return hasPath(edges,n,i,e,visited);
        }
    }
    return false;
}
bool hasPathMain(int ** edges,int n,int s,int e){
     bool *visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    return hasPath(edges,n,s,e,visited);
}
vector<int> * getPath(int ** edges,int n,int s,int e,bool * visited){
    

}
int main(){
    int n;//No of vertics
    int e;//No of edges
    cout<<"Enter number of Vertics and Edges: "<<endl;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
       edges[i]=new int[n];
       for(int j=0;j<n;j++){
        edges[i][j]=0;
       }
    }
    cout<<"Enter connections : "<<endl;
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    cout<<"BFS : "<<endl;
    BFS(edges,n);
    cout<<"DFS : "<<endl;
    DFS(edges,n);
    
    hasPathMain(edges,n,0,2)?cout<<"YES":cout<<"NO";


    return 0;
}