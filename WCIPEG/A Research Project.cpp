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

int g;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> g;
    int n;
    int t;
    int worst;
    int best;
    for ( int x = 0; x < g; x ++ )
    {
        worst = INF;
        best = -INF;
        cin >> n;
        for ( int i = 0; i < n; i ++ )
        {
            cin >> t;
            worst = min ( worst, t );
            best = max ( best, t );
        }
        cout << worst << " " << best << endl;
    }


	return 0;
}
