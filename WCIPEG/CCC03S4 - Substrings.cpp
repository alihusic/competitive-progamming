
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int n;
string str;
vector < int > suffix;

bool condition ( int a, int b )
{
    while ( a < str.size () && b < str.size () )
    {
        if ( str [ a ] < str [ b ] ) return 1;
        if ( str [ a ] > str [ b ] ) return 0;
        a ++;
        b ++;
    }
    if ( a < b ) return 0;
    return 1;
}

int length ( const int &index )
{
    return str.size () - index;
}

int lcp ( int i1, int i2 )
{
    int common = 0;
    while ( i1 < str.size (), i2 < str.size () )
    {
        if ( str [ i1 ] != str [ i2 ] ) return common;
        common ++;
        i1 ++;
        i2 ++;
    }
    return common;
}

int main ()
{
    cin >> n;
    getline ( cin, str );
    for ( int i ( 0 ); i < n; i ++ )
    {
        vector < int > suffix;
        //suffix.clear ();
        getline ( cin, str );
        for ( int j ( 0 ); j < str.size (); j ++ )
        {
            suffix.push_back ( j );
        }
        sort ( suffix.begin (), suffix.end (), condition );
        /*for ( int j ( 0 ); j < suffix.size (); j ++ )
        {
            for ( int x ( suffix [ j ] ); x < str.size (); x ++ )
            {
                cout << str [ x ];
            }
            cout << endl;
        }*/
        int combs = 1;
        combs += str.size () - suffix [ 0 ];
        for ( int j ( 0 ); j < str.size () - 1; j ++ )
        {
            combs += str.size () - suffix [ j + 1 ] - lcp ( suffix [ j ], suffix [ j + 1 ] );
        }
        cout << combs << endl;
    }

    return 0;
}