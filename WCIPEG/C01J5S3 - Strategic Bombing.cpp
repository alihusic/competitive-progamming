#include<iostream>
#include<vector>
#include<string>
#include<set>

using namespace std;

//vector < int > g [ 30 ];
bool c [ 26 ][ 26 ];
bool vis [ 26 ];

bool dfs ( const int curr )
{
    vis [ curr ] = true;
    //cout << curr << endl;
    if ( curr == 1 )
    {
        //cout << "EVO GA" << endl;
        return true;
    }
    bool found = false;
    bool tmp = false;
    for ( int i ( 0 ); i < 26; i ++ )
    {
        if ( c [ curr ][ i ] == true && i != curr && vis [ i ] == false )
        {
            //cout << "Ulazim u " << char ( i + 'A' ) << endl;
            tmp = dfs ( i );
            if ( tmp == true ) found = true;
        }
    }
    return found;
}

set < pair < int, int > > sols;

int main()
{
    string a;
    //vector < pair < char, char > > inp;
    vector < pair < char, char > > inp;
    while ( true )
    {
        cin >> a;
        if ( a == "**" ) break;
        c [ a [ 0 ] - 'A' ][ a [ 1 ] - 'A' ] = true;
        c [ a [ 1 ] - 'A' ][ a [ 0 ] - 'A' ] = true;
        //g [ a [ 0 ] - 'A' ].push_back ( a [ 1 ] - 'A' );
        inp.push_back ( make_pair ( a [ 0 ], a [ 1 ] ) );
    }

    for ( int i ( 0 ); i < 26; i ++ )
    {
        for ( int j ( 0 ); j < 26; j ++ )
        {
            if ( c [ i ][ j ] == true && i != j )
            {
                for ( int k ( 0 ); k < 26; k ++ ) vis [ k ] = false;
                c [ i ][ j ] = false;
                if ( dfs ( 0 ) == false )
                {
                    sols.insert ( make_pair ( char ( i + 'A'), char ( j + 'A') ) );
                    sols.insert ( make_pair ( char ( j + 'A'), char ( i + 'A') ) );
                }
                c [ i ][ j ] = true;
            }
        }
    }
    int f = 0;
    for ( int i ( 0 ); i < inp.size(); i ++ )
    {
        if ( sols.count ( inp [ i ] ) > 0 ) { cout << inp [ i ].first << inp [ i ].second << endl; f ++; }
    }
    cout << "There are "<< f <<" disconnecting roads." << endl;
    return 0;
}
