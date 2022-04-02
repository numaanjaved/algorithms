#include<iostream>
#include<cmath>
#include<time.h>

int choosePivot(int array[], int p, int r){
    int size = r - p;
    srand(time(0));
    int output = rand() / size;
    return output;
}
int select(int array[], int p, int r, int k){
    if(p == r){
        return array[p];
    }
    else{
        int x = choosePivot(array, p, r);
        int q = partition(array, p, r, x);
        int rankX = q - p + 1;

        if(k == rankX){
            return x;
        }
        else if(k < rankX){
            return select(array, p, q-1, k);
        }
        else{
            return select(array, q+1, r, k);
        }
    }

}

int main(){
    int array[8] = {5,9,2,6,4,1,3,7};
    

    return 0;
}