#include <iostream>

using namespace std;

/*За стислим списком (індекс + значення) відтворити початковий розріджений список (комірки між наявними індексами заповнені нулями)*/

struct compList{
	int num;
	int index;
	compList *left, *right;
};

void addNode(compList** head, compList** tail, int n, int index)
{
	compList* temp = new compList;
	temp->num = n;
	temp->index = index;

	if(*head == NULL)
	{
		*head = temp;
		*tail = temp;
		temp->left = NULL;
		temp->right = NULL;
	}
	else
	{
		temp->right = *tail;
		temp->left = NULL;
		(*tail)->left = temp;
		*tail = temp;
	}
}

void delNode (compList** head, compList** tail)
{
	if(!(*head))
	{
		cout<<"The list is empty!"<<endl;
	}
	
	compList* temp = *head;
	
	if(*head == *tail)
	{
		*head = NULL;
		*tail = NULL;
		delete temp;
		return;
	}
	
	temp->left->right = NULL;
	*head = temp->left;
	delete temp;
}

void delList(compList** head, compList** tail)
{
	while(*head)
	{
		delNode(head, tail);
	}
}

void printCompList (compList* head)
{
	if(!head)
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	
	compList* temp = head;
	cout<<"head: ";
	
	while(temp)
	{
		cout<<"index: "<<temp->index<<", value: "<<temp->num<<endl;
		temp = temp->left;
	}
	
	cout<<"tail"<<endl;
}

void restoreCompList1 (compList** head, compList** tail)
{
	if(!(*head))
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	compList* temp = *head;
	int index = 1;
	
	compList* rhead = *head;
	compList* rtail = *tail;
	*head = NULL;
	*tail = NULL;
	
	while(temp)
	{
		if(temp->index > index)
		{
			addNode(head, tail, 0, index);
			index++;
		}
		else
		{
			addNode(head, tail, temp->num, index);
			index++;
			temp = temp->left;
		}
	}
	
	delList(&rhead, &rtail);
}

void restoreCompList2 (compList** head, compList** tail)
{
	if(!(*head))
	{
		cout<<"The list is empty"<<endl;
		return;
	}
	compList* temp = *head;
	int prevTemp = 0;
	
	compList* rhead = *head;
	compList* rtail = *tail;
	*head = NULL;
	*tail = NULL;
	
	while(temp)
	{
		for(int i = 1; i <= (temp->index - prevTemp - 1); i++)
		{
			addNode(head, tail, 0, prevTemp+i);
		}
		addNode(head, tail, temp->num, temp->index);

		prevTemp = temp->index;
		temp = temp->left;
	}
	
	delList(&rhead, &rtail);
}

int main()
{
	compList* head = NULL;
	compList* tail = NULL;
	printCompList(head);
	
	for(int i = 1; i < 11; i++)
	{
		addNode(&head, &tail, i, i*5);
	}
	printCompList(head);
	cout<<endl;
	restoreCompList1(&head, &tail);
	printCompList(head);
	cout<<endl;
	
	delList(&head, &tail);
	printCompList(head);
	cout<<endl;
	
	for(int i = 1; i < 11; i++)
	{
		addNode(&head, &tail, i, i*5);
	}
	printCompList(head);
	cout<<endl;
	restoreCompList2(&head, &tail);
	printCompList(head);
	cout<<endl;
}
