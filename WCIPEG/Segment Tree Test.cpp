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

using namespace std;

#define mp make_pair
#define pb push_back
#define	xx first
#define yy second

const int INF = 1 << 29;
typedef long long lint;
typedef pair < int, int > tacka;
 #define endl '\n'



int start [ 100020 ];

struct node
{
    int left;
    int right;
    int best;
    node()
    {
        left = -INF;
        right = -INF;
        best = INF;
    }
};

node segtree [ 1000000 ];

int make ( const int &left, const int &right, int index )
{
    segtree [ index ].left = left;
    segtree [ index ].right = right;
    if ( left + 1 == right )
    {
        segtree [ index ].best = start [ left ];
        return segtree [ index ].best;
    }
    segtree [ index ].best = min ( make ( left, ( left + right )/2, (index*2)+1), make ( (left +right)/2, right, (index * 2) + 2 ) );
    return segtree [ index ].best;
}

int calls = 0;

int query ( const int &left, const int &right, const int &index )
{
    calls ++;
    if ( right == segtree [ index ].right && left == segtree [ index ].left ) return segtree [ index ].best;
    int mid = ( segtree [ index ].left + segtree [ index ].right )/2;
    if ( segtree[index].left + 1 == segtree[index].right ) return segtree [ index ].best;
    if ( right <= mid )
    {
        return query ( max ( left, segtree [ index ].left ), right, (index*2)+1);
    }
    if ( left >= mid )
    {
        return query ( left, min ( right, segtree [ index ].right ), ( index * 2 )+2);
    }
    return min ( query( max ( left, segtree [ index ].left ),mid,(index*2)+1),query(mid, min ( right, segtree[index].right),(index*2)+2) );
}

void traverse ( const int index )
{
    cout << segtree [ index ]. left << " " << segtree [ index ].right << " " << segtree [ index ].best << endl;
    if ( segtree [ index ].left + 1 == segtree [ index ].right ) return;
    traverse ( ( index * 2 ) + 1);
    traverse ( ( index * 2 ) + 2);
}

void change ( const int &position, const int &newvalue, const int index )
{
    if ( segtree [ index ].left + 1 == segtree [ index ].right )
    {
        segtree [ index ].best = newvalue;
        return;
    }
    if ( position < (segtree [ index ].left + segtree [ index ].right )/2 )
    {
        change ( position , newvalue, ( index*2)+1);
    }
    else
    {
        change ( position, newvalue, ( index*2)+2);
    }
    segtree [ index ].best = min ( segtree [ ( index * 2) + 1 ].best, segtree [ ( index*2)+2].best);
}

int main ()
{
    std::ios::sync_with_stdio(false);
    //int a = make ( 0, 10, 0 );
    int n;
    int m;
    //scanf ( "%d", &n );
    //scanf ( "%d", &m);
    cin >> n >> m;
    //n = 500;
    for ( int i = 0; i < n; i ++ )
    {
        //scanf ( "%d", &start [ i ] );
        cin >> start [ i ];
        //start [ i ] = i + 1;
    }
    int a = make ( 0, n, 0 );
    char command;
    int f1, f2;
    //int ab = query(30, 470,0 );
    //cout << calls << endl;
    for ( int i = 0; i < m; i ++ )
    {
        //scanf ("%c", &command);
        //scanf ( "%d", &f1 );
        //scanf ( "%d", &f2 );
        cin >> command >> f1 >> f2;
        //cout << command << endl;
        if ( command == 'Q' ) cout << query(f1,f2+1, 0) << endl;//printf ( "%d\n", query(f1,f2+1,0));////printf ( "%d\n", query(f1,f2+1,0));
        else
        {
            change ( f1, f2, 0 );
        }
        //traverse ( 0 );
        //printf ( "%d\n", query(f1,f2+1,0));
    }
    //cout << a << endl;
    //cout << query ( 0,7, 0 ) << endl;
    //int start [ 10 ] = { 4, 5, 6, 10, 5, 3, 2, 1, 0, 0 };
///////////////////////////0  1  2   3  4  5  6  7   8   9
	//traverse ( 0 );
	return 0;
}
