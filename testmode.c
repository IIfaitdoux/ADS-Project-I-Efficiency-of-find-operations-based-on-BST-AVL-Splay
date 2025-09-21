#include "testmode.h"
#include <time.h>

int* make_increasing_order(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[i] = i;
    }
    return arr;
}

int* make_decreasing_order(int n) {
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[n - 1 - i] = i;
    }
    return arr;
}

int* make_random_order(int n) {
    srand(time(NULL));
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i += 1) {
        arr[i] = i;
    }
    for (int i = n - 1; i > 0; i -= 1) { 
        int index = rand() % i;
        int tem = arr[i];
        arr[i] = arr[index];
        arr[index] = tem;
    }
    return arr;
}

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