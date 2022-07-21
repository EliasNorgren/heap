#include <stdio.h>
#include<stdlib.h>
#include "heap.h"

int main()
{  
    
    int n = 1000;
    //int temp[11] = {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    int temp[n];
    int *array = malloc(sizeof(int) * n);
    //for(int i = 0; i < n; i++){
      //  array[i] = temp[i];
    //}
    
    for(int i = 0; i < n; i++){
        array[i] = rand() % 10000;
    }

    //printArray(array, 11);
    //printf(" Before\n");

    buildHeap(array, n, 0);
    printArray(array, n);
    printf("Popping\n");

    for(int i = n; i >= 0; i--){
        temp[n-i] = pop(array, n, 0);
    }

    for(int i = 0; i < n; i++){
        if(i+1 < n && temp[i] > temp[i+1]){
            printf("FAIL");
            return 1;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d ", temp[i]);
    }
    printf("\n");
    

    free(array);
    return 0;
}