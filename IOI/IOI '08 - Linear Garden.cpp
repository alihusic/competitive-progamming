#include<iostream>
#include<string>

using namespace std;

string s;
int n, m;
long long dp [ 1000020 ][ 3 ][ 3 ];

int main()
{
    cin >> n;
    cin >> m;
    cin >> s;
    dp [ 0 ][ 0 ][ 0 ] = 1;
    for ( int i = 1; i <= n; i ++ )
    {
        for ( int k = 0; k < 2; k ++ )
        {
            for ( int j = 0; j < 3; j ++ )
            {
                dp [ i ][ k + 1 ][ max ( j - 1, 0 ) ] += dp [ i - 1 ][ k ][ j ];
            }
        }
        for ( int k = 0; k < 2; k ++ )
        {
            for ( int j = 0; j < 3; j ++ )
            {
                dp [ i ][ max ( j - 1, 0 ) ][ k + 1 ] += dp [ i - 1 ][ j ][ k ];
            }
        }
        for ( int k = 0; k < 2; k ++ )
        {
            for ( int j = 0; j < 3; j ++ )
            {
                dp [ i ][ k ][ j ] %= m;
            }
        }
    }
    long long sum = 1;
    int L = 0;
    int P = 0;
    for ( int i = 0; i < n; i ++ )
    {
        if ( s [ i ] == 'L' )
        {
            L ++;
            P = max ( P - 1, 0 );
        }
        else
        {
            if ( L < 2 )
            {
                for ( int k = 0; k <= 2 - L - 1; k ++ )
                {
                    for ( int j = 0; j <= 2 - (max ( P - 1, 0 ) ); j ++ )
                    {
                        sum += dp [ n - i - 1 ][ k ][ j ];

                    }
                    sum %= m;
                }
            }
            P ++;
            L = max ( L - 1, 0 );
        }
    }
    cout << sum << endl;
    return 0;
}
