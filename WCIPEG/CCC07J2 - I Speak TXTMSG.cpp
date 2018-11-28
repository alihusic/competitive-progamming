#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<fstream>
#include<utility>

using namespace std;

#define mp make_pair
#define pb push_back
#define	xx first
#define yy second

const int INF = 1 << 29;
typedef long long lint;
typedef pair < int, int > tacka;

string e [ 12 ] = { "CU", ":-)", ":-(", ";-)", ":-P", "(~.~)", "TA", "CCC", "CUZ", "TY", "YW", "TTYL" };
string t [ 12 ] = { "see you", "I'm happy", "I'm unhappy", "wink", "stick out my tongue", "sleepy", "totally awesome", "Canadian Computing Competition", "because",
 "thank-you", "you're welcome", "talk to you later" };

int findindex ( const string &a )
{
    int f = -1;
    for ( int i ( 0 ); i < 12; i ++ ) if ( e [ i ] == a ) return i;
    return f;
}

int main ()
{
    string tmp;
    while ( true )
    {
        cin >> tmp;
        if ( tmp == "TTYL" )
        {
            cout << "talk to you later" << endl;
            break;
        }
        int er = findindex ( tmp );
        if ( er == -1 )
        {
            cout << tmp << endl;
        }
        else
        {
            cout << t [ er ] << endl;
        }
    }
	return 0;
}
