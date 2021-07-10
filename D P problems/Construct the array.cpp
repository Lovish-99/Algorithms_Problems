#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<long> a(n+1, 0);
    vector<long> b(n+1, 0);
    a[2] = 1;
    b[2] = 0;
    for (int i=3; i<=n; i++) {
        a[i] = b[i-1] + (k-2) * a[i-1];
        b[i] = (k-1) * a[i-1];
        a[i] %= long(1e9+7);
        b[i] %= long(1e9+7);
    }
    if(x==1){
        cout<<b[n];
    }
    else{
        cout<<a[n];
    }
    return 0;
}
