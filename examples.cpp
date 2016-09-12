#include "crypto.hpp"
#include <iostream>

using namespace std;

int main() {
  cout << "SHA-1 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha1("Test")) << endl << endl;
  
  cout << "SHA-1 with two iterations" << endl;
  cout << Crypto::hex(Crypto::sha1(Crypto::sha1("Test"))) << endl;
  cout << Crypto::hex(Crypto::sha1("Test", 2)) << endl << endl;
  
  cout << "MD5 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::md5("Test")) << endl << endl;
  
  cout << "SHA-256 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha256("Test")) << endl << endl;
  
  cout << "SHA-512 with 1 iteration" << endl;
  cout << Crypto::hex(Crypto::sha512("Test")) << endl << endl;
  
  cout << "The derived key from the PBKDF2 algorithm" << endl;
  cout << Crypto::hex(Crypto::pbkdf2("Password", "Salt")) << endl;
  
  char table[3];
  for(int i = 65; i <= 122; i++)
    {
   for(int j = 65; j <= 122; j++)
     {
     for(int k = 65; k <= 122; k++)
       {
        table[0] = char(i);
        table[1] = char(j);
        table[2] = char(k);
        
        cout << table << endl;
        
        if(Crypto::hex(Crypto::pbkdf2(table, "Saltet til Ola", 2048, 20)) == "ab29d7b5c589e18b52261ecba1d3a7e7cbf212c6")
        {
          cout << "The password is: " << table << endl;
          return 0;
        }
      } 
    } 
  }
}
