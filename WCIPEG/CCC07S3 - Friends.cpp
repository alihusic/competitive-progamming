#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<queue>
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
int biggest;

int fr [ 10100 ];
int best [ 10100 ];

int bfs ( const int &start, const int &finish )
{
    for ( int i ( 0 ); i <= biggest; i ++ ) best [ i ] = INF;
    best [ start ] = 0;
    queue < int > q;
    int curr;
    q.push ( start );
    while ( !q.empty() )
    {
        curr = q.front();
        q.pop();
        if ( best [ fr [ curr ] ] > best [ curr ] + 1 )
        {
            best [ fr [ curr ] ] = best [ curr ] + 1;
            q.push ( fr [ curr ] );
        }
    }
    return best [ finish ] - 1;
}

int main ()
{
    int n;
    cin >> n;
    int a, b;
    biggest = 0;
    for ( int i ( 0 ); i < n; i ++ )
    {
        cin >> a >> b;
        biggest = max ( biggest, a );
        biggest = max ( biggest, b );
        fr [ a ] = b;
    }
    while ( true )
    {
        cin >> a >> b;
        if ( a == 0 && b == 0 ) break;
        int r = bfs ( a, b );
        if ( r == INF - 1 )
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes " << r << endl;
        }
    }
	return 0;
}
