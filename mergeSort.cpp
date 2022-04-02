#include<iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){

    const int leftArrayLength = mid - left + 1;
    const int rightArrayLength = right - mid;
    int leftArray[leftArrayLength];
    int rightArray[rightArrayLength];   
    
    for(int i = 0; i < leftArrayLength; ++i){
        leftArray[i] = array[left + i];
    }
    for(int j = 0; j < rightArrayLength; ++j){
        rightArray[j] = array[mid + j + 1];
    }
    int indexOfLeftArray = 0;
    int indexOfRightArray = 0;
    int indexOfMergedArray = left;

    while(indexOfLeftArray < leftArrayLength && indexOfRightArray < rightArrayLength){
        if(leftArray[indexOfLeftArray] < rightArray[indexOfRightArray]){
            array[indexOfMergedArray] = leftArray[indexOfLeftArray];
            ++indexOfLeftArray;
        }
        else{
            array[indexOfMergedArray] = rightArray[indexOfRightArray];
            ++indexOfRightArray;
        }
        ++indexOfMergedArray;
    }
    while(indexOfLeftArray < leftArrayLength){
        array[indexOfMergedArray] = leftArray[indexOfLeftArray];
        ++indexOfLeftArray;
        ++indexOfMergedArray;
    }
    while(indexOfRightArray < rightArrayLength){
        array[indexOfMergedArray] = rightArray[indexOfRightArray];
        ++indexOfRightArray;
        ++indexOfMergedArray;
    }

}
void mergeSort(int array[], int begin, int end){  
    cout << "begin : "<< begin << endl;
    cout << "end : "<< end << endl;
    for(int i = 0; i < (sizeof(&array)/sizeof(array[0])); ++i){
        cout << array[i] << endl;
    }
    if(begin < end){
        int mid = (begin + end)/2;     
        mergeSort(array, begin, mid);
        mergeSort(array, mid+1, end);
        merge(array, begin, mid, end);        
    }
}
int main(){
    int array[3] = { 10, 5, 4};
    mergeSort(array, 0, 3);

    for(int i = 0; i < 3; ++i){
        cout << array[i];
    }
    return 0;
}