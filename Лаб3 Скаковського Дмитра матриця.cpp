#include <iostream>

using namespace std;

/*Для розрідженої матриці M x N (розмір будь який) побудувати стисле індексне представлення / список (якщо строго, там стек стеків)*/

const int rows = 5;
const int cols = 5;

struct columnNode{
	int num;
	int index;
	columnNode* next;
};

struct rowNode{
	int index;
	rowNode* next;
	columnNode* right;
};

struct matrixList{
	rowNode* head;
	rowNode* tail;
};

void addRow (rowNode** head, rowNode** tail, int index)
{
	if(!(*head))
	{
		*head = new rowNode;
		*tail = *head;
		(*head)->index = index;
		(*head)->next = NULL;
		(*head)->right = NULL;
		return;
	}
	
	rowNode* temp = new rowNode;
	temp->index = index;
	temp->next = *head;
	temp->right = NULL;
	*head = temp;
}

void addColumn(rowNode** head, int indexR, int indexCol, int n)
{
	rowNode* temp = *head;
	while(temp)
	{
		if(temp->index == indexR)
		{
			columnNode* tempCol = new columnNode;
			tempCol->index = indexCol;
			tempCol->num = n;
			tempCol->next = NULL;
			
			columnNode* currentCol = temp->right;
			
			do
			{
				if(currentCol != NULL)
				{
					if(currentCol->next == NULL)
					{
						currentCol->next = tempCol;
						return;
					}
					else
					{
						currentCol = currentCol->next;
					}
				}
				else
				{
					temp->right = tempCol;
					return;
				}
			}while(currentCol);
		}
		else
		{
			temp = temp->next;
		}
	}
}

matrixList* makeMList(int array[rows][cols], int m, int n)
{
	rowNode* head = NULL;
	rowNode* tail = NULL;
	for(int i = m-1; i >= 0; i--)
	{
		addRow(&head, &tail, i);
		for(int j = n-1; j >= 0; j--)
		{
			if(array[i][j] != 0)
			{
				addColumn(&head, i, j, array[i][j]);
			}
		}
	}
	
	matrixList* matrix = new matrixList;
	matrix->head = head;
	matrix->tail = tail;
	
	return matrix;
}

void printMatrix (rowNode* head)
{
    rowNode* current = head;
	if(!current)
	{
		cout<<"The list is empty!"<<endl;
	}
	while(current)
	{
		cout<<"Row: "<<current->index<<endl;
		columnNode* temp = current->right;
		if(!temp)
		{
			cout<<"There is no elements!"<<endl;
		}
		else
		{
			while(temp)
			{
				cout<<"Column: "<<temp->index<<", value: "<<temp->num<<endl;
				temp = temp->next;
			}
		}
		current = current->next;
		cout<<"Next!"<<endl;
	}
}

int main()
{
	int arr[5][5] = {
            {1, 0, 0, 0, 1},
            {0, 2, 0, 4, 0},
            {6, 5, 0, 1, 0},
            {0, 0 , 3, 0, 0},
            {0, 0, 1, 2, 0}
    };
    
    matrixList* result = makeMList(arr, 5, 5);
    printMatrix(result->head);
}
