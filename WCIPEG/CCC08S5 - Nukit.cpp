#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int dp [ 31 ][ 31 ][ 31 ][ 31 ];

bool ma ( const int &a, const int &b, const int &c, const int &d )
{
    return ( a >= 2 && b >= 1 && d >= 2 );
}

bool mb ( const int &a, const int &b, const int &c, const int &d )
{
    return ( a >= 1 && b >= 1 && c >= 1 && d >= 1 );
}

bool mc ( const int &a, const int &b, const int &c, const int &d )
{
    return ( c >=2 && d >= 1 );
}

bool md ( const int &a, const int &b, const int &c, const int &d )
{
    return ( b >= 3 );
}

bool me ( const int &a, const int &b, const int &c, const int &d )
{
    return ( a >= 1 && d >= 1 );
}

bool winning ( int a, int b, int c, int d )
{
    if ( dp [ a ][ b ][ c ][ d ] != 0 )
    {
        return dp [ a ][ b ][ c ][ d ] > 0;
    }
    if ( ma ( a, b, c, d ) == false && mb ( a, b, c, d ) == false && mc ( a, b, c, d ) == false && md ( a, b, c, d ) == false && me ( a, b, c, d ) == false )
    {
        dp [ a ][ b ][ c ][ d ] = -1;
        return false;
    }
    if ( ma ( a, b, c, d ) == true && winning ( a - 2, b - 1, c, d - 2) == false )
    {  dp [ a ][ b ][ c ][ d ] = 1; return true;}
    if ( mb ( a, b, c, d ) == true && winning ( a - 1, b - 1, c - 1, d - 1 ) == false )
        {  dp [ a ][ b ][ c ][ d ] = 1; return true;}
    if ( mc ( a, b, c, d ) == true && winning ( a, b, c - 2, d - 1 ) == false )
    {  dp [ a ][ b ][ c ][ d ] = 1; return true;}
    if ( md ( a, b, c, d ) == true && winning ( a, b - 3, c, d ) == false )
    {  dp [ a ][ b ][ c ][ d ] = 1; return true;}
    if ( me ( a, b, c, d ) == true && winning ( a - 1, b, c, d - 1 ) == false )
    {  dp [ a ][ b ][ c ][ d ] = 1; return true;}


    return false;
}

int main()
{
    int t;
    int a,b,c,d;
    cin >> t;
    for ( int test ( 0 ); test < t; test ++ )
    {
        cin >> a >> b >> c >> d;
        if ( winning ( a, b, c, d ) == true )
        {
            cout << "Patrick" << endl;
        }
        else
        {
            cout << "Roland" << endl;
        }
    }

    return 0;
}
