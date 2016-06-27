#include"list.h"
//13.�ж����������Ƿ��ཻ���󽻵㣨�������������
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
	printf("�Ƿ��ཻ��%d\n",CheckCross1(list1,list2));
	ListNode * retCrossNode = CrossNode1(list1,list2);
	printf("����Ϊ��%d\n",retCrossNode->_data);

}
//12.�ж����������Ƿ��ཻ���󽻵㣨��������������
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
	printf("�Ƿ��ཻ��%d\n",CheckCross(list1,list2));
	ListNode * retCrossNode = CrossNode(list1,list2);
	printf("����Ϊ��%d\n",retCrossNode->_data);
}
//11.�жϵ������Ƿ�������󳤶ȡ���ڵ�
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
	printf("�������Ƿ������%d\n",HasCycle(list));
	int len = GetCycleLength(list);
	printf("�������ȣ�%d\n",len);
	ListNode * meetNode = MeetNode(list);
	ListNode * retEntry = GetEntryNode(list,meetNode);
	printf("��ڵ㣺%d\n",retEntry->_data);
}
//10.���ҵ�����ĵ�����K���ڵ㣬Ҫ��ֻ�ܱ���һ��
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

//9.���ҵ�������м�ڵ㣬Ҫ��ֻ����һ��
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

//8.�ϲ��������������ϲ�����Ȼ����
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
//7.����������(ð��)
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
//6.����/��ת������
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
//5.������ʵ��Լɪ��
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
//4.����ͷ�������һ����ͷ���ǰ����һ���ڵ�
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
//3.ɾ��һ����ͷ������ķ�β�ڵ�
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
//2.��β��ͷ��ӡ������
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