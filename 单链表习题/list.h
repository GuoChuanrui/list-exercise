#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;
//定义单链表
typedef struct ListNode
{
	DataType _data;    //数据
	struct ListNode * _next;   //指向下一个节点的指针
}ListNode;


//2.从尾到头打印单链表
void PrintTailToHead(ListNode * pHead)
{
	if(pHead)
	{
		PrintTailToHead(pHead->_next);
		printf("%d  <- ",pHead->_data);
	}
}

//3.删除一个无头单链表的非尾节点
void DelNonTailNode(ListNode * pos)
{
	assert(pos && pos->_next);
	pos->_data = pos->_next->_data;
	ListNode * next = pos->_next->_next;
	free(pos->_next);
	pos->_next = next;
}

//创建节点
ListNode * BuyNode(DataType x)
{
	ListNode * tmp = (ListNode *)malloc(sizeof(ListNode));
	assert(tmp);
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}

//4.在无头单链表的一个非头结点前插入一个节点
void InsertFrontNode(ListNode * pos,DataType x)
{
	assert(pos);
	ListNode * tmp = BuyNode(x);
	tmp->_next = pos->_next;
	pos->_next = tmp;
	DataType tmpData = tmp->_data;
	tmp->_data = pos->_data;
	pos->_data = tmpData;
} 

//5.单链表实现约瑟夫环
void Joseph(ListNode * &pHead,int x)
{
	int count=1;    //链表节点个数
	ListNode * cur = pHead, *tail = pHead;
	while(tail->_next != NULL)
	{
		tail = tail->_next;     //令tail指向最后一个节点
		count++;

	}	
	tail->_next = pHead;    //形成环
	while(count > 1)
	{
		int i=0;
		while(i < x-1)
		{
			tail = tail->_next;
			i++;
		} 
		cur = tail->_next;     //cur指向第x个 ，删掉cur
		printf("%d  ",cur->_data);  
		tail->_next = cur->_next;  
		free(cur);
		count--;
	}
	
}

//6.逆置/反转单链表
void Reverse(ListNode * &pHead)
{
	ListNode * cur = pHead;
	ListNode * newHead = NULL;
	while(cur)
	{
		ListNode * tmp = cur;
		cur = cur->_next;
		tmp->_next = newHead;
		newHead = tmp;
	}
	pHead = newHead;
}

//7.单链表排序(冒泡)
void BubSort(ListNode *pHead)
{
	ListNode * cur;
	bool flag = true;
	while(flag)
	{
		cur = pHead;
		flag = false;
		while(cur->_next)
		{
			if(cur->_data > cur->_next->_data)  //当前数据大于后面的数据，交换值
			{
				flag = true;
				DataType tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;			
			}
			cur = cur->_next;
		}
	}
}
//7.单链表排序(选择)
void SelectSort(ListNode * pHead)
{
	ListNode * cur = pHead;
	while(cur)
	{
		ListNode * tmp = cur->_next;
		while(tmp)
		{
			if(cur->_data > tmp->_data)  //当前数据大于后面的数据，交换值
			{
				DataType tmpData = tmp->_data;
				tmp->_data = cur->_data;
				cur->_data = tmpData;			
			}
			tmp = tmp->_next;
		}
		cur = cur->_next;
	}
}

//8.合并两个有序链表，合并后依然有序
ListNode *CombineList(ListNode * &list_a,ListNode * & list_b)
{
	ListNode * cur_a = list_a , * cur_b = list_b;
	ListNode * newHead = BuyNode(0);
	ListNode * cur = newHead;
	while(cur_a && cur_b)
	{
		if(cur_a->_data <= cur_b->_data)
		{
			cur->_next = cur_a;
			cur = cur->_next;
			cur_a = cur_a->_next;
		}
		else
		{
			cur->_next = cur_b;
			cur = cur->_next;
			cur_b = cur_b->_next;
		}
	}
	cur->_next = (cur_a == NULL)?cur_b:cur_a;
	return newHead->_next;
}


//9.查找单链表的中间节点，要求只遍历一次
ListNode * FindMid(ListNode *pHead)
{
	ListNode * slow = pHead, * fast = pHead;
	while(fast && fast->_next)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	slow->_next = NULL;
	return slow;
}

