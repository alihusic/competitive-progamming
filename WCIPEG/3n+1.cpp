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

int main ()
{
    int n;
    cin >> n;
    int num = 0;
    while ( true )
    {
        if ( n == 1 ) break;
        num ++;
        if ( n % 2 == 0 ) n /= 2;
        else
        {
            n*=3;
            n++;
        }
    }
    cout << num << endl;
	return 0;
}
