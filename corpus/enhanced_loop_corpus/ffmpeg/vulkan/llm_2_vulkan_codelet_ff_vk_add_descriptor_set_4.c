#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access pattern using a local array
    int *arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        arr[i] = i;  // Writing consecutively to adjacent memory locations
    }
    free(arr);
}
