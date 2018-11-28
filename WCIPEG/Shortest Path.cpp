#include<iostream>
#include<vector>

using namespace std;

int n;
int m;
vector < pair < int, int > > cost [ 1010 ];
int best [ 1010 ];
const int inf = 1 << 29;
vector < int > path;
vector < int > current_path;

void dijkstra ( const int node )
{
    if ( node == n )
    {
        path.clear();
        for ( int i ( 0 ); i < current_path.size(); i ++ ) path.push_back ( current_path [ i ] );
        return;
    }
    for ( int i ( 0 ); i < cost [ node ].size(); i ++ )
    {
        if ( best [ cost [ node ][ i ].first ] > best [ node ] + cost [ node ][ i ].second )
        {
            best [ cost [ node ][ i ].first ] = best [ node ] + cost [ node ][ i ].second;
            current_path.push_back ( cost [ node ][ i ].first );
            dijkstra ( cost [ node ][ i ].first );
            current_path.pop_back ();
        }
    }
}

int main()
{
    cin >> n;
    cin >> m;
    int a, b, c;
    for ( int i ( 1 ); i <= m; i ++ )
    {
        cin >> a >> b >> c;
        cost [ a ].push_back ( make_pair ( b, c ) );
    }
    for ( int i ( 0 ); i <= n; i ++ ) best [ i ] = inf;
    best [ 1 ] = 0;
    current_path.push_back ( 1 );
    dijkstra ( 1 );

    cout << best [ n ] << endl;
    //cout << endl;
    //cout << "Take the path ";
    //cout << path [ 0 ];
    //for ( int i ( 1 ); i < path.size(); i ++ ) cout << "-" << path [ i ];
    //cout << "." << endl;
    return 0;
}
