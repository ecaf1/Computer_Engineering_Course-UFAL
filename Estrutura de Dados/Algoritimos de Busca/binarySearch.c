#include <stdio.h>

int binarySearch(int *array, int size, int value){
    int left = 0;
    int right = size -1;
    while(left <= right){
        int mid = (left + right)/2;
        if(array[mid] == value){
            return mid;
        }
        if(array[mid] < value){
            left = mid +1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}


int main(){
    int test[] = {1,2,3,4,5};
    int *pont = test;
    int resu = binarySearch(pont, 5, 2);
    printf("%d", resu);
    return 0;
}