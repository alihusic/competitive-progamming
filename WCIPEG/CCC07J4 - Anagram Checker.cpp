#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main ()
{
    string a, b;
    vector <char> p, q;
    getline ( cin, a );
    getline ( cin, b );
    for ( int i ( 0 ); i < a.size(); i ++ )
    {
        if ( a [ i ] != ' ' ) p.push_back ( a [ i ] );
    }
    for ( int i ( 0 ); i < b.size(); i ++ )
    {
        if ( b [ i ] != ' ' ) q.push_back ( b [ i ] );
    }
    sort ( p.begin(), p.end() );
    sort ( q.begin(), q.end() );
    if ( p.size() != q.size() )
    {
        cout << "Is not an anagram." << endl;
        return 0;
    }
    else
    {
        bool wrong = false;
        for ( int i ( 0 ); i < p.size(); i ++ )
        {
            if ( p [ i ] != q [ i ] ) wrong = true;
        }
        if ( wrong == true )
        {
            cout << "Is not an anagram." << endl;
        }
        else
        {
            cout << "Is an anagram." << endl;
        }
    }
    return 0;
}
