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
vector <int> primes;
bool prek [ 3000 ];


bool isPrime(const int x)
{
    int i = 0;
    if ( x == 2 ) return true;
    while ( primes [ i ] <= sqrt(x)+1 )
    {
        if ( x%primes [ i ] == 0 ) return false;
        i ++;
    }
    return true;
}

bool isPalind( int x)
{
    string a, b;
    a = "";
    while ( x > 0 )
    {
        a.pb(char((x%10) + '0' ) );
        x /= 10;
    }
    b = a;
    reverse ( b.begin(), b.end() );
    return a == b;
}

int main ()
{
    for ( int i = 2; i < 3000; i ++ )
    {
        if ( prek [ i ] == false )
        {
            primes.pb(i);
            for ( int j = i + i; j < 3000; j += i )
            {
                prek [ j ] = true;
            }
        }
    }
    int a, b;
    int cnt;
    for ( int i = 0; i < 5; i ++ )
    {
        cnt = 0;
        cin >> a >> b;
        for ( int x = a; x <= b; x ++ )
        {
            if ( isPrime ( x ) )
            {
                if ( isPalind ( x ) )
                {
                    cnt ++;
                }
            }
        }
        cout << cnt << endl;
    }
	return 0;
}
