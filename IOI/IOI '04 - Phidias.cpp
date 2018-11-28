#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int maxw;
int maxh;
int n;
const int INF = 1 << 29;

int dp [ 605 ][ 605 ];

int opt ( const int &x, const int &y )
{
    if ( dp [ x ][ y ] != INF ) return dp [ x ][ y ];
    dp [ x ][ y ] = min ( dp [ x ][ y ], x * y );
    for ( int i = 1; i < (x/2)+1; i ++ )
    {
        dp [ x ][ y ] = min ( dp [ x ][ y ], opt ( x - i, y ) + opt ( i, y ) );
    }
    for ( int j = 1; j < (y/2)+1; j ++ )
    {
        dp [ x ][ y ] = min ( dp [ x ][ y ], opt ( x, y - j ) + opt ( x, j ) );
    }
    return dp [ x ][ y ];
}

int main()
{
    for ( int i = 0; i < 605; i ++ )
    {
        for ( int j = 0; j < 605; j ++ )
        {
            dp [ i ][ j ] = INF;
        }
    }
    //cin >> maxw >> maxh;
    scanf ( "%d %d", &maxw, &maxh );

    //cin >> n;
    scanf ( "%d", &n );
    int a, b;
    for ( int i = 0; i < n; i ++ )
    {
        //cin >> a >> b;
        scanf ( "%d %d", &a, &b );
        dp [ a ][ b ] = 0;
    }
    int result = opt ( maxw, maxh );
    cout << dp [ maxw ][ maxh ] << endl;
    return 0;
}
