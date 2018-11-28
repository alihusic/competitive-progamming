#include<iostream>
#include<algorithm>

using namespace std;

int n;

int dp [ 20000 ];

int main()
{
    cin >> n;
    int pos = 0;
    for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j <= i; j ++ )
        {
            cin >> dp [ pos ];
            if ( i != 0 )
            {
                if ( j == 0 ) dp [ pos ] += dp [ pos - i ];
                if ( j == i ) dp [ pos ] += dp [ pos - i - 1 ];
                if ( j != 0 && j != i )
                {
                    dp [ pos ] += max ( dp [ pos - i ], dp [ pos - i - 1 ] );
                }
            }
            pos ++;
        }
    }
    int best = 0;
    for ( int i ( 0 ); i < n*n; i ++ ) best = max ( best, dp [ i ] );
    cout << best << endl;
    return 0;
}
