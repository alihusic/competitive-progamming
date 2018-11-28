#include<string>
#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class bignum
{
    public:
        vector < int > cipher;
        bignum () {}
        bignum ( const string &arg )
        {
            for ( int i ( 0 ); i < arg.size(); i ++ )
            {
                cipher.push_back ( arg [ i ] - '0' );
            }
        }
        bignum ( int a )
        {
            while ( true )
            {
                if ( a < 10 )
                {
                    cipher.push_back ( a );
                    break;
                }
                cipher.push_back ( a % 10 );
                a /= 10;
            }
            reverse ( cipher.begin(), cipher.end() );
        }
        bignum operator + ( const bignum &alternative )
        {
            bignum result;
            bignum replica = alternative;
            for ( int i ( 0 ); i < cipher.size(); i ++ ) result.cipher.push_back ( cipher [ i ] );
            reverse ( result.cipher.begin(), result.cipher.end() );
            reverse ( replica.cipher.begin(), replica.cipher.end() );

            int len = max ( result.cipher.size(), replica.cipher.size() );
            for ( int i ( result.cipher.size() ); i < len; i ++ ) result.cipher.push_back ( 0 );
            for ( int i ( replica.cipher.size() ); i < len; i ++ ) replica.cipher.push_back ( 0 );

            int carry = 0;
            for ( int i ( 0 ); i < len; i ++ )
            {
                result.cipher [ i ] += replica.cipher [ i ] + carry;
                carry = result.cipher [ i ] / 10;
                result.cipher [ i ] %= 10;
            }
            if ( carry > 0 )
            {
                result.cipher.push_back ( carry );
            }
            reverse ( result.cipher.begin(), result.cipher.end() );
            return result;
        }

        bignum operator * ( const bignum &alternative )
        {
            bignum result ( "0" );
            bignum row ( "0" );
            int zeros ( 0 );
            int transfer;
            for ( int i ( alternative.cipher.size() - 1 ); i > -1; i -- )
            {
                row.clear();
                transfer = 0;
                for ( int k ( 0 ); k < zeros; k ++ ) row.cipher.push_back ( 0 );
                for ( int j ( cipher.size() - 1 ); j > -1; j -- )
                {
                    row.cipher.push_back ( ( alternative.cipher [ i ] * cipher [ j ] ) + transfer );
                    transfer = row.cipher [ row.cipher.size() - 1 ] / 10;
                    row.cipher [ row.cipher.size() - 1 ] %= 10;
                }
                if ( transfer > 0 ) row.cipher.push_back ( transfer );
                reverse ( row.cipher.begin(), row.cipher.end() );
                result = result + row;
                zeros ++;
            }
            if ( result.cipher [ 0 ] == 0 )
            {
                reverse ( result.cipher.begin(), result.cipher.end() );
                while ( true )
                {
                    if ( result.cipher [ result.cipher.size() - 1 ] != 0 || result.cipher.size() == 1 ) break;
                    result.cipher.pop_back();
                }
                reverse ( result.cipher.begin(), result.cipher.end() );
            }
            return result;
        }
        bignum operator - ( const bignum &as )
        {
            bignum rs;
            bignum a ( as );
            rs.clear();
            for ( int i ( 0 ); i < cipher.size(); i ++ ) rs.cipher.push_back ( cipher [ i ] );
            reverse ( a.cipher.begin(), a.cipher.end() );
            reverse ( rs.cipher.begin(), rs.cipher.end() );
            for ( int i ( 0 ); i < a.cipher.size(); i ++ )
            {
                //cout << rs.cipher [ i ] << " " << a.cipher [ i ] << endl;
                if ( rs.cipher [ i ] < a.cipher [ i ] )
                {
                    rs.cipher [ i + 1 ] --;
                    rs.cipher [ i ] += 10;
                    rs.cipher [ i ] -= a.cipher [ i ];
                }
                else
                {
                    rs.cipher [ i ] -= a.cipher [ i ];
                }
            }
            //eliminisati ostatak
            //int i = a.cipher.size() - 1;
            for ( int i ( a.cipher.size() - 1 ); i < cipher.size() - 1; i ++ )
            {
                if ( rs.cipher [ i ] == -1 )
                {
                    rs.cipher [ i ] += 10;
                    rs.cipher [ i + 1 ] --;
                }
            }

            while ( true )
            {
                if ( rs.cipher [ rs.cipher.size() - 1 ] != 0 ) break;
                rs.cipher.pop_back();
            }
            //obrisati nule
            reverse ( rs.cipher.begin(), rs.cipher.end() );
            //okrenuti
            return rs;
        }
        bignum operator / ( const bignum &a )
        {

        }
        void print ()
        {
            for ( int i ( 0 ); i < cipher.size(); i ++ )
            {
                cout << cipher [ i ];
            }
            cout << endl;
        }
        void clear ()
        {
            cipher.clear();
        }
        bool operator < ( const bignum &a ) const
        {
            if ( cipher.size () > a.cipher.size() ) return false;
            if ( cipher.size () < a.cipher.size() ) return true;
            for ( int i ( 0 ); i < cipher.size(); i ++ )
            {
                if ( cipher [ i ] < a.cipher [ i ] ) return true;
                if ( cipher [ i ] > a.cipher [ i ] ) return false;
            }
        }
};

int main()
{
    string a;
    string b;
    string aa2;
    string bb2;
    cin >> a;
    cin >> b;
    aa2.clear();
    bb2.clear();
    bool aneg = false;
    bool bneg = false;
    if ( a [ 0 ] == '-' )
    {
        aneg = true;
        for ( int i ( 1 ); i < a.size(); i ++ )
        {
            aa2.push_back ( a [ i ] );
        }
    }
    else
    {
        aa2 = a;
    }
    if ( b [ 0 ] == '-' )
    {
        bneg = true;
        for ( int i ( 1 ); i < b.size(); i ++ )
        {
            bb2.push_back ( b [ i ] );
        }
    }
    else
    {
        bb2 = b;
    }
    bignum a2 ( aa2 );
    bignum b2 ( bb2 );
    if ( aneg == false && bneg == false )
    {
        bignum c = a2 + b2;
        c.print();
        return 0;
    }
    if ( aneg == true && bneg == true )
    {
        bignum c = a2 + b2;
        cout << "-";
        c.print();
        return 0;
    }
    if ( aa2 == bb2 )
    {
        cout << "0" << endl;
        return 0;
    }
    if ( aneg == true && bneg == false )
    {
        if ( a2 < b2 )
        {
            bignum c = b2 - a2;
            c.print();
            return 0;
        }
        else
        {
            bignum c = a2 - b2;
            cout << "-";
            c.print();
            return 0;
        }
    }
    else
    {
        if ( b2 < a2 )
        {
            bignum c = a2 - b2;
            c.print();
            return 0;
        }
        else
        {
            bignum c = b2 - a2;
            cout << "-";
            c.print();
            return 0;
        }

    }

    return 0;
}
