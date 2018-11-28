#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector <int> t;

unsigned long long inv ( unsigned long long a )
{
    unsigned long long fin = 0;
    t.clear();
    while ( a > 0 )
    {
        t.push_back ( a % 10 );
        a /= 10;
    }
    reverse ( t.begin(), t.end() );
    unsigned long long exp = 1;
    for ( int i = 0; i < t.size(); i ++ )
    {
        fin += t [ i ] * exp;
        exp *= 10;
    }
    return fin;
}

int main()
{
    int n;
    cin >> n;
    for ( int i = 0; i < n; i ++ )
    {
        unsigned long long a;
        unsigned long long b;
        cin >> a >> b;
        cout << inv ( inv( a ) + inv ( b ) ) << endl;
    }

    return 0;
}
