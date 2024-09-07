#include<iostream>

using namespace std;

/*Завдання.Реалізувати циклічний список та такі функції : додавання (з хвоста),
видалення (з голови), виведення списку в консоль, видалення всього списку*/

struct CycleList
{
	int num;
	CycleList* left; 
	CycleList* right;
};

void addNode (CycleList** head, CycleList** tail, int n)
{
	if(*head == NULL)
	{
		*head = new CycleList;
		(*head)->num = n;
		(*head)->left = *head;
		(*head)->right = *head;
		*tail = *head;
		return;
	}
	
	CycleList* temp = new CycleList;
	temp->num = n;
	(*tail)->left = temp;
	(*head)->right = temp;
	temp->right = *tail;
	temp->left = *head;
	*tail = (*tail)->left;
}

void delNode (CycleList** head, CycleList**tail)
{
	if(head == NULL)
	{
		cout<<"The list is empty"<<endl;;
		return;
	}
	
	
	if(*head == *tail)
	{
		CycleList* temp = *head;
		*tail = NULL;
		*head = NULL;
	    delete temp;
	    return;
	}
	
	CycleList* temp = *head;
	*head = (*head)->left;
	(*head)->right = *tail;
	(*tail)->left = *head;
	delete temp;
}

void delList(CycleList** head, CycleList** tail)
{
	while(*head)
	{
		delNode(head, tail);
	}
}

void printList (CycleList* head)
{
	if(head == NULL)
	{
		cout<<"The list is empty"<<endl;;
		return;
	}
	
	CycleList* temp = head;
	
	do {
		cout<<temp->num<<endl;
		temp = temp -> left;
	} while (temp != head);
}

void task2 (CycleList** head, CycleList** tail)
{
	if(head == NULL)
	{
		cout<<"The list is empty"<<endl;;
		return;
	}
	
	CycleList* h1 = NULL;
	CycleList* t1 = NULL;
	CycleList* h2 = NULL;
	CycleList* t2 = NULL;
	
	CycleList* temp = *head;
	
	do {
		if(temp->num %2 == 0)
		{
			addNode(&h1, &t1, temp->num);
		}
		else
		{
			addNode(&h2, &t2, temp->num);
		}
		
		temp = temp->left;
	} while (temp != *head);
	
	delList(head, tail);
	
	cout<<"Even numbers: "<<endl;
	printList(h1);
	cout<<"Odd numbers: "<<endl;
	printList(h2);
}

int main()
{
	CycleList* head = NULL;
	CycleList* tail = NULL;
	
	printList(head);
	
	addNode(&head, &tail, 7);
	addNode(&head, &tail, 5);
	addNode(&head, &tail, 3);
	addNode(&head, &tail, 2);
	addNode(&head, &tail, 8);
	addNode(&head, &tail, 4);
	printList(head);
	
	cout<<endl;
	delNode(&head, &tail);
	printList(head);
	
	cout<<endl;
	task2(&head, &tail);
	
	cout<<endl;
	delList(&head, &tail);
	printList(head);
}
