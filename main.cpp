#include <iostream>
#include <string>
#include <vector>
#include <map>

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

vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> out(2);
        int i0 = 0;
        int i1 = 0;
        int count = 1;

        while(nums[i0]+nums[i1] != target or i0 == i1){

	  printf("i0 = %d, i1 = %d\n", i0,i1);
	  
            if(count < nums.size()){
                ++i1;
                ++count;
            }
            else{
	      i1 = 0;
	      ++i0;
	      count = 1;
            }
        }

        if(i1 < i0){
            out[0] = i1;
            out[1] = i0;
        }
        else{
            out[0] = i0;
            out[1] = i1;
        }

        return out;   
    }

int lengthOfLongestSubstring(string s) {

  int SizeString = s.size();
  
  if (s.empty()) {
    return 0;
  }
  else if (SizeString == 1) {
    return 1;
  }

  vector<string> Candidate(SizeString,"");
  int IndexCandidate = 0;
  // char TempChar;


  for (auto it0 = s.begin(); it0 != s.end(); ++it0) {
    
    // cout << "*it0 : " << *it0 << "\n";
        
    Candidate[IndexCandidate].push_back(*it0);

    auto it1 = it0+1;
    
    while (Candidate[IndexCandidate].find(*it1) == string::npos and it1 != s.end()) {
      // cout << "IndexCandidate = " << IndexCandidate << " *it1 : " << *it1 << "\n";
      // printf("IndexCandidate = %d\n", IndexCandidate);
      
      // TempChar = *it1;
      Candidate[IndexCandidate].push_back(*it1);
      ++it1;
    }

    ++IndexCandidate;
    
  }

  int out = Candidate[0].size();

  for (int i0 = 0; i0 < Candidate.size(); ++i0) {
    if (Candidate[i0].size() > out) {
      cout << Candidate[i0] << "\n";
      out = Candidate[i0].size();
    }
  }

  return out;

}

int main(int argc, char *argv[])
{

  string s = "azertbycuiaopqsdbfghjklmc";
  string answer = "zertbycuiaopqsdbfghjklm";

  cout << lengthOfLongestSubstring(s) << endl;
  
  return 0;
}
