#include<iostream>
#include<algorithm>

using namespace std;

long long dp [ 100 ];
long long places [ 100 ] = { 0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000 };

int main ()
{
    int toadd;
    int a;
    int b;
    long long dp [ 100 ];
    cin >> a;
    cin >> b;
    cin >> toadd;
    int n = 14 + toadd;
    for ( int i  ( 0 ); i < 100; i ++ ) dp [ i ] = 0;
    for ( int i ( 0 ); i < toadd; i ++ )
    {
        cin >> places [ i + 14 ];
    }
    sort ( places, places + n );
    dp [ 0 ] = 1;
    for ( int i ( 0 ); i < n; i ++ )
    {
        int j = i + 1;
        while ( j < n )
        {
            if ( places [ j ] - places [ i ] >= a && places [ j ] - places [ i ] <= b )
            {
                dp [ j ] += dp [ i ];
            }
            j ++;
        }
    }
    //for ( int i ( 0 ); i < n; i ++ ) cout << places [ i ] << endl;
    cout << dp [ n - 1 ] << endl;
    return 0;
}