//10.查找单链表的倒数第K个节点，要求只能遍历一次
ListNode * FindKTailNode(ListNode * pHead,int k)
{
	ListNode * slow = pHead, * fast = pHead;
	while(k--)
	{
		if(fast == NULL)    //没有k这么长,返回空
		{
			return NULL;
		}
		fast = fast->_next;    //fast先走k步
	}
	while(fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}

//11.判断单链表是否带环，求长度、入口点
bool HasCycle(ListNode *pHead)
{
	ListNode * slow = pHead, * fast = pHead;
	while(fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if(slow == fast)
		{
			return true;
	
		}
	}
	return false;
}
ListNode * MeetNode(ListNode *pHead)    //找到快慢指针的相遇点
{
	ListNode * slow = pHead, * fast = pHead;
	while(fast && fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
		if(slow == fast)
			return slow;
	}
	return NULL;
}

int GetCycleLength(ListNode * meetNode)    //求环的长度
{
	ListNode * slow = meetNode->_next, * fast = meetNode->_next->_next;
	int count = 1;
	while(slow != fast)
	{
		slow = slow->_next;
		fast = fast->_next->_next;
		count ++;
	}
	return count;
}

ListNode * GetEntryNode(ListNode *pHead, ListNode * meetNode)    //求入口点
{
	while(pHead && meetNode)
	{
		if(pHead == meetNode)
		{
			return pHead;
		}
		pHead = pHead->_next;
		meetNode = meetNode->_next;
	}
	return NULL;
}

//12.判断两个链表是否相交，求交点（假设链表不带环）
bool CheckCross(ListNode * l1,ListNode * l2)
{
	ListNode * tail1 = l1, * tail2 = l2;
	while(tail1->_next != NULL)
	{
		tail1 = tail1->_next;
	}
	while(tail2->_next != NULL)
	{
		tail2 = tail2->_next;
	}
	if(tail1 == tail2)
	{
		return true;
	}
	return false;
}
ListNode *CrossNode(ListNode * l1,ListNode * l2)   //求交点
{
	ListNode * cur1 = l1, * cur2 = l2;
	ListNode * tail1 = l1, *tail2 = l2;
	int len1 = 1, len2 = 1;
	while(tail1->_next != NULL)       //分别求出单链表长度
	{
		tail1 = tail1->_next;
		len1 ++;
	}
	while(tail2->_next != NULL)
	{
		tail2 = tail2->_next;
		len2 ++;
	}
	int x;
	if(len1 > len2)     //若l1长，先走x步
	{
		x = len1 - len2;
		while(x--)
		{
			cur1 = cur1->_next;
		}
	}
	else              //若l2长，先走x步
	{
		x = len2 - len1;
		while(x--)
		{
			cur2 = cur2->_next;
		}
	}
	while(cur1 != cur2)
	{
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return cur1;
}
//13.判断两个链表是否相交，求交点（假设链表带环）
bool CheckCross1(ListNode * l1, ListNode * l2)
{
	ListNode * meetNode1 = MeetNode(l1);
	ListNode * meetNode2 = MeetNode(l2);
	if(meetNode1 == NULL && meetNode2 ==NULL)       //不带环
	{
		ListNode * tail1 = l1, *tail2 = l2;
		while(tail1->_next != NULL)
		{
			tail1 = tail1->_next;
		}
		while(tail2->_next != NULL)
		{
			tail2 = tail2->_next;
		}
		if(tail1 == tail2)
			return true;
		else
			return false;
	}
	if(meetNode1 && meetNode2)         //带环
	{
		ListNode * cur1 = meetNode1;
		while(cur1->_next != meetNode1)
		{
			if(cur1 == meetNode2)
				return true;
			cur1 = cur1->_next;
		}
		return false;
	}
}
ListNode * CrossNode1(ListNode * l1,ListNode * l2)   //求交点
{
	ListNode * meetNode1 = MeetNode(l1);
	ListNode * meetNode2 = MeetNode(l2);
	ListNode * entryNode1 = GetEntryNode(l1,meetNode1);
	ListNode * entryNode2 = GetEntryNode(l2,meetNode2);
	if(entryNode1 == entryNode2)      //入口点一样，说明在入环之前就相交
	{
		entryNode1 = NULL;
		ListNode * crossNode = CrossNode(l1,l2);
		return crossNode;
	}
	else         //入口点不同，说明在环内相交(应有两个交点，现在假设l2交l1)
	{
		return entryNode2;
	}

}


//尾插
void PushBack(ListNode * &pHead, DataType x)
{
	if(NULL == pHead)      //为空时，表示没有节点，创建新节点
	{
		pHead = BuyNode(x);
	}
	else
	{
		ListNode * tail = pHead;
		while(tail->_next != NULL)
		{
			tail = tail->_next;     //令tail指向最后一个节点
		}
		tail->_next = BuyNode(x);
	}
}






//删除某节点
void Erase(ListNode * &pHead, ListNode * &pos)
{
	if(NULL == pHead)
	{
		printf("List is empty!\n");
		return ;
	}
	else if(NULL == pos)
	{
		printf("Pos is empty!\n");
		return ;
	}
	else if(pHead == pos)    //当要删除的节点就是第一个时，直接删
	{
		pHead = pHead->_next;		
	}
	else
	{
		ListNode * prev = pHead, * after = pos->_next;    //定义节点前、后，分别赋值
		while(prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = after;     //将要删除节点的前后相连，该节点被删除
	}
}

//查找
ListNode * Find(ListNode * pHead, DataType x)
{
	ListNode * cur = pHead;
	while(cur)
	{
		if(cur->_data == x)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

//删除数据为x的节点
void Remove(ListNode * &pHead, DataType x)
{
	if(NULL == pHead)
	{
		printf("List is empty!\n");
		return ;
	}
	else
	{
		ListNode * tmp = Find(pHead,x);    //用临时变量指向x所在节点
		if(NULL == tmp)
		{
			printf("No x \n");
			return ;
		}
		Erase(pHead, tmp);		//删除此节点
	}
}



//插入
void Insert(ListNode * &pos, DataType x)    //在pos节点后插入
{
	assert(pos);
	ListNode * next = pos->_next;     
	pos->_next = BuyNode(x);
	pos->_next->_next = next;
}



//打印输出
void PrintList(ListNode * pHead)
{
	ListNode * cur = pHead;
	while(cur != NULL)
	{
		printf("%d -> ",cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}