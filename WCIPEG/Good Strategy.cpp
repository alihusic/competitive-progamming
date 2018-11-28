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
int n, m;

int helper [ 1000020 ];
bool solved [ 1000020 ];
bool numsolved = 0;

/*template <int, int>
  bool operator<  (const pair<int,int>& lhs, const pair<int,int>& rhs)
{ return lhs.first>rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }
*/

bool compare ( const tacka &a, const tacka &b )
{
    if ( a.first == b.first )
    {
        return a.second >b.second;
    }
    return a.first < b.second;
}

struct classcomp {
  bool operator() (const tacka &lhs, const tacka &rhs) const
  {
        if ( lhs.first == rhs.first )
        {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
  }
};


set < tacka, classcomp > all;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for ( int i = 1; i <= n; i ++ )
    {
        helper [ i ] = 0;
        all.insert ( make_pair ( 0, i ) );
    }
    int a, b;
    for ( int i = 0; i < m; i ++ )
    {
        //cout << numsolved << endl;
        cin >> a >> b;
        if ( all.empty() == false )
        {
            if ( a == 1 )
            {
                if ( solved [ b ] == false )
                {
                    numsolved ++;
                    solved [ b ] ++;
                    set<tacka>::iterator it = all.find( make_pair ( helper [ b ], b) );
                    all.erase ( it );
                }

            }
            else
            {
                    if ( solved [ b ] == false )
                    {
                        set <tacka>::iterator it = all.find(make_pair (helper [ b ], b) );
                        all.erase ( it );
                        helper [ b ] ++;
                        all.insert ( make_pair ( helper [ b ], b ) );
                    }

            }
        }

        if ( numsolved == n || all.empty())
        {
            cout << "Make noise" << endl;
        }
        else
        {
            set<tacka>::iterator it = all.end();
            /*for ( it = all.begin(); it != all.end(); it ++ )
            {
                /*if ( solved [ (*it).second ] == false )
                {
                    cout << (*it).second << " ";
                    break;
                }*/
                //cout << ( *it ).first << "," << ( *it ).second << " ";
            //}
            //cout << endl;
            it --;
            cout << ( *it ).second << " ";
            it = all.begin();
            cout << ( *it ).second << endl;
            //cout << (*it).second << " ";
            /*for ( it = all.end(); it != all.begin(); it -- )
            {
                if ( solved [ (*it).second ] == false )
                {
                    cout << (*it).second << endl;
                    break;
                }
            }*/
        }
    }
	return 0;
}
