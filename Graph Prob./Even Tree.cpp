#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int main(){   
    int v,e,x,y,r;
    cin>>v>>e;
    vector<int>tree(v,0);
    vector<int>count(v,1);

    for(int i=0;i<e;i++){
        cin>>x>>y;
        tree[x-1] = y;
        count[y-1] += count[x-1];
        r = tree[y-1];
        while(r!=0){
            count[r-1] += count[x-1];
            r = tree[r-1];
        }
    }
    r = -1;
    for(int i=0;i<v;i++)
        if((count[i] & 1) ==0)
            r++;  
    printf("%d\n",r);
    return 0;
}