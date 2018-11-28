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

int n1 [ 10010 ];
int n2 [ 10010 ];

int main ()
{
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    char t;
    int res = 0;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> t;
        n1 [ i ] = t - 'A';
    }
    for ( int i = 0; i < n; i ++ )
    {
        cin >> t;
        n2 [ i ] = t - 'A';
        if ( n1 [ i ] == n2 [ i ] ) res ++;
    }
    cout << res << endl;
	return 0;
}
