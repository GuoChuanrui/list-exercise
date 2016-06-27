#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;
//���嵥����
typedef struct ListNode
{
	DataType _data;    //����
	struct ListNode * _next;   //ָ����һ���ڵ��ָ��
}ListNode;


//2.��β��ͷ��ӡ������
void PrintTailToHead(ListNode * pHead)
{
	if(pHead)
	{
		PrintTailToHead(pHead->_next);
		printf("%d  <- ",pHead->_data);
	}
}

//3.ɾ��һ����ͷ������ķ�β�ڵ�
void DelNonTailNode(ListNode * pos)
{
	assert(pos && pos->_next);
	pos->_data = pos->_next->_data;
	ListNode * next = pos->_next->_next;
	free(pos->_next);
	pos->_next = next;
}

//�����ڵ�
ListNode * BuyNode(DataType x)
{
	ListNode * tmp = (ListNode *)malloc(sizeof(ListNode));
	assert(tmp);
	tmp->_data = x;
	tmp->_next = NULL;
	return tmp;
}

//4.����ͷ�������һ����ͷ���ǰ����һ���ڵ�
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

//5.������ʵ��Լɪ��
void Joseph(ListNode * &pHead,int x)
{
	int count=1;    //����ڵ����
	ListNode * cur = pHead, *tail = pHead;
	while(tail->_next != NULL)
	{
		tail = tail->_next;     //��tailָ�����һ���ڵ�
		count++;

	}	
	tail->_next = pHead;    //�γɻ�
	while(count > 1)
	{
		int i=0;
		while(i < x-1)
		{
			tail = tail->_next;
			i++;
		} 
		cur = tail->_next;     //curָ���x�� ��ɾ��cur
		printf("%d  ",cur->_data);  
		tail->_next = cur->_next;  
		free(cur);
		count--;
	}
	
}

//6.����/��ת������
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

//7.����������(ð��)
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
			if(cur->_data > cur->_next->_data)  //��ǰ���ݴ��ں�������ݣ�����ֵ
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
//7.����������(ѡ��)
void SelectSort(ListNode * pHead)
{
	ListNode * cur = pHead;
	while(cur)
	{
		ListNode * tmp = cur->_next;
		while(tmp)
		{
			if(cur->_data > tmp->_data)  //��ǰ���ݴ��ں�������ݣ�����ֵ
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

//8.�ϲ��������������ϲ�����Ȼ����
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


//9.���ҵ�������м�ڵ㣬Ҫ��ֻ����һ��
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

//10.���ҵ�����ĵ�����K���ڵ㣬Ҫ��ֻ�ܱ���һ��
ListNode * FindKTailNode(ListNode * pHead,int k)
{
	ListNode * slow = pHead, * fast = pHead;
	while(k--)
	{
		if(fast == NULL)    //û��k��ô��,���ؿ�
		{
			return NULL;
		}
		fast = fast->_next;    //fast����k��
	}
	while(fast)
	{
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}

//11.�жϵ������Ƿ�������󳤶ȡ���ڵ�
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
ListNode * MeetNode(ListNode *pHead)    //�ҵ�����ָ���������
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

int GetCycleLength(ListNode * meetNode)    //�󻷵ĳ���
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

ListNode * GetEntryNode(ListNode *pHead, ListNode * meetNode)    //����ڵ�
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

//12.�ж����������Ƿ��ཻ���󽻵㣨��������������
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
ListNode *CrossNode(ListNode * l1,ListNode * l2)   //�󽻵�
{
	ListNode * cur1 = l1, * cur2 = l2;
	ListNode * tail1 = l1, *tail2 = l2;
	int len1 = 1, len2 = 1;
	while(tail1->_next != NULL)       //�ֱ������������
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
	if(len1 > len2)     //��l1��������x��
	{
		x = len1 - len2;
		while(x--)
		{
			cur1 = cur1->_next;
		}
	}
	else              //��l2��������x��
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
//13.�ж����������Ƿ��ཻ���󽻵㣨�������������
bool CheckCross1(ListNode * l1, ListNode * l2)
{
	ListNode * meetNode1 = MeetNode(l1);
	ListNode * meetNode2 = MeetNode(l2);
	if(meetNode1 == NULL && meetNode2 ==NULL)       //������
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
	if(meetNode1 && meetNode2)         //����
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
ListNode * CrossNode1(ListNode * l1,ListNode * l2)   //�󽻵�
{
	ListNode * meetNode1 = MeetNode(l1);
	ListNode * meetNode2 = MeetNode(l2);
	ListNode * entryNode1 = GetEntryNode(l1,meetNode1);
	ListNode * entryNode2 = GetEntryNode(l2,meetNode2);
	if(entryNode1 == entryNode2)      //��ڵ�һ����˵�����뻷֮ǰ���ཻ
	{
		entryNode1 = NULL;
		ListNode * crossNode = CrossNode(l1,l2);
		return crossNode;
	}
	else         //��ڵ㲻ͬ��˵���ڻ����ཻ(Ӧ���������㣬���ڼ���l2��l1)
	{
		return entryNode2;
	}

}


//β��
void PushBack(ListNode * &pHead, DataType x)
{
	if(NULL == pHead)      //Ϊ��ʱ����ʾû�нڵ㣬�����½ڵ�
	{
		pHead = BuyNode(x);
	}
	else
	{
		ListNode * tail = pHead;
		while(tail->_next != NULL)
		{
			tail = tail->_next;     //��tailָ�����һ���ڵ�
		}
		tail->_next = BuyNode(x);
	}
}






//ɾ��ĳ�ڵ�
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
	else if(pHead == pos)    //��Ҫɾ���Ľڵ���ǵ�һ��ʱ��ֱ��ɾ
	{
		pHead = pHead->_next;		
	}
	else
	{
		ListNode * prev = pHead, * after = pos->_next;    //����ڵ�ǰ���󣬷ֱ�ֵ
		while(prev->_next != pos)
		{
			prev = prev->_next;
		}
		prev->_next = after;     //��Ҫɾ���ڵ��ǰ���������ýڵ㱻ɾ��
	}
}

//����
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

//ɾ������Ϊx�Ľڵ�
void Remove(ListNode * &pHead, DataType x)
{
	if(NULL == pHead)
	{
		printf("List is empty!\n");
		return ;
	}
	else
	{
		ListNode * tmp = Find(pHead,x);    //����ʱ����ָ��x���ڽڵ�
		if(NULL == tmp)
		{
			printf("No x \n");
			return ;
		}
		Erase(pHead, tmp);		//ɾ���˽ڵ�
	}
}



//����
void Insert(ListNode * &pos, DataType x)    //��pos�ڵ�����
{
	assert(pos);
	ListNode * next = pos->_next;     
	pos->_next = BuyNode(x);
	pos->_next->_next = next;
}



//��ӡ���
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