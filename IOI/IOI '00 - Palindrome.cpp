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

//int dp [ 501 ][ 501 ];
int up [ 5010 ];
int curr [ 5010 ];
int n;

int main ()
{
    //return 0;
    cin >> n;
    string a;

    cin >> a;
    string b;
    b = a;
    //cout << "DDD" << endl;
    reverse ( b.begin(), b.end() );

    for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < n; j ++ )
        {
            up [ j ] = curr [ j ];
            curr [ j ] = 0;
        }
        for ( int j ( 0 ); j < n; j ++ )
        {
            if ( i != 0 && j != 0 )
            {
                if ( a [ i ] == b [ j ] )
                {
                    //dp [ i ][ j ] = dp [ i - 1 ][ j - 1 ] + 1;
                    curr [ j ] = up [ j - 1 ] + 1;
                }
                else
                {
                    //dp [ i ][ j ] = max ( dp [ i - 1 ][ j ], dp [ i ][ j - 1 ] );
                    curr [ j ] = max ( curr [ j - 1 ], up [ j ] );
                }
            }
            else
            {
                if ( a [ i ] == b [ j ] ) curr [ j ] = 1;
            }
        }
    }
    //cout << n - dp [ n - 1 ][ n - 1 ] << endl;
    //if ( b [ 0 ] == a [ 0 ] ) curr [ n - 1 ] ++;
    cout << n - curr [ n - 1 ] << endl;
	return 0;
}
