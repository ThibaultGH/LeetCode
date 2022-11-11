#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string longestPalindrome(string s) {

  int SizeS = s.size();
  if (SizeS == 1) {
    return s;
  }
  vector<string> Candidates;
  string TempString = ""; TempString.push_back(s[0]);
  Candidates.push_back(TempString);
  string Candidate = "";
  int IndexCandidate = 1;
  string out;
  int i1,i2;
  string::iterator backward;
  string::iterator forward;

  for (int i0 = 0; i0 < SizeS; ++i0) {
    // cout << s[i0] << "\n";

    if (i0 < SizeS-1 and s[i0] == s[i0+1]) {
      Candidates.push_back("");
      
      i1 = i0;
      i2 = i0+1;
      while (s[i1] == s[i2]) {
	Candidate.push_back(s[i2]);
	++i2;
	--i1;
	if (i2 == SizeS or i1 == -1) {
	  break;
	}
      }
      
      backward = Candidate.end()-1;
      for (int i3 = 0; i3 < Candidate.size(); ++i3) {
	// cout << *backward << "\n";
	Candidates[IndexCandidate].push_back(*backward);
	--backward;
      }
      
      // Candidates[IndexCandidate].push_back(*backward);

      forward = Candidate.begin();
      for (int i4 = 0; i4 < Candidate.size(); ++i4) {
	// cout << *forward << "\n";
	Candidates[IndexCandidate].push_back(*forward);
	++forward;
      }

      // cout << Candidates[IndexCandidate] << endl;
      Candidate.clear();
      
      ++IndexCandidate;
    }

    if (i0 > 0 and i0 < SizeS-1 and s[i0-1] == s[i0+1]) {
      Candidates.push_back("");
            
      i1 = i0-1;
      i2 = i0+1;
      
      // cout << s[i1] << " " << s[i2] << "\n";

      while (s[i1] == s[i2]) {
	Candidate.push_back(s[i2]);
	++i2;
	--i1;
	if (i2 == SizeS or i1 == -1) {
	  break;
	}
      }

      // cout << Candidate << "\n";
      
      backward = Candidate.end()-1;
      for (int i3 = 0; i3 < Candidate.size(); ++i3) {
	Candidates[IndexCandidate].push_back(*backward);
	--backward;
      }
      
      Candidates[IndexCandidate].push_back(s[i0]);

      forward = Candidate.begin();
      for (int i4 = 0; i4 < Candidate.size(); ++i4) {
	Candidates[IndexCandidate].push_back(*forward);
	++forward;
      }

      // cout << Candidates[IndexCandidate] << endl;
      Candidate.clear();
      
      ++IndexCandidate;
    }
  }

  // cout << Candidates[1] << "\n";

  int MaxLength = Candidates[0].size();
  out = Candidates[0];

  for (int i3 = 1; i3 < IndexCandidate; ++i3) {
    if (Candidates[i3].size() > MaxLength) {
      out = Candidates[i3];
      MaxLength = Candidates[i3].size();
    }
  }
  
  return out;
}

int main(int argc, char *argv[])
{
  string s = "cbbd";

  // vector<string> test(5);
  // test[0].push_back('a');
  // cout << test[0] << "\n";
  // test[0].push_back('a');
  // cout << test[0] << "\n";
  

  cout << longestPalindrome(s) << endl;
  
  return 0;
}
