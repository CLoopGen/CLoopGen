#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(x * sizeof(int));
    for (h = 0; h < x; h++) {
        arr[h] = h; // Consecutive memory access
    }
    free(arr);
}
