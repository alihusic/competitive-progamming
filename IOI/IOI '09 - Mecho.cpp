#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<utility>
#include<queue>

using namespace std;

#define mp make_pair
#define pb push_back
#define	xx first
#define yy second

const int INF = 1 << 29;
typedef long long lint;
typedef pair < int, int > tacka;

int ma [ 4 ] = { 0, 0, 1, -1 };
int mb [ 4 ] = { 1, -1, 0, 0 };

bool reach [ 810 ][ 810 ];
int bear [ 810 ][ 810 ];
int bees [ 810 ][ 810 ];
tacka mecho;
tacka home;
int n, steps;
vector <tacka> bstart;

bool check( int level )
{
    for ( int i = 0; i < n; i ++ )
    {
        for ( int j = 0; j < n; j ++ )
        {
            bear [ i ][ j ] = INF;
        }
    }
    reach [ home.xx ][ home.yy ] = true;
    bear [ mecho.xx ][ mecho.yy ] = 0;
    if ( bees [ mecho.xx ][ mecho.yy ] <= level ) return false;
    queue <tacka> q;
    tacka curr;
    while ( !q.empty() ) q.pop();
    q.push ( mp(mecho.xx, mecho.yy));
    //sabiramo sa +level
    int a, b;
    while ( !q.empty() )
    {
        curr = q.front();
        q.pop();
        if ( curr == home ) return true;

        for ( int i = 0; i < 4; i ++ )
        {
            a = ma [ i ];
            b = mb [ i ];
            if ( curr.xx + a >= 0 && curr.xx + a < n && curr.yy + b >= 0 && curr.yy + b < n && reach [ curr.xx + a ][ curr.yy + b ])
            {
                if ( bear [ curr.xx + a ][ curr.yy + b ] > bear [ curr.xx ][ curr.yy ] + 1 )
                {
                    if ( ( ( bear [ curr.xx ][ curr.yy ]+ 1 )/steps ) + level < bees [ curr.xx + a ][ curr.yy + b ] )
                    {
                        bear [ curr.xx + a ][ curr.yy + b ] = bear [ curr.xx ][ curr.yy ] + 1;
                        q.push(mp(curr.xx+a,curr.yy+b));
                    }
                }
            }
        }
    }
    return false;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> steps;
    char t;
    for ( int i = 0; i < n; i ++ )
    {
        for ( int j = 0; j < n; j ++ )
        {
            reach [ i ][ j ] = false;
            bear [ i ][ j ] = INF;
            bees [ i ][ j ] = INF;
            cin >> t;
            if ( t == 'M' )
            {
                reach [ i ][ j ] = true;
                mecho = mp ( i, j );
            }
            if ( t == 'H' )
            {
                bstart.pb(mp(i,j));
            }
            if ( t == 'D' )
            {
                home = mp(i,j);
            }
            if ( t == 'T' )
            {

            }
            if ( t == 'G' )
            {
                reach [ i ][ j ] = true;
            }
        }
    }
    queue <tacka> q;
    while ( !q.empty() ) q.pop();
    for ( int i = 0; i < bstart.size(); i ++ )
    {
        bees [ bstart [ i ].first ][ bstart [ i ].second ] = 0;
        q.push(bstart [ i ] );
    }
    tacka bcurr;
    while ( !q.empty() )
    {
        bcurr = q.front();
        q.pop();
        int a, b;
        for ( int i = 0; i < 4; i ++ )
        {
            a = ma [ i ];
            b = mb [ i ];
            if ( bcurr.first + a >= 0 && bcurr.first + a < n && bcurr.second + b >= 0 && bcurr.second + b < n  && reach [ bcurr.first + a ][ bcurr.second + b ])
            {
                if ( bees [ bcurr.first + a ][ bcurr.second + b ] > bees [ bcurr.first ][ bcurr.second ] + 1 )
                {
                    bees [ bcurr.first + a ][ bcurr.second + b ] = bees [ bcurr.first ][ bcurr.second ] + 1;
                    q.push ( mp ( bcurr.first + a, bcurr.second + b) );
                }
            }
        }
    }
    /*for ( int i = 0; i < n; i ++ )
    {
        for ( int j = 0; j < n; j ++ )
        {
            cout << bees [ i ][ j ] << " ";
        }
        cout << endl;
    }*/
    /*or ( int i = 10; i > -2; i -- )
    {
        cout << check ( i ) << " " << i << endl;
    }*/
    int low = -2;
    int high = n*n;
    high ++;
    int best = -1;
    int mid;
    bool feed;
    while ( low < high )
    {
        if ( high - low < 4 )
        {
            for ( int i = high; i >= low; i -- )
            {
                if ( check ( i ) )
                {
                    if ( i > best )
                    {
                        best = i;
                        break;
                    }
                }
            }
        }
        mid = ( low + high ) / 2;
        feed = check ( mid );
        if ( feed )
        {
            low = mid + 1;
            best = max ( mid, best );
        }
        else
        {
            high = mid - 1;
        }

    }
    cout << best << endl;
	return 0;
}
