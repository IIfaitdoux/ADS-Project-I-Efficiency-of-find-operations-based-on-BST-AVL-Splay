#include "testmode.h"
#include <time.h>
//increasing order:0,1,2,...,n-1//
int* make_increasing_order(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[i] = i;
    }
    return arr;
}
//decreasing order:n-1,n-2,...1,0//
int* make_decreasing_order(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[n - 1 - i] = i;
    }
    return arr;
}
//random order//
int* make_random_order(int n) {
    srand(time(NULL));
    //first create an increasing array//
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[i] = i;
    }
    //random choose an element from 0th to i-1th,swap it with ith element
    for (int i = n - 1; i > 0; i -= 1) { 
        int index = rand() % i;
        int tem = arr[i];
        arr[i] = arr[index];
        arr[index] = tem;
    }
    return arr;
}
//according to insert & delete ways to choose insert order//
int* insert_order(int n, int testmode) {
    switch (testmode)
    {
    case 0:
        return make_increasing_order(n);
        break;
    case 1:
        return make_increasing_order(n);
        break;
    case 2:
        return make_random_order(n);
        break;
    default:
        return NULL;
    }
}
//according to insert & delete ways to choose delete order//
int* delete_order(int n, int testmode) {
    switch (testmode)
    {
    case 0:
        return make_increasing_order(n);
        break;
    case 1:
        return make_decreasing_order(n);
        break;
    case 2:
        return make_random_order(n);
        break;
    default:
        return NULL;
    }
}