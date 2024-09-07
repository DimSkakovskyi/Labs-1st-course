#include <iostream>
#include <cmath>
using namespace std;

/*
1. - сортування (вибором), можна з використанням додаткового булевого масиву (select sort)
2 - структура на декартову систему + структура на декартову систему + ф-я перетворення з вікі
3 - проходження по рядку з початку в кінець по парним індексам і назад по непарним*/

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectSort(double A[], int I[], int n){

    for(int i = 0; i < n-1; i++){
        int idMin = i;
        for(int k = i+1; k < n; k++){
            if (A[I[idMin]] > A[I[k]]){
                idMin = k;
            }
        }
        if(idMin!=i){
            swap(I[i], I[idMin]);
        }

    }
}

void task1(double A[], int n) {

    int I[n];

    for (int i = 0; i < n; ++i) {
        I[i] = i;
    }
    selectSort(A, I, n);

    cout << "Task 1"<<endl<<"Index array: ";
    for (int i = 0; i < n; ++i) {
        cout << I[i] << " ";
    }
    cout <<endl;
}

struct DecartPoint{
    float x;
    float y;
    void print(){
        cout << "Decart point"<<endl<<"x: " << x << "; y: " << y << ";"<<endl;
    }
};

struct PolarPoint{
    float r;
    float deg;
    void print(){
        cout << "Polar point"<<endl<<"radius: " << r << "; degree: " << deg << ";"<<endl;
    }
};


void task2(DecartPoint point){
    cout << "Task 2"<<endl;
    point.print();

    PolarPoint polarPoint;
    polarPoint.r = sqrt(pow(point.x, 2) + pow(point.y, 2));
    polarPoint.deg = atan(point.y/point.x);

    polarPoint.print();

}

void task3(char cstring[], int n){
    int evenLength = n/2;
    int oddLength = (n/2) + (n%2);


    char even_chars[evenLength];
    char odd_chars[oddLength];

    int even_count = 0;
    int odd_count = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            odd_chars[even_count++] = cstring[i];
        } else {
            even_chars[odd_count++] = cstring[i];
        }
    }

    int index = 0;

    for (int i = 0; i < evenLength; ++i) {
        cstring[index++] = even_chars[i];
    }
    for (int i = oddLength - 1 ; i >= 0; --i) {
        cstring[index++] = odd_chars[i];
    }


}

int main() {

    //task1
    double A[] = { 1.0, 3.14, 2.5, 0.5, 0.5, 200};
    int len = 6;
    task1(A, len);

    //task2
    DecartPoint point = {1,1};
    task2(point);

    //task3
    char cstring[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'z'};
    int stringLen = 8;
    task3(cstring, stringLen);
    cout << "Task 3"<<endl<< cstring;

    return 0;
}
