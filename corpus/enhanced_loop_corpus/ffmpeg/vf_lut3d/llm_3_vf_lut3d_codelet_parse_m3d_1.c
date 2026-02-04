#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int size;
extern int in;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(sizeof(int) * (in + 10));
    for (size = 1; size * size * size < in; size++) {
        arr[size - 1] = size; // Consecutive write access into array
    }
    free(arr);
}
