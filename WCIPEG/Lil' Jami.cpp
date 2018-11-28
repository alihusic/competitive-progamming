#include<iostream>

using namespace std;

int arr[1000020];
int n,q,k;

int main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    int tmp;
    for(int i=0;i<k;++i){
        cin>>tmp;
        arr[tmp]++;
    }
    for(int i=1;i<n;++i){
        arr[i]+=arr[i-1];
    }
    cin>>q;
    int a,b;
    for(int i=0;i<q;++i){
        cin>>a>>b;
        if(a==0){
            cout<<arr[b]<<'\n';
        }else{
            cout<<arr[b]-arr[a-1]<<'\n';
        }
    }
    return 0;
}
