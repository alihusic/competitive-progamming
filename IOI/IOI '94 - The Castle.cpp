/*
ID: ali.hus1
LANG: C++
PROB: castle
*/

#include<fstream>
#include<cstdio>
#include<queue>
#include<iostream>


using namespace std;

int compound [ 4 ] = { 8, 4, 2 ,1 };
int where [ 9 ] = { 0, 0, 1, 0, 2, 0, 0, 0, 3 };

struct tile
{
    bool wall [ 4 ];
    tile () {}
    int sizeroom;
    int id;
    tile ( int v )
    {
        sizeroom = 1;
        for ( int i ( 0 ); i < 4; i ++ ) wall [ i ] = false;
        for ( int i ( 0 ); i < 4; i ++ )
        {
            if ( v >= compound [ i ] )
            {
                v -= compound [ i ];
                wall [ where [ compound [ i ] ] ] = true;
            }
        }
    }
};

int n, m;

tile field [ 51 ][ 51 ];
bool visited [ 51 ][ 51 ];
int numrooms = 0;
int biggestroom = 0;


queue <pair <int, int > > room;
int roomid;

int amove [ 4 ] = { 0, -1, 0, 1 };
int bmove [ 4 ] = { -1, 0, 1, 0 };
int roomsize;


void floodfill ( int x, int y )
{
    roomsize ++;
    int a, b;
    room.push ( make_pair ( x, y ) );
    visited [ x ][ y ] = 1;
    for ( int i ( 0 ); i < 4; i ++ )
    {
        //cout << i << endl;
        a = amove [ i ];
        b = bmove [ i ];
        if ( x + a < n && x + a > -1 && y + b < m && y + b > -1 )
        {
            //if ( x == 0 && y == 1 ) cout <<  field [ x ][ y ].wall [ i ] << " " << i << endl;
            if ( field [ x ][ y ].wall [ i ] == false  && visited [ x + a ][ y + b ] == false )
            {
                floodfill ( x + a, y + b );
            }
        }
    }
    return;
}



int main ()
{
    ifstream in;
    //in.open ( "castle.in" );
    cin >> m;
    cin >> n;
    int temp;
    for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < m; j ++ )
        {
            cin >> temp;
            //cout << temp << " ";
            field [ i ][ j ] = tile ( temp );
        }
        //cout << endl;
    }
    roomid = 0;
    for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < m; j ++ )
        {

            if ( visited [ i ][ j ] == false )
            {
                //cout << i + 1 << " " << j + 1 << endl;
                roomsize = 0;
                while ( room.empty() == false )
                {
                    room.pop ();
                }

                numrooms ++;
                floodfill ( i, j );
                int a, b;
                if ( roomsize > biggestroom ) biggestroom = roomsize;
                while ( room.empty () == false )
                {
                    //cout << room.front ().first + 1<< "," << room.front().second + 1 << "   ";
                    a = room.front().first;
                    b = room.front().second;
                    field [ a ][ b ].sizeroom = roomsize;
                    field [ a ][ b ].id = roomid;
                    room.pop();
                }
                roomid ++;
                //cout << endl;
                //postaviti room
            }
        }
    }

    /*for ( int i ( 0 ); i < n; i ++ )
    {
        for ( int j ( 0 ); j < m; j ++ )
        {
            cout << field [ i ][ j ].sizeroom << " ";
        }
        cout << endl;
    }*/

    pair < int, int > critical;
    char critical_side;
    int critical_sum = 0;
    for ( int j ( 0 ); j < m; j ++ )
    {
        for ( int i ( n - 1 ); i > -1; i -- )
        {
            if ( i - 1 > -1 && field [ i ][ j ].wall [ 1 ] == true )
            {
                if ( critical_sum < field [ i ][ j ].sizeroom + field [ i - 1 ][ j ].sizeroom && field [ i ][ j ].id != field [ i - 1 ][ j ].id )
                {
                    critical_sum = field [ i ][ j ].sizeroom + field [ i - 1 ][ j ].sizeroom;
                    critical_side = 'N';
                    critical.first = i;
                    critical.second = j;
                }
            }
            if ( j + 1 < m && field [ i ][ j ].wall [ 2 ] == true )
            {
                if ( critical_sum < field [ i ][ j ].sizeroom + field [ i ][ j + 1 ].sizeroom && field [ i ][ j ].id != field [ i ][ j + 1 ].id )
                {
                    critical_sum = field [ i ][ j ].sizeroom + field [ i ][ j + 1 ].sizeroom;
                    critical_side = 'E';
                    critical.first = i;
                    critical.second = j;
                }
            }
        }
    }
    //ofstream out;
    //cout.open ( "castle.out" );
    cout << numrooms << endl;
    cout << biggestroom << endl;
    cout << critical_sum << endl;
    cout << critical.first + 1 << " " << critical.second + 1 << " " << critical_side << endl;
    //cout << field [ n - 1 ][ m - 1 ].wall [ 1 ] << endl;
    return 0;
}
