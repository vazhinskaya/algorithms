#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

int evklid(int a, int b) {
   int k;
   while(1) {
      k = a % b;
      if(k==0)
      return a;
      a = b;
      b = k;
   }
}


int encrypt(int m, int e, int n)
{
  int c = 1;
  while( e > 0 )
  {
        if( (e % 2) == 1 )
        {
                c = (c * m) % n;
        }
        e /= 2;
        m = (m * m) % n;
  }
  return c;
}

int decrypt(int m, int d, int n)
{
  int c = 1;
  while( d > 0 )
  {
        if( (d % 2) == 1 )
        {
                d = (d * m) % n;
        }
        d /= 2;
        m = (m * m) % n;
  }
  return c;
}


const int p = 999023;
const int q = 333667;

int main()  {
    long n = p * q;
    long f = ( q - 1 ) * ( p - 1 );
    int d, d_simple = 0;
    long f=( q - 1 ) * ( p - 1 );
    while (d_simple !=1) {
    d = rand()%100;
    d_simple = evklid(d, f);
    }

    long int e = 0, e_simple = 0;
    while (e_simple !=1) {
    e += 1;
    e_simple = (e*d)%f;

    int M = 359;
    int E = encrypt(M, e, n);
    cout << 'Encryption' << E << endl;
    cout << 'Decryption' << decrypt(E, d, n) << endl;
}






