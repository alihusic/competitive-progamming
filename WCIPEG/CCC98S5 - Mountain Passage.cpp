#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>


using namespace std;

int elev [ 30 ][ 30 ];
int mx [ 4 ] = { 0, 0, 1, -1 };
int my [ 4 ] = { 1, -1, 0, 0 };
int n;
int startelev;
int best [ 30 ][ 30 ];
const int inf = 1<<29;


void dijkstra ()
{
    for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < n; j ++ )
        {
            best [ i ][ j ] = inf;
        }
    }
    best [ 0 ][ 0 ] = 0;
    queue < pair < int, int > > q;
    q.push ( make_pair ( 0, 0 ) );
    pair < int, int > curr;
    int a, b;
    while ( !q.empty() )
    {
        //cout << best [ curr.first ][ curr.second ] << endl;
        curr = q.front();
        q.pop();
        for ( int i ( 0 ); i < 4; i ++ )
        {
            a = mx [ i ];
            b = my [ i ];
            if ( curr.first + a < n && curr.first + a > -1 && curr.second + b < n && curr.second + b > -1 && abs ( elev [ curr.first ][ curr.second ] - elev [ curr.first + a ][ curr.second + b ] ) <= 2 )
            {
                int consume = 0;
                if ( elev [ curr.first ][ curr.second ] > startelev || elev [ curr.first + a ][ curr.second + b ] > startelev ) consume = 1;
                if ( best [ curr.first ][ curr.second ] + consume < best [ curr.first + a ][ curr.second + b ] )
                {
                    q.push ( make_pair ( curr.first + a, curr.second + b ) );
                    best [ curr.first + a ][ curr.second + b ] = best [ curr.first ][ curr.second ] + consume;
                }
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for ( int test ( 0 ); test < t; test ++ )
    {
        cin >> n;
        for ( int i ( 0 ); i < n; i ++ )
        {
            for ( int j ( 0 ); j < n; j ++ )
            {
                cin >> elev [ i ][ j ];
            }
        }
        startelev = elev [ 0 ][ 0 ];
        dijkstra ();
        if ( best [ n - 1 ][ n - 1 ] != inf )
        {
            cout << best [ n - 1 ][ n - 1 ] << endl;
        }
        else
        {
            cout << "CANNOT MAKE THE TRIP" << endl;
        }

    }
    return 0;
}
