#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *arr = (int*)malloc(h * sizeof(int));
    if (arr == NULL) return;
    for (i = 0; i < h; i++) {
        arr[i] = i * 2;
    }
    // Removes loop-carried data dependencies by writing to distinct memory locations (no reuse of same element)
    // Introduces memory-level parallelism with independent writes (RAW/WAR/WAW avoided across iterations)
    free(arr);
}
