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
    // Eliminate loop-carried dependencies entirely: each iteration writes to a unique memory location.
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable.
    free(arr);
}
