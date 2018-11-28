#include<iostream>


using namespace std;

long long r, l, b;
long long cumulative [ 100020 ];
long long rfield [ 100020 ];

long long best = 0;

long long check ( const int first, const int last )
{
    if ( first == last ) return 0;
    int s = last - first + 1;
    long long sum = 0;
    if ( s%2==1 ) //NEPARAN BROJ
    {
        sum = sum + cumulative [ last ] - cumulative [ first + s/ 2 ] - cumulative [ first +s/2-1];
    }
    else
    {
        sum = cumulative [ last ];
        if ( first + s / 2 - 1 >= 0 )
        {
            sum -= 2 * cumulative [ first + s/2 - 1 ];
        }
    }
    if ( first > 0 ) sum += cumulative [ first - 1 ];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> r >> l >> b;
    for ( int i = 0; i < r; i ++ )
    {
        cin >> rfield [ i ];
    }
    cumulative [ 0 ] = rfield [ 0 ];
    for ( int i = 1; i < r; i ++ )
    {
        cumulative [ i ] = cumulative [ i - 1 ] + rfield [ i ];
    }
    int first = 0;
    int last = 0;
    while ( true )
    {
        if ( last >= r ) break;
        if ( check ( first, last ) <= b )
        {
            if ( last - first + 1 > best ) best = last - first +1;
            last ++;
        }
        else
        {
            first ++;
        }
    }
    cout << best << endl;
    return 0;
}
