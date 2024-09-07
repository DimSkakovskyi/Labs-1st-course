#include <iostream>
#include <math.h>
using namespace std;

int* convertToArray ( long num )
{
	int* arr = new int[1000];
	int counter = 0;
	while ( num != 0)
	{
		arr[counter+1] = num%10;
		num /= 10;
		counter++;
	}
	arr[0] = counter;
	
	return arr;
}

bool checkPalindrom ( long num )
{
	int* arr = convertToArray(num);
	bool Palindrome = true;
	
	int halfLength = arr[0] / 2;
    if(arr[0]%2 != 0){
        halfLength++;
    }
    for(int i = 0; i < halfLength; i++){
        if(arr[i+1] != arr[arr[0]-i]){
            Palindrome = false;
            return Palindrome;
        }
    }
    return Palindrome;
}

void task1 ( int N )
{
	int NumbersArray[N];
	cout << "Task1"<<endl;
    int indexLength = 0;
    for (int i = 1; i <= N; i++){
        if(!checkPalindrom(i)){
            continue;
        }
        int SqrNum = pow(i, 2);
        if(checkPalindrom(SqrNum)){
            NumbersArray[indexLength] = i;
            indexLength++;
        }
    }
    for(int k=0; k<indexLength; k++){
        cout << NumbersArray[k] << endl;
    }
}

void task2( int arr[][4], int n)
{
	int vector[2*n - 1];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			vector[i+j] += arr[i][j];
		}
	}
	
	cout<<"Task2"<<endl;
	for(int i = 0; i < 2*n - 1; i++)
	{
		cout<<vector[i]<<" "; 
	}
	cout<<endl;
}

void task3( char cstring[] )
{
	int wordsCounter = 0;
	if (cstring[0] != ' ')
	{
		wordsCounter++;
	}
	for( int i = 0; cstring[i+1] != '\0' ; i++ )
	{
		if( cstring[i] == ' ' and cstring[i+1] != ' ' )
		{
			wordsCounter++;
		}
	}
	cout<<"Task3"<<endl<<"Number of words: "<<wordsCounter<<endl;
}

int main()
{
	task1(100);
	
	int n = 4;
	int Aarray[4][4];
	for (int i = 0; i < n; i++)
	{
		for (int j =0; j < n; j++)
		{
			Aarray[i][j] = 1;
		}
	}
	task2(Aarray, n);
	
	char cstring[] = "You have power over your mind — not outside events. Realize this, and you will find strength.";
	task3(cstring);

    return 0;
}
