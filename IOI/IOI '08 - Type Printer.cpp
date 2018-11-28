#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n;

struct node
{
    int child [ 26 ];
    bool isEnd;
    char val;
    int toEnterlast;
    node()
    {
        for ( int i = 0; i < 26; i ++ ) child [ i ] = -1;
        isEnd = false;
        toEnterlast = -1;
    }
    node ( const char &a )
    {
        for ( int i = 0; i < 26; i ++ ) child [ i ] = -1;
        val = a;
        toEnterlast = -1;
        isEnd = false;
    }
};

node trie [ 500000 ];
int nextindex = 0;
int moves = 0;

void insert( const string &a )
{
    //cout << a << endl;
    int curr = 0;
    for ( int i = 0; i < a.size(); i ++ )
    {
        //cout << i << " " << curr << endl;
        if ( trie [ curr ].child [ a [ i ] - 'a' ] == -1 )
        {
            trie [ curr ].child [ a [ i ] - 'a' ] = nextindex;
            trie [ nextindex ] = node ( a [ i ] );
            nextindex ++;
        }
        curr = trie [ curr ].child [ a [ i ] - 'a' ];
        //cout << i << " " << curr << " " << nextindex << endl;
    }
    trie [ curr ].isEnd = true;
    /*
    int curr = 0;
    for ( int i = 0; i < a.size(); i ++ )
    {

        if ( trie [ par ].child [ a [ i ] - 'a' ] == -1 )
        {
            trie [ par ].child [ a [ i ] - 'a' ] = nextindex;
            trie [ nextindex ] = node ( a [ i ] );
            nextindex ++;
            //cout << par << endl;
        }
            par = trie [ par ].child [ a [ i ] - 'a' ];
            cout << i << " " << par << endl;
    }
    cout <<"SURVIVED"<< endl;
    trie [ par ].isEnd = true;*/
}

string ispis = "";


void flagit ( const string &a )
{
    int par = 0;
    for ( int i = 0; i < a.size(); i ++ )
    {
        trie [ par ].toEnterlast = a [ i ] - 'a';
        par = trie [ par ].child [ a [ i ] - 'a' ];
    }
}

/*void print ( int index, const bool islast )
{
    moves ++;
    //cout << "POZIV" << endl;
    //cout << index << endl;
    //cout << index << endl;
    if ( index != 0 ) cout << trie [ index ].val << endl;
    if ( trie [ index ].isEnd == true ) { moves ++; cout << "P" << endl;}
    for ( int i = 0; i < 26; i ++ )
    {
        if ( i != trie [ index ].toEnterlast && trie [ index ].child [ i ] != -1 )
        {
            //if ( index > trie [ index ].child [ i ] ) cout << "SHIT" << endl;
            print ( trie [ index ].child [ i ], 0 );
        }
    }
    //cout << "CRASHED AFTER" << endl;
    if (trie [index].toEnterlast!=-1 && trie[ index ].child [ trie [index].toEnterlast ] != -1 ) print ( trie [ index ].child [ trie [index].toEnterlast ], 1 );
    if ( islast == false && index != 0 ) { moves ++; cout << "-" << endl; }

}*/

void eprint ( int index, const bool islast )
{
    moves ++;
    //cout << "POZIV" << endl;
    //cout << index << endl;
    //cout << index << endl;

    if ( index != 0 ) ispis.push_back(trie[ index ].val);
    if ( trie [ index ].isEnd == true ) { moves ++;ispis.push_back('P');}
    for ( int i = 0; i < 26; i ++ )
    {
        if ( i != trie [ index ].toEnterlast && trie [ index ].child [ i ] != -1 )
        {
            //if ( index > trie [ index ].child [ i ] ) cout << "SHIT" << endl;
            eprint ( trie [ index ].child [ i ], 0 );
        }
    }
    //cout << "CRASHED AFTER" << endl;
    if (trie [index].toEnterlast!=-1 && trie[ index ].child [ trie [index].toEnterlast ] != -1 ) eprint ( trie [ index ].child [ trie [index].toEnterlast ], 1 );
    if ( islast == false && index != 0 ) { ispis.push_back ('-');moves ++;}

}


int main()
{
    cin >> n;
    string t;
    string longest = "";
    trie [ 0 ].val = '*';
    nextindex ++;
    for ( int i = 0; i < n; i ++ )
    {
        cin >> t;
        if ( t.size() > longest.size() ) longest = t;
        insert( t );
    }
    //cout << "START" << endl;
    flagit ( longest );
    //cout << "END" << endl;
    eprint ( 0, 0 );
    cout << moves - 1<< '\n';
    for ( int i = 0; i < ispis.size(); i ++ ) cout << ispis [ i ] << '\n';
    //print ( 0, 0 );
    //
    return 0;
}
