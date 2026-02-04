#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern
    // Simulate array access with stride of 2 using index manipulation
    int *arr = (int*)malloc(w2 * 2 * sizeof(int)); // Allocate extra space for strided access
    if (arr == NULL) return;
    for (x = 0; x < w2; x += 2) {
        arr[x * 2] = x; // Strided write access: indices 0, 4, 8, ...
    }
    free(arr);
}
