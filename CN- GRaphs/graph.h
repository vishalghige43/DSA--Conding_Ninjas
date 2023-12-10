
#include<queue>
class graph{
private:
    int n,e;
    int **edges;
    bool *visited;

    void bfsPrint(){
        std::queue<int> pending;
        pending.push(0);
        visited[0]=true;
        while(!pending.empty()){
            int curr=pending.front();
            pending.pop();
            std::cout<<curr<<"\t";
            for(int i=0;i<n;i++){
                if(i!=curr && edges[curr][i]==1 && !visited[i]){
                    pending.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    void dfsPrint(int sv){
        std:: cout<<sv<<"\t";
        visited[sv]=true;
        for(int i=0;i<n;i++){
            if(i==sv)continue;
            if(edges[sv][i]==1 && !visited[i]){
                dfsPrint(i);
            }
        }
    }
    void resetVisited(){
        for(int i=0;i<n;i++){
            visited[i]=false;
        } 
    }

public:
    graph(int n,int e){
        this->n=n;
        this->e=e;
        edges=new int*[n];
        for(int i=0;i<n;i++){
            edges[i]=new int [n];
            for(int j=0;j<n;j++){
                edges[i][j]=0;
            }
        }
        visited=new bool[n];
        resetVisited();
    }
    void input(){
        for(int i=0;i<e;i++){
            int f,s;
            std::cin>>f>>s;
            edges[f][s]=1;
            edges[s][f]=1;
        }
    }
   
    void DFS(){
        for(int i=0;i<n;i++){
            if(!visited[i])
            dfsPrint(i);
        }
        std::cout<<"\n";
        resetVisited();
    }

    void BFS(){
        for(int i=0;i<n;i++){
            if(!visited[i])
            bfsPrint();
        }std:: cout<<"\n";
        resetVisited();
    }
    bool hasPath(int s,int e){
        if(s==e)return true;
        for(int i=0;i<n;i++){
           if(i!=s && edges[s][i]==1 && !visited[i]){
            return hasPath(i,e);
            visited[i]=true;
           }
        }
        return false;
    }
};