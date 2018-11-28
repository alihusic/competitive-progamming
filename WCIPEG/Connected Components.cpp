#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
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
bool matrix [ 1010 ][ 1010 ];
bool vis [ 1010 ];
vector< int > path;

void dfs ( const int curr )
{
    vis [ curr ] = 1;
    path.push_back ( curr );
    for ( int i ( 0 ); i < n; i ++ )
    {
        if ( i != curr )
        {
            if ( vis [ i ] == false && matrix [ curr ][ i ] == true ) dfs ( i );
        }
    }
    return;
}

int main ()
{
    cin >> n;
    int t;
    for ( int i ( 0 ); i < n; i ++ )
    {
        vis [ i ] = 0;
        for ( int j ( 0 ); j < n; j ++ )
        {
            matrix [ i ][ j ] = 0;
            cin >> t;
            if ( t == 1 ) matrix [ i ][ j ] = true;
            //cin >> matrix [ i ][ j ];
        }
    }
    for ( int i ( 0 ); i < n; i ++ )
    {
        if ( vis [ i ] == false )
        {
            path.clear();
            dfs ( i );
            sort ( path.begin(), path.end() );
            for ( int j ( 0 ); j < path.size(); j ++ ) cout << path [ j ] + 1 << " ";
            cout << endl;
        }

    }
	return 0;
}
