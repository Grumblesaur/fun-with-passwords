#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
  string plain_pass="password";
  string salt="salt";
  cout << "Please enter a plaintext password:\n";
  cin >> plain_pass;
  cout <<"\nNow enter a salt: \n";
  cin >> salt;
  const char * arg1 = plain_pass.c_str();
  const char * arg2 = salt.c_str();
  string hash = crypt(arg1, arg2);
  cout << "The Hash is: " << hash <<"\n";
  return 0;
}
