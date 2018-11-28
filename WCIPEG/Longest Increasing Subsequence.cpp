#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<stack>
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

int n;


int main ()
{
    cin >> n;
    vector < int > all;
    vector < int > current;
    int t;
    for ( int i ( 0 ); i < n; i ++ )
    {
        cin >> t;
        all.push_back ( t );
    }
    std::vector<int>::iterator up;
    for ( int i ( 0 ); i < n; i ++ )
    {
        if ( current.size() == 0 || current [ current.size() - 1 ] < all [ i ] ) current.push_back ( all [ i ] );
        else current [ lower_bound ( current.begin(), current.end(), all [ i ] ) - current.begin() ] = all [ i ];
    }
    cout << current.size() << endl;
	return 0;
}
