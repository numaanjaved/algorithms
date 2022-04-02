#include<iostream>
#include<algorithm>
using namespace std;

void swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void heapify(int array[], int i, int m){    
    int indexLeft = 2*i;
    int indexRight = indexLeft + 1;
    int max = i;
    if(indexLeft < m && array[indexLeft] > array[max]){
        cout << "root = " << i << endl;
        cout << "left = " << array[indexLeft] << " right = " << array[indexRight] << endl;
        cout << "max = " << max << endl;
        max = indexLeft;
        cout << "root = " << i << endl;
        cout << "left = " << array[indexLeft] << " right = " << array[indexRight] << endl;
        cout << "max = " << max << endl;
    }
    if(indexRight < m && array[indexRight] > array[max]){
        max = indexRight;
    }
    if(max != i){
        swap(array[i], array[max]);
        cout << "root = " << array[i] << endl;
        cout << "left = " << array[indexLeft] << " right = " << array[indexRight] << endl;
        cout << "max = " << array[max] << endl;
        heapify(array, max, m);
    }
};
void buildHeap(int array[], int n){
    for(int i = n/2; i > 0; --i){
        heapify(array, i, n);
    }
}
void heapSort(int array[], int n){
    buildHeap(array, n);
    int m = n;
    while(m >= 2){
        swap(array[1], array[m]);
        m = m - 1;
        heapify(array, 1, m);
    }
}
int main(){
    int n = 8;
    int array[n] = {5,9,2,6,4,1,3,7};
    buildHeap(array, n);
    // heapSort(array, n);

    for(int i = 0; i < n; ++i){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}