#include <iostream>

using namespace std;

/*Завдання
Для впорядкованого бінарного дерева:
 1. перевірити наявність вузла зі значенням N, та у випадку існування - знайти його глибину
 2. знайти висоту дерева
 3. знайти всі вершити, доступні з кореня, за N кроків*/

struct treeNode{
	int data;
	treeNode* right;
	treeNode* left;
};

treeNode* createNode(int num)
{
	treeNode* node = new treeNode;
	node->data = num;
	node->left = node->right = NULL;
}

void findNode(treeNode* parent, int num, int* level, bool* check){
	if (!parent)
	{
	    *check = false;
		return;
	}
		
	(*level) ++;	
		
	if (parent->data == num)
	{
	    *check = true;
	    cout<<"Parent-data: "<<parent->data<<"; level: "<<*level<<endl;
		return;
	}
	else
	{
		findNode(parent->left, num, level, check);
		if (!(*check))
			findNode(parent->right, num, level, check);
	}
	
	if (!(*check))
	{
		(*level)--;
		cout<<  "deLevel  "<<endl;
	}
		
	return;		
}

void checkHeight(treeNode* parent, int* level, int* height){ //counting parent of the tree as 1
	if (!parent)
	{
	    if(*level > *height)
	    {
		    *height = *level;
	    }
	    return;
    }   
		
	(*level)++;	
	
	checkHeight(parent->left, level, height);
	checkHeight(parent->right, level, height);
	
	
	(*level)--;
		
	return;		
}

void nodesOnNLevel(treeNode* parent, int numL, int* level, bool* check){
	if (!parent)
	{
		(*level) ++;
		return;
	}
		
	(*level) ++;	
		
	if (*level == numL)
	{
	    cout<<"Parent-data: "<<parent->data<<"; Level: "<<*level<<endl;
		return;
	}
	else if(*level < numL)
	{
		nodesOnNLevel(parent->left, numL, level, check);
		(*level)--;
		nodesOnNLevel(parent->right, numL, level, check);
		(*level)--;
	}
		
	return;		
}

void addNode (treeNode* parent, int num)
{
	if(num < parent->data)
	{
		if(parent->left)
		{
			addNode(parent->left, num);
		}
		else
		{
			parent->left = createNode(num);
		}
	}
	else
	{
		if(parent->right)
		{
			addNode(parent->right, num);
		}
		else
		{
			parent->right = createNode(num);
		}
	}
}

void printTree(treeNode* parent)
{
	if(!parent)
	{
		return;
	}
	
	printTree(parent->left);
	cout<<parent->data<<"; ";
	printTree(parent->right);
}

int main(){
	
	int arr[] = {7,10,12,2,5,1,8,0,9,4,15,3,13,19,20};
	
	treeNode* root  = new treeNode;
	root->data = arr[0];
	root->left = root->right = NULL;
	
	for (int i = 1; i < 15; i++)
		addNode(root, arr[i]);
	
	printTree(root);
	cout << endl;
	
	int level = 0;
	int height = 0;
	checkHeight(root, &level, &height);
	
	cout<<"Height: "<<height<<endl;
	cout<<endl;
	
	bool check = false;
	level = 0;
	findNode(root, arr[0], &level, &check);
	
	check = false;
	level = 0;
	findNode(root, arr[5], &level, &check);
	cout<<endl;
	
	for(int i = 1; i < 7; i++)
	{
	    check = false;
	    level = 0;
	    nodesOnNLevel(root, i, &level, &check);
	    cout<<endl;
	}

	return 0;
}
