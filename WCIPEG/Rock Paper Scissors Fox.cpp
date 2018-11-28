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
int n;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    string t;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> t;
        if ( t == "Foxen" ) break;
        if ( t == "Rock" ) cout << "Paper" << endl;
        if ( t == "Paper" ) cout << "Scissors" << endl;
        if ( t == "Scissors" ) cout << "Rock" << endl;
        if ( t == "Fox" ) cout << "Foxen" << endl;

    }
	return 0;
}
