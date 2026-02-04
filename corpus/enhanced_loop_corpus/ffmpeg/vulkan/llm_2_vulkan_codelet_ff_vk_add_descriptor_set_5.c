#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(num * sizeof(int));
    for (int i = 0; i < num; i++) {
        arr[i] = i; // Consecutive memory access: writing to adjacent array elements
    }
    free(arr);
}
