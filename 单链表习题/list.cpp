#include"list.h"
//13.判断两个链表是否相交，求交点（假设链表带环）
void Test13()
{
	ListNode * list1 = NULL;
	PushBack(list1,1);
	PushBack(list1,3);
	PushBack(list1,2);
	PushBack(list1,6);
	PushBack(list1,7);
	PushBack(list1,9);
	ListNode * tail1 = Find(list1,9);
	ListNode * tmp1 = Find(list1,6);
	ListNode * tmp2 = Find(list1,2);
	tail1->_next = tmp1;
	ListNode * list2 = NULL;
	PushBack(list2,4);
	PushBack(list2,5);
	PushBack(list2,8);
	ListNode * tail2 = Find(list2,8);
	tail2->_next = tmp2;
	printf("是否相交：%d\n",CheckCross1(list1,list2));
	ListNode * retCrossNode = CrossNode1(list1,list2);
	printf("交点为：%d\n",retCrossNode->_data);

}
//12.判断两个链表是否相交，求交点（假设链表不带环）
void Test12()
{
	ListNode * list1 = NULL;
	PushBack(list1,1);
	PushBack(list1,3);
	PushBack(list1,2);
	PushBack(list1,6);
	PushBack(list1,7);
	PushBack(list1,9);
	ListNode * list2 = NULL;
	PushBack(list2,4);
	PushBack(list2,5);
	PushBack(list2,8);
	ListNode * crossNode = Find(list1,6);
	ListNode * tail2 = Find(list2,8);
	tail2->_next = crossNode;
	printf("是否相交：%d\n",CheckCross(list1,list2));
	ListNode * retCrossNode = CrossNode(list1,list2);
	printf("交点为：%d\n",retCrossNode->_data);
}
//11.判断单链表是否带环，求长度、入口点
void Test11()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,7);
	PushBack(list,9);
	ListNode * tail = Find(list,9);
	ListNode * entry = Find(list,6);
	tail->_next = entry;
	printf("单链表是否带环：%d\n",HasCycle(list));
	int len = GetCycleLength(list);
	printf("单链表长度：%d\n",len);
	ListNode * meetNode = MeetNode(list);
	ListNode * retEntry = GetEntryNode(list,meetNode);
	printf("入口点：%d\n",retEntry->_data);
}
//10.查找单链表的倒数第K个节点，要求只能遍历一次
void Test10()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,7);
	PushBack(list,9);
	PrintList(list);
	ListNode * kNode = FindKTailNode(list,2);
	printf("%d\n",kNode->_data);
}

//9.查找单链表的中间节点，要求只遍历一次
void Test9()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,7);
	PushBack(list,9);
	PrintList(list);
	ListNode * mid = FindMid(list);
	PrintList(mid);
}

//8.合并两个有序链表，合并后依然有序
void Test8()
{
	ListNode * list_a = NULL, *list_b = NULL;
	PushBack(list_a,1);
	PushBack(list_a,2);
	PushBack(list_a,6);
	PushBack(list_a,7);
	PushBack(list_a,9);
	PrintList(list_a);
	PushBack(list_b,3);
	PushBack(list_b,5);
	PushBack(list_b,7);
	PushBack(list_b,9);
	PushBack(list_b,10);
	PrintList(list_b);
	ListNode * newList = CombineList(list_a,list_b);
	PrintList(newList);
}
//7.单链表排序(冒泡)
void Test7()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,8);
	PushBack(list,7);
	PushBack(list,5);
	PrintList(list);
//	BubSort(list);
	SelectSort(list);
	PrintList(list);

}
//6.逆置/反转单链表
void Test6()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,9);
	PrintList(list);
	Reverse(list);
	PrintList(list);
}
//5.单链表实现约瑟夫环
void Test5()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,1);
	PushBack(list,6);
	PushBack(list,9);
	PrintList(list);
	Joseph(list,4);
}
//4.在无头单链表的一个非头结点前插入一个节点
void Test4()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,9);
	PrintList(list);
	ListNode * pos = Find(list,3);
	InsertFrontNode(pos,5);
	PrintList(list);
}
//3.删除一个无头单链表的非尾节点
void Test3()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,9);
	PrintList(list);
	ListNode * pos = Find(list,6);
	DelNonTailNode(pos);
	PrintList(list);
}
//2.从尾到头打印单链表
void Test2()
{
	ListNode * list = NULL;
	PushBack(list,1);
	PushBack(list,3);
	PushBack(list,2);
	PushBack(list,6);
	PushBack(list,9);
	PrintList(list);
	PrintTailToHead(list);
}

int main()
{
	//Test2();
	//Test3();
	//Test4();
	//Test6();
	//Test5();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	//Test12();
	Test13();
}