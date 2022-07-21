#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

static void max_heapify(int *array, int n, int i);
static void min_heapify(int *array, int n, int i);
static void swap(int *array, int i1, int i2);


void buildHeap(int *array, int n, int min_or_max)
{
    int start_index = (n/2) - 1;

    for(int i = start_index; i >= 0; i--)
    {
        printf("On %d\n", array[i]);
        printArray(array, n);
        if(min_or_max == 1){
            max_heapify(array, n, i);
        }else{
            min_heapify(array, n, i);
        }
    }
}

void printArray(int *array, int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d[%d] ", array[i],i);
    }
    printf("\n");

}

int pop(int *array, int n, int min_or_max)
{
    int num = array[0];
    array[0] = array[n-1];
    if(min_or_max == 1){
        max_heapify(array, n, 0);
    }else{
        min_heapify(array, n, 0);
    }
    return num;
}

static void max_heapify(int *array, int n, int i)
{
    int largest = i;
    int li = (2*i) + 1;
    int ri = (2*i) + 2;

    if(li < n && array[li] > array[largest]){
        largest = li;
    }
    
    if(ri < n && array[ri] > array[largest]){
        largest = ri;
    }

    if(largest != i){
        printf("swapping %d and %d\n" , array[i],array[largest]);
        swap(array, i, largest);
        max_heapify(array, n, largest);
    }
    
}

static void min_heapify(int *array, int n, int i)
{
    int smallest = i;
    int li = (2*i) + 1;
    int ri = (2*i) + 2;

    if(li < n && array[li] < array[smallest]){
        smallest = li;
    }
    
    if(ri < n && array[ri] < array[smallest]){
        smallest = ri;
    }

    if(smallest != i){
        printf("swapping %d and %d\n" , array[i],array[smallest]);
        swap(array, i, smallest);
        min_heapify(array, n, smallest);
    }
    
}

static void swap(int *array, int i1, int i2){
    int temp = array[i1];
    array[i1] = array[i2];
    array[i2] = temp;
}