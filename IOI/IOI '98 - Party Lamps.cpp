/*
ID: ali.hus1
LANG: C++
PROB: lamps
*/

#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>

using namespace std;

int res [ 200 ][ 200 ];

int off [ 200 ];
int soff, son;
int on [ 200 ];

int n, C;

void t1 ( int ( &r ) [ 102 ] )
{
    for ( int i = 0; i < n; i ++ )
    {
        if ( r [ i ] == 0 )
        {
            r [ i ] = 1;
        }
        else
        {
            r [ i ] = 0;
        }
    }
}
void t2 ( int ( &r ) [ 102 ] )
{
    for ( int i = 0; i < n; i += 2 )
    {
        if ( r [ i ] == 0 )
        {
            r [ i ] = 1;
        }
        else
        {
            r [ i ] = 0;
        }
    }
}
void t3 ( int ( &r ) [ 102 ] )
{
    for ( int i = 1; i < n; i += 2 )
    {
        if ( r [ i ] == 0 )
        {
            r [ i ] = 1;
        }
        else
        {
            r [ i ] = 0;
        }
    }
}
void t4 ( int ( &r ) [ 102 ] )
{
    for ( int i = 0; i < n; i += 3 )
    {
        if ( r [ i ] == 0 )
        {
            r [ i ] = 1;
        }
        else
        {
            r [ i ] = 0;
        }
    }
}

bool smaller ( const int ( &a ) [ 200 ], const int ( &b ) [ 200 ] )
{
    for ( int i = 0; i < n; i ++ )
    {
        if ( a [ i ] < b [ i ] ) return true;
        if ( a [ i ] > b [ i ] ) return false;
    }
    return true;
}

int tmp [ 200 ];

void eswap ( int ( &a ) [ 200 ], int ( &b ) [ 200 ] )
{
    for ( int i = 0; i < n; i ++ )
    {
        tmp [ i ] = a [ i ];
    }
    for ( int i = 0; i < n; i ++ )
    {
        a [ i ] = b [ i ];
    }
    for ( int i = 0; i < n; i ++ )
    {
        b [ i ] = tmp [ i ];
    }
}

int main ()
{
    son = 0;
    soff = 0;
    //ifstream in;
    //ofstream out;
    //in.open ( "lamps.in" );
    //out.open ( "lamps.out" );
    cin >> n;
    cin >> C;
    int temp;
    for ( int i = 0; ; i ++ )
    {
        cin >> temp;
        if ( temp == -1 )
        {
            break;
        }
        on [ i ] = temp;
        son ++;
    }
    for ( int i = 0; ; i ++ )
    {
        cin >> temp;
        if ( temp == -1 )
        {
            break;
        }
        off [ i ] = temp;
        soff ++;
    }
    int cnt = 0;

    for ( int a = 0; a < 2; a ++ )
    {
        for ( int b = 0; b < 2; b ++ )
        {
            for ( int c = 0; c < 2; c ++ )
            {
                for ( int d = 0; d < 2; d ++ )
                {
                    int tempstate [ 102 ];
                    for ( int i = 0; i < n; i ++ ) tempstate [ i ] = 1;
                    for ( int i = 0; i < a; i ++ ) t1 ( tempstate );
                    for ( int i = 0; i < b; i ++ ) t2 ( tempstate );
                    for ( int i = 0; i < c; i ++ ) t3 ( tempstate );
                    for ( int i = 0; i < d; i ++ ) t4 ( tempstate );
                    int flag = 0;
                    if ( a + b + c + d > C || ( C + a + b + c + d ) % 2 == 1 ) flag = 1;
                    for ( int i = 0; i < son; i ++ )
                    {
                        if ( tempstate [ on [ i ] - 1 ] == 0 ) flag = 1;
                    }
                    for ( int i = 0; i < soff; i ++ )
                    {
                        if ( tempstate [ off [ i ] - 1 ] == 1 ) flag = 1;
                    }
                    if ( flag == 0 )
                    {
                        for ( int i = 0; i < n; i ++ )
                        {
                            res [ cnt ][ i ] = tempstate [ i ];
                        }
                        cnt ++;
                    }
                }
            }
        }
    }
    if ( cnt == 0 )
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else
    {
        for ( int i = 0; i < cnt - 1; i ++ )
        {
            for ( int j = i + 1; j < cnt; j ++ )
            {
                if ( smaller ( res [ i ], res [ j ] ) == false )
                {
                    eswap ( res [ i ], res [ j ] );
                }
            }
        }
        for ( int i = 0; i < cnt; i ++ )
        {
            for ( int j = 0; j < n; j ++ )
            {
                cout << res [ i ][ j ];
            }
            cout << endl;
        }
    }

    return 0;
}
