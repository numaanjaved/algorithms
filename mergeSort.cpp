#include<iostream>
using namespace std;

void merge(int array[], int left, int mid, int right){
    if(left < right){
        cout << endl;
        cout << "left = " << left << endl;
        cout << "right = " << right << endl;
        cout << "mid = " << mid << endl;

        int leftArrayLength = mid - left + 1;
        int rightArrayLength = right - mid;
        cout << "LeftArray length = " << leftArrayLength << endl;
        cout << "Right Array length = " << rightArrayLength << endl;
        int *leftArray = new int[leftArrayLength];
        int *rightArray = new int[rightArrayLength];   
        
        for(int i = 0; i < leftArrayLength; ++i){
            leftArray[i] = array[left + i];
        }
        for(int i = 0; i < rightArrayLength; ++i){
            rightArray[i] = array[mid + i + 1];
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

}
void mergeSort(int array[], int begin, int end){  
    if(begin >= end){
        return;
    }
    int mid = (begin + (end - begin))/2;     
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, mid, end);        
    
}
int main(){
    int array[2] = { 10, 5};
    mergeSort(array, 0, 2);

    for(int i = 0; i < 2; ++i){
        cout << array[i];
    }
    return 0;
}