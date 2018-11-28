#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isC [ 200000 ];
vector<int>primes;

bool prime ( const int a )
{
    if ( a == 1 ) return false;
    if ( a == 2 ) return true;
    int limit = (int) sqrt(a)+1;
    int i = 0;
    while ( limit >= primes [ i ] )
    {
        if ( a % primes [ i ] == 0 ) return false;
        i++;
    }
    return true;
}



int main()
{
    primes.clear();
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for ( int i = 2; i < 100000; i ++ )
    {
        if ( isC [ i ] == false )
        {
            //cout << i << endl;
            //cout << i << endl;
            primes.push_back ( i );
            //cout << primes [ primes.size() - 1 ] << endl;
            for ( int j = i + i; j <= 100000; j += i )
            {
                isC [ j ] = true;
            }
        }
    }
    //cout << "D" << endl;
    for ( int i = n; i <= m; i ++ )
    {
        if ( prime ( i ) == true ) cout << i << endl;
    }
    return 0;
}
