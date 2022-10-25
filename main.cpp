#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(0), next(next) {}
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
  
  string str_l3;
  
  ListNode *nx_l1 = l1->next;
  ListNode *nx_l2 = l2->next;
  ListNode *l3 = new ListNode();
  int sum = l1->val+l2->val;
  int carry = 0;
  int drop;

  if (nx_l1 == NULL and nx_l2 == NULL) {
    if (sum >= 10) {
      str_l3.append(to_string(sum%10));
      str_l3.append(to_string(sum/10));
    }
    else {
      str_l3.append(to_string(sum));
    }
  }

  while (nx_l1 != NULL or nx_l2 != NULL) {
    if (sum >= 10) {
      drop = sum % 10;
      carry = sum / 10;
    }
    else {
      drop = sum;
      carry = 0;
    }
    // cout << carry << endl;
    str_l3.append(to_string(drop));

    if (nx_l1 == NULL) {
      sum = nx_l2->val+carry;
      nx_l2 = nx_l2->next;
    }
    else if (nx_l2 == NULL) {
      sum = nx_l1->val+carry;
      nx_l1 = nx_l1->next;
    }
    else {
      sum = nx_l1->val + nx_l2->val + carry;
      nx_l1 = nx_l1->next;
      nx_l2 = nx_l2->next;
    }

    if (nx_l1 == NULL and nx_l2 == NULL) {
      if (sum >= 10) {
	str_l3.append(to_string(sum%10));
	str_l3.append(to_string(sum/10));
      }
      else {
	str_l3.append(to_string(sum));
      }
      
    }
    
    

  }

  // cout << str_l3 << endl;
  l3->val = str_l3[0]-'0';
  ListNode *nx = new ListNode();
  if (str_l3.size() == 1) {
    l3->next = NULL;
  }
  else {
    l3->next = nx;
  }
  

  for (int i0 = 1; i0 < str_l3.size(); ++i0) {
    // cout << str_l3[i0]-'0' << endl;
    nx->val = str_l3[i0]-'0';
    // cout << nx->val << endl;
    
    if (i0 == str_l3.size()-1) {
      nx->next = NULL;
    }
    else {
      nx->next = new ListNode();
    }
    nx = nx->next;
  }
  
  return l3;

}

void ListNodesFromChar(struct ListNode* ptrList, char *array, int size) {
    struct ListNode *auxNode = ptrList;
    for(int i = 0; i < size; i++) {
        ptrList->val = array[i];
        if(i + 1 != size) {
	  ptrList->next = (struct ListNode *)  malloc(sizeof(struct ListNode));
	  ptrList = ptrList->next;
        }
    }
    ptrList = auxNode;
    // printf("\n");
}

void printAnswer(struct ListNode *ptrAnswer) {
  for(; ptrAnswer != NULL; ptrAnswer = ptrAnswer->next){
    printf("%d ", ptrAnswer->val);
  }
  printf("\n");
    
}

int main(int argc, char *argv[])
{
  struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
  struct ListNode *l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
  char list[1] = {9};
  char list2[1] = {9};
  ListNodesFromChar(l1, list, 1);
  ListNodesFromChar(l2, list2, 1);
  printAnswer(l1);
  printAnswer(l2);
  struct ListNode *answer = addTwoNumbers(l1, l2);
  printAnswer(answer);
    
  return 0;
}
