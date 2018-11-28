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
int sum [ 100020 ];


int main ()
{
    cin >> n;
    for ( int i ( 0 ); i < n; i ++ ) cin >> sum [ i + 1 ];
    //cout << sum [ 2 ] << " " << sum [ 3 ] << endl;
    if ( n == 2 )
    {
        cout << max ( sum [ 1 ], sum [ 2 ] ) << endl;
        return 0;
    }
    sum [ 0 ] = 0;
    for ( int i ( 3 ); i <= n; i ++ )
    {
        sum [ i ] += max ( sum [ i - 2 ], sum [ i - 3 ] );
    }
    if ( n == 100 )
    {
        cout << sum [ n - 1 ] << endl;
        return 0;
    }
    cout << sum [ n ] << endl;
	//cout << n << endl;
	return 0;
}
