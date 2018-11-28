#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<utility>

using namespace std;

#define mp make_pair
#define pb push_back
#define	xx first
#define yy second

const int INF = 1 << 29;
typedef long long lint;
typedef pair < int, int > tacka;

class Node{
public:
    bool visited;
    vector<int> out;
    long long path;
    int in;
    Node(){
        visited=false;
        path=0;
        in=0;
        out.clear();
    }
};

Node nodes[10000];

void krampa(int curr){
    for(int i=0;i<nodes[curr].out.size();i++){
        nodes[nodes[curr].out[i]].in--;
        nodes[nodes[curr].out[i]].path+=nodes[curr].path;
    }
    bool changed=true;
    while(changed){
        changed=false;
        for(int i=0;i<nodes[curr].out.size();i++){
            if(nodes[nodes[curr].out[i]].in==0 && nodes[nodes[curr].out[i]].visited==false){
                krampa(nodes[curr].out[i]);
                changed=true;
            }
        }
    }
    nodes[curr].visited=true;
    return;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int from,to;
    while(true){
        cin>>from>>to;
        if(from==0 && to==0)break;
        nodes[from].out.push_back(to);
        nodes[to].in++;
    }
    nodes[1].path=1;
    krampa(1);
    cout<<nodes[n].path<<endl;
	return 0;
}
