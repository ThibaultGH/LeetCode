#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string s, string p){

  // for (int i0 = 0; i0 < s.size(); ++i0) {
  //   printf("%c", s[i0]);
  // }
  // printf("\n");

  bool AlwaysMatchs = true;
  char RepetingChar;
  int CopyLength;
  int i1;
  bool RepetingCharAfterStar = true;
  string StringToCopy;
  
  for (int i0 = 0; i0 < p.size(); ++i0) {
    // printf("p[i0] = %c, p[i0+1] = %c\n", p[i0], p[i0+1]);

    if (p[i0] != '.' and p[i0+1] != '*') {
      AlwaysMatchs = false;
    }    

    if (p[i0] == '*') {

      RepetingChar = p[i0-1];
      // if (RepetingChar == '.') {
      // 	RepetingChar = s[i0-1];
      // }

      CopyLength = 0;
      i1 = i0-1;

      while (s[i1] == RepetingChar) {
	// printf("Here 1\n");
	if (p[i1+2] == RepetingChar and RepetingCharAfterStar) {
	  // printf("Here 2\n");
	  --CopyLength;
	  if (i1+3 < p.size() and p[i1+3] != RepetingChar) {
	    RepetingCharAfterStar = false;
	  }
	}
	++CopyLength;
	++i1;
      }

      StringToCopy = s.substr(i0-1,CopyLength);

      cout << "String to copy from s to p : " << StringToCopy << endl;
      
      p.replace(i0-1,2,StringToCopy);

      cout << p << endl;
      
      
    }
    
  }
  
  if (AlwaysMatchs) {
    return true;
  }

  if (p.size() != s.size()) {
    return false;
  }

  for (int i2 = 0; i2 < s.size(); ++i2) {
    if (s[i2] != p[i2] and p[i2] != '.') {
      return false;
    }
  }


  return true;
  

  
}

int main(int argc, char *argv[])
{

  // string s = "aab";
  // string p = "c*a*b";
  
  // bool matching;

  // matching = isMatch(s,p);

  // printf("%d\n", matching);

  vector<int> nums1 = {2,7,11,15};
  vector<int> nums2 = {3,2,4};
  vector<int> nums3 = {3,3};
  int target1 = 9;
  int target2 = 6;
  int target3 = 6;
  
  vector<int> out = twoSum(nums3,target3);

  cout << out[0] << " " << out[1] << endl;
  
  
  return 0;
}
