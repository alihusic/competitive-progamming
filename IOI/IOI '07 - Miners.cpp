#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

const int INF = -(1 << 29);
int dp [ 2 ][ 4 ][ 4 ][ 4 ][ 4 ];
int n;
string s;

inline int value ( const char &a )
{
    if ( a == 'B' ) return 1;
    if ( a == 'F' ) return 2;
    return 3;
}

inline int izrac ( const int &a, const int &b, const int &c )
{
    int sum = 0;
    if ( a == 1 || b == 1 || c == 1 ) sum ++;
    if ( a == 2 || b == 2 || c == 2 ) sum ++;
    if ( a == 3 || b == 3 || c == 3 ) sum ++;
    return sum;
}

int main()
{
    scanf ( "%d", &n );
    cin >> s;
    //scanf ( "%s", &s );
    for ( int i = 0; i <= 1; i ++ )
    {
        for ( int x1 = 0; x1 < 4; x1 ++ )
        {
            for ( int x2 = 0; x2 < 4; x2 ++ )
            {
                for ( int y1 = 0; y1 < 4; y1 ++ )
                {
                    for ( int y2 = 0; y2 < 4; y2 ++ )
                    {
                        dp [ i ][ x1 ][ x2 ][ y1 ][ y2 ] = INF;
                    }
                }
            }
        }
    }
    dp [ 0 ][ 0 ][ 0 ][ 0 ][ 0 ] = 0;
    int val;
    int best = 0;
    for ( int i = 0; i <= n; i ++ )
    {
        for ( int x1 = 0; x1 < 4; x1 ++ )
        {
            for ( int x2 = 0; x2 < 4; x2 ++ )
            {
                for ( int y1 = 0; y1 < 4; y1 ++ )
                {
                    for ( int y2 = 0; y2 < 4; y2 ++ )
                    {
                        val = value ( s [ i ] );
                        //cout << "D" << endl;
                        //dp [ i + 1 ][ x1 ][ x2 ][ y1 ][ y2 ] = max ( dp [ i + 1 ][ x1 ][ x2 ][ y1 ][ y2 ], )

                        dp [ 1 ][ x2 ][ val ][ y1 ][ y2 ] = max (dp [ 1 ][ x2 ][ val ][ y1 ][ y2 ], dp [ 0 ][ x1 ][ x2 ][ y1 ][ y2 ] + izrac ( x1, x2, val ) );
                        dp [ 1 ][ x1 ][ x2 ][ y2 ][ val ] = max ( dp [ 1 ][ x1 ][ x2 ][ y2 ][ val ], dp [ 0 ][ x1 ][ x2 ][ y1 ][ y2 ] + izrac ( y1, y2, val ) );

                        best = max ( best, dp [ 0 ][ x1 ][ x2 ][ y1 ][ y2 ] );
                    }
                }
            }
        }
        for ( int x1 = 0; x1 < 4; x1 ++ )
        {
            for ( int x2 = 0; x2 < 4; x2 ++ )
            {
                for ( int y1 = 0; y1 < 4; y1 ++ )
                {
                    for ( int y2 = 0; y2 < 4; y2 ++ )
                    {
                        dp [ 0 ][ x1 ][ x2 ][ y1 ][ y2 ] = dp [ 1 ][ x1 ][ x2 ][ y1 ][ y2 ];
                        dp [ 1 ][ x1 ][ x2 ][ y1 ][ y2 ] = INF;
                    }
                }
            }
        }

    }
    for ( int x1 = 0; x1 < 4; x1 ++ )
    {
        for ( int x2 = 0; x2 < 4; x2 ++ )
        {
            for ( int y1 = 0; y1 < 4; y1 ++ )
            {
                for ( int y2 = 0; y2 < 4; y2 ++ )
                {
                    best = max ( best, dp [ 1 ][ x1 ][ x2 ][ y1 ][ y2 ] );
                }
            }
        }
    }
    cout << best << endl;
    return 0;
}
