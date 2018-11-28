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
int n,t;


int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    string temp1,temp2;
    for ( int x = 0; x < t; x ++ )
    {
        cin >> n;
        cin >> temp1 >> temp2;
        for ( int i = n - 1; i >= 0; i -- )
        {
            cout << temp2 [ i ] << temp1[ i ];
        }
        cout << endl;
    }
	return 0;
}
