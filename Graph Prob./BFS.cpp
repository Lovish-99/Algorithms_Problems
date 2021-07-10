#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>arr;
void bfs(int u,vector<vector<int>>a,vector<bool>v){
    v[u]=true;
    queue<int>q;
    q.push(u);
    arr[u]=0;
    while(!q.empty()){
        u=q.front();
        q.pop();        
        for(int i:a[u]){
            if(!v[i]&&arr[i]==-1){
                arr[i]=arr[u]+1;
                v[i]=true;
                q.push(i);   
            }
        }
    }
}
int main() {
  int q;
  cin>>q;
  for(int t=0;t<q;t++){
      int n,m;
      cin>>n>>m;
      vector<vector<int>>a(n);
      for(int i=0;i<m;i++){
          int x,y;
          cin>>x>>y;
          a[x-1].push_back(y-1);
          a[y-1].push_back(x-1);
      }
      int s;
      cin>>s;
      vector<bool>v1(n+1,false);
      arr.resize(n,-1);
      bfs(s-1,a,v1);
      for(int i=0;i<arr.size();i++){
          if(arr[i]==-1)
              cout<<arr[i]<<" ";
          else if(arr[i]!=0)
              cout<<arr[i]*6<<" ";
      }
      cout<<endl;
      arr.clear();
  }
    return 0;
}