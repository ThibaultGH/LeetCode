#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool isPalindrome(int x){

  if (x < 10 and x > -1) {
    return true;
  }
  else if (x <= -1) {
    return false;
  }

  string str_x = to_string(x);

  // cout << str_x.empty() << "\n";

  string::iterator beg = str_x.begin();
  string::iterator end = str_x.end()-1;

  bool IsPalindrome = true;  
  int SizeLoop = floor(str_x.size()/2);

  for (int i0 = 0; i0 < SizeLoop; ++i0) { // beg != str_x.end() and end != str_x.begin()

    // cout << *beg << " " << *end << "\n";

    if (*beg != *end) {
      IsPalindrome = false;
    }

    ++beg;
    --end;
  }
  
  return IsPalindrome;
}

int main(int argc, char *argv[])
{

  int x = 11;

  cout << isPalindrome(x) << "\n";
  
  return 0;
}
