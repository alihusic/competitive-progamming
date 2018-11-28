#include<iostream>
#include<vector>

using namespace std;

int dp [ 6000 ];
int n;
const int inf = 1 << 29;
vector <int > clubs;

int main()
{
    cin >> n;
    int c;
    cin >> c;
    int t;
    for ( int i ( 0 ); i < 6000; i ++ ) dp [ i ] = inf;
    for ( int i ( 0 ); i < c; i ++ )
    {
        cin >> t;
        clubs.push_back ( t );
        dp [ t ] = 1;
    }
    for ( int i ( 1 ); i <= n; i ++ )
    {
        for ( int j ( 0 ); j < c; j ++ )
        {
            if ( dp [ i + clubs [ j ] ] > dp [ i ] + 1 )
            {
                dp [ i + clubs [ j ] ] = dp [ i ] + 1;
            }
        }
    }
    if ( dp [ n ] != inf )
    {
        cout << "Roberta wins in " << dp [ n ] << " strokes." << endl;
    }
    else
    {
        cout << "Roberta acknowledges defeat." << endl;
    }
    return 0;
}
