#include <iostream>
#include <vector>
#include <random>

using namespace std;

void SortArray(vector<int> &nums1){

  int m = nums1.size();

  int smallest = nums1[0];
  int pos_smallest = 0;
  int count = 0;

  while (count < m) {
    for (int i0 = count+1; i0 < m; ++i0) {
      if (nums1[i0] < smallest) {
	smallest = nums1[i0];
	pos_smallest = i0;
      }
    }

    if (count != m-1) {
      nums1[pos_smallest] = nums1[count];
      nums1[count] = smallest;
      smallest = nums1[count+1];
    }
    ++count;
    
  }
  
  // for (int i1 = 0; i1 < m; ++i1) {
  //   printf("%d ", nums1[i1]);
  // }
  // printf("\n");
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){

  int m = nums1.size();
  int n = nums2.size();
  double median;

  if (m == 0) {
    if (n == 0) {
      return 0;
    }
    else {
      if (n%2 == 0) {
	median = nums2[n/2-1]+nums2[n/2];
	return median/2;
      }
      else {
	median = nums2[n/2];
	return median;
      }
    }
  }

  if (n == 0) {
    if (m == 0) {
      return 0;
    }
    else {
      if (m%2 == 0) {
	median = nums1[m/2-1]+nums1[m/2];
	return median/2;
      }
      else {
	median = nums1[m/2];
	return median;
      }
    }
  }

  if (m == 1 and n == 1) {
    median = nums1[0]+nums2[0];
    return median/2;
  }

  int count = 0;
  vector<int>::iterator it1 = nums1.begin();
  vector<int>::iterator it2 = nums2.begin();

  int current;
  if (*it1 <= *it2) {
    current = *it1;
    if (it1 != --nums1.end()) {
      ++it1;
    }
    else{
      *it1 = 2147483647;
    }
  }
  else {
    current = *it2;
    if (it2 != --nums2.end()) {
      ++it2;
    }
    else{
      *it2 = 2147483647;
    }
  }
  ++count;
  int next;
  bool keep_going_strong = true;

  while (count < (m+n)/2) {

    
    printf("current : %d\n", current);
    printf("next : it1 = %d, it2 = %d\n", *it1,*it2);
    
    
    if (*it1 < *it2) {
      current = *it1;
      if (it1 != --nums1.end()) {
	++it1;
      }
      else {
	// it1 = it2;
	*it1 = 2147483647;
      }
    }
    else {
      current = *it2;
      if (it2 != --nums2.end()) {
	++it2;
      }
      else {
	// it2 = it1;
	*it2 = 2147483647;
      }
    }
    ++count;
    // current = next;

  }

  printf("current : %d\n", current);
  printf("next : it1 = %d, it2 = %d\n", *it1,*it2);
  
  if ((m+n)%2 != 0) {
    if (*it1 < *it2) {
      median = *it1;
    }
    else{
      median = *it2;
    }
  }
  else {
    if (*it1 < *it2) {
      // printf("current = %d, next = %d\n", current,*it1);
      median = (current+*it1);
      median = median/2;
    }
    else{
      // printf("current = %d, next = %d\n", current,*it2);
      median = (current+*it2);
      median = median/2;
    }
  }
  
  

  return median;

}

int main(int argc, char *argv[])
{
  
  vector<int> nums1 = {1};
  vector<int> nums2 = {2,3,4};
  
  // SortArray(nums1);
  // SortArray(nums2);

  // for (int i0 = 0; i0 < m; ++i0) {
  //   printf("%d ", nums1[i0]);
  // }
  // cout << "\n";

  double median = findMedianSortedArrays(nums1,nums2);

  printf("%f\n", median);
  
  return 0;
}
