#include<iostream>

using namespace std;

int n;
int dp [ 1010 ][ 1010 ];
int arr [ 1010 ];

int f ( const int a, const int b )
{
    //cout << a << " " << b << endl;
    if ( dp [ a ][ b ] != -1 ) return dp [ a ][ b ];
    if ( b - a == 1 )
    {
        dp [ a ][ b ] = max ( arr [ a ], arr [ b ] );
        return dp [ a ][ b ];
    }
    //dp [ a ][ b ] = max ( arr [ a ] + min ( f ( a + 2, b ) + arr [ a + 1 ], f ( a + 1, b - 1 ) + arr [ b ] ) , arr [ b ] + min ( f ( a, b - 2 ) + arr [ b - 1 ], f ( a + 1, b - 1 ) + arr [ a ] ) );
    dp [ a ][ b ] = max ( arr [ a ] + min ( f ( a + 2, b ), f ( a + 1, b - 1 ) ) , arr [ b ] + min ( f ( a, b - 2 ), f ( a + 1, b - 1 ) ) );
    return dp [ a ][ b ];
}

int main()
{
    cin >> n;
    int sum = 0;
    for ( int i ( 0 ); i < n; i ++ ) cin >> arr [ i ];
    for ( int i ( 0 ); i < n; i ++ ) sum += arr [ i ];
    for ( int i ( 0 ); i <= n; i ++ )
    {
        for ( int j ( 0 ); j <= n; j ++ )
        {
            dp [ i ][ j ] = -1;
        }
        dp [ i ][ i ] = arr [ i ];
    }
    cout << f ( 0 , n - 1 ) << " " << sum - f ( 0, n - 1 ) << endl;
    /*for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < n; j ++ )
        {
            cout << dp [ i ][ j ] << " ";
        }
        cout << endl;
    }*/
    return 0;
}
