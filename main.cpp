#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string convert(string s, int numRows) {

  int SizeS = s.size();
  vector<string> Rows(numRows,"");;
  char space = ' ';
  int sDivnumRows = SizeS/numRows+1;
  while (s.size() != numRows*sDivnumRows) {
    s.push_back(' ');
  }

  // cout << s << "\n";

  string::iterator it = s.begin();
  int column = 0;
  string ColumnToCopy = "";

  while (it != s.end()) {
    
    if (column%numRows == 0 ) {
      for (int i0 = 0; i0 < numRows; ++i0) {
      Rows[i0].push_back(*(it+i0));
      Rows[i0].push_back(' ');
      }

    }
    
    it = it+numRows;
  }

  for (int i1 = 0; i1 < numRows-1; ++i1) {
    cout << Rows[i1] << "\n";
  }

  

  return Rows[0];
}

int main(int argc, char *argv[])
{

  string s = "PAYPALISHIRING"; // length = 14
  int numRows = 3;

  cout << convert(s,numRows) << "\n";
  
  return 0;
}
