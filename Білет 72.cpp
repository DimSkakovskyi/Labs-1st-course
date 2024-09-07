#include<iostream>

using namespace std;

struct Tree{
	int num;
	Tree* left;
	Tree* right;
};

struct List{
	int num;
	int index;
	List* left;
	List* right;
};

bool FindPoint (Tree* root, int num, int* height)
{
	if(!root)
	{
		return false;
	}
	(*height)++;
	bool check = false;
	if(root->num == num)
	{
		cout<<"Number: "<<root->num<<" and level "<<(*height)<<endl;
		check = true;
	}
	else
	{
		check = FindPoint(root->left, num, height);
		if(!check)
		{
			check = FindPoint(root->right, num, height);
		}
	}
	if(!check)
	{
		(*height)--;
	}
	return check;
}

void addNodeEasy (List** head, List** tail, int num)
{
	if((*head)==NULL)
	{
		(*head) = new List;
		(*head)->num;
		(*head)->left = NULL;
		(*head)->right = NULL;
		(*tail) = (*head);
	}
	
    List* temp = new List;
    temp->num = num;
    temp->left = (*tail);
    temp->right = NULL;
    (*tail)->right = temp;
    (*tail) = temp;
}

void showList (List** head)
{
	List* current = *head;
	while(current)
	{
		cout<<current->num<<" ";
		current = current->right;
	}
}

void delZeroes (List** head, List** tail)
{
	if((*head)==NULL)
	{
		cout<<"The list is empty!"<<endl;
		return;
	}
	
	List* start = (*head);
	
	while(*head)
	{
		if((*head)->num == 0)
		{
			List* temp = (*head);
			if((*head)->left == NULL)
			{
				start = (*head)->right;
				(*head) = (*head)->right;
				(*head)->left = NULL;
				delete temp;
			}
			else if((*head)->right == NULL)
			{
				(*tail) = (*tail)->left;
				(*tail)->right = NULL;
				(*head) = (*tail);
				delete temp;
			}
			else
			{
				(*head)->right->left = (*head)->left;
				(*head)->left->right = (*head)->right;
				(*head) = (*head)->right;
				delete temp;
			}
		}
		else
		{
			(*head) = (*head)->right;
		}
	}
	
	(*head) = start;
}

int main()
{
	List* head = NULL;
	List* tail = NULL;
	
	for(int i = 1; i < 7; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			addNodeEasy(&head, &tail, 0);
		}
		addNodeEasy(&head, &tail, i);
	}
	
	showList(&(head->right));
	
	delZeroes(&head, &tail);
	
	showList(&(head->right));
}
