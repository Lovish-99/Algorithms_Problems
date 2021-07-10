#include<iostream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t,min,max,num1,num2,num3,num4,c;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector <int> a(n);
        vector <int> b(5);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        min=*min_element(a.begin(),a.end());
        num1=0;
        for (int i=0;i<n;i++){
            c=floor((a[i]-min)/5.0);
            a[i]-=(5*floor((a[i]-min)/5.0));
            num1+=c;
        }
        min=*min_element(a.begin(),a.end()); 
        for (int i=0;i<n;i++){
            b[a[i]-min]++; 
        }
        num2=1*(b[1]+b[2])+2*(b[3]+b[4]);
        num3=1*(b[0]+b[1]+b[4])+2*(b[2]+b[3]);
        if (num3<num2){
            num2=num3;
        }
        num4=1*(b[0]+b[3])+2*(b[1]+b[2]+b[4]);
        if (num4<num2){
            num2=num4;
        }
        cout << num1+num2 << endl;
    }
    return 0;
}