#include<iostream>
#include<vector>
using namespace std;


//-----链表常用操作，面试常用题目
//1、单链表反转
//2、合并两个有序单链表
//

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


/*Reverse a singly linked list.
Hint:
A linked list can be reversed either iteratively or recursively.Could you implement both ?*/

#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {   //Accepted leetcode21

		ListNode *prehead = new ListNode(-1);   //创建一个头结点，值为-1
		ListNode *prev = prehead;

		while (l1 != NULL && l2 != NULL)
		{
			if (l1->val <= l2->val) {
				prev->next = l1;
				l1 = l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}
		if (l1 != NULL)prev->next = l1;
		else prev->next = l2;

		return prehead->next;
	}
//-----------------------------------------------------------------
	ListNode* reverseList(ListNode* head) {   //Accepted  leetcode206

		if (head == NULL || head->next == NULL) return head;

		ListNode *p1 = head;
		ListNode *p2 = p1->next;
		ListNode *p3 = NULL;

		while (p2) {

			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}

		head->next = NULL;
		head = p1;
		return head;
	}

	ListNode* reverseList2(ListNode* head) { //Accepted
		ListNode *pre = NULL;
		ListNode *cur = head;

		while (cur) {
			ListNode *nextTemp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nextTemp;
		}
		return pre;
	}
};
//-----------------------------------------------------------------
//求链表长度
int length(ListNode * head) {
	ListNode *read = head;
	int length = 0;
	while (read != NULL)
	{
		read = read->next;
		length++;
	}
	return length;
}
//-----------------------------------------------------------------
//链表的创建
ListNode *createList(ListNode *head, vector<int> nums) {   

	ListNode *end = NULL;
	
	for (int i = 0; i < nums.size(); i++)
	{
		//ListNode cur = ListNode(nums[i]);

		ListNode *cur = new ListNode(nums[i]);
		if (head == NULL) head = cur;
		else {
			end->next = cur;
		}
		end = cur;
	}
	if (head != NULL)
	{
		end->next = NULL;
	}
	return head;
}
//-----------------------------------------------------------------
//链表的显示
void displayList(ListNode *head) {
	ListNode *read = head;
	while (read != NULL)
	{
		cout << read->val << " ";
		read = read->next;
	}
	cout << endl;
}
//-----------------------------------------------------------------

int main() {

	vector<int> nums = { 2,4,8,1 };
	
	ListNode *head = NULL;

	head = createList(head, nums);
	displayList(head);
	cout << length(head) << endl;

	return 0;

}