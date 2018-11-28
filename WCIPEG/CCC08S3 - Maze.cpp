#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<queue>
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
int direction [ 25 ][ 25 ];
int best [ 25 ][ 25 ];
int mx [ 4 ] = { 0, 1, 0, -1 };
int my [ 4 ] = { 1, 0, -1, 0 };

int row, column;

void bfs ( const int &x, const int &y )
{
    queue < pair < int, int > > q;
    int a, b;
    while ( !q.empty() ) q.pop();
    q.push( make_pair ( x, y ) );
    pair < int, int > curr;
    while ( !q.empty() )
    {
        curr = q.front();
        q.pop();
        if ( direction [ curr.first ][ curr.second ] == 2 )
        {
            for ( int i ( 0 ); i < 4; i ++ )
            {
                a = mx [ i ];
                b = my [ i ];
                if ( curr.first + a < row && curr.first + a > -1 && curr.second + b < column && curr.second + b > -1 && direction [ curr.first + a ][ curr.second + b ] > -1 )
                {
                    if ( best [ curr.first + a ][ curr.second + b ] > best [ curr.first ][ curr.second ] + 1 )
                    {
                        best [ curr.first + a ][ curr.second + b ] = best [ curr.first ][ curr.second ] + 1;
                        q.push( make_pair ( curr.first + a, curr.second + b ) );
                    }
                }
            }
        }
        else
        {
            for ( int i ( 0 ); i < 4; i ++ )
            {
                if ( i % 2 == direction [ curr.first ][ curr.second ] )
                {
                    a = mx [ i ];
                    b = my [ i ];
                    if ( curr.first + a < row && curr.first + a > -1 && curr.second + b < column && curr.second + b > -1 && direction [ curr.first + a ][ curr.second + b ] > -1 )
                    {
                        if ( best [ curr.first + a ][ curr.second + b ] > best [ curr.first ][ curr.second ] + 1 )
                        {
                            best [ curr.first + a ][ curr.second + b ] = best [ curr.first ][ curr.second ] + 1;
                            q.push( make_pair ( curr.first + a, curr.second + b ) );
                        }
                    }
                }

            }
        }
    }
    if ( best [ row - 1 ][ column - 1 ] == INF ) best [ row - 1 ][ column - 1 ] = -2;
    return;
}

int main ()
{
    int test;
    cin >> test;
    char t;
    for ( int tr ( 0 ); tr < test; tr ++ )
    {
        cin >> row >> column;
        //cout << row << " " << column << endl;
        for ( int i ( 0 ); i < row; i ++ )
        {
            for ( int j ( 0 ); j < column; j ++ )
            {
                best [ i ][ j ] = INF;
                cin >> t;
                //cout << t << endl;
                if ( t == '*' ) direction [ i ][ j ] = -1;
                if ( t == '+' ) direction [ i ][ j ] = 2;
                if ( t == '-' ) direction [ i ][ j ] = 0;
                if ( t == '|' ) direction [ i ][ j ] = 1;
            }
        }
        best [ 0 ][ 0 ] = 0;
        bfs ( 0, 0 );
        cout << best [ row - 1 ][ column - 1 ] + 1 << endl;
    }


	return 0;
}
