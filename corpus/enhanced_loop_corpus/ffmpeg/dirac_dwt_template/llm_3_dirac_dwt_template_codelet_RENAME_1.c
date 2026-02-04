#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with reverse traversal
    // Simulate traversing an array in reverse order consecutively
    int *arr = (int*)malloc(w2 * sizeof(int));
    if (arr == NULL) return;
    for (x = w2 - 1; x >= 0; x--) {
        arr[x] = x; // Consecutive write in reverse: w2-1, w2-2, ..., 0
    }
    free(arr);
}
