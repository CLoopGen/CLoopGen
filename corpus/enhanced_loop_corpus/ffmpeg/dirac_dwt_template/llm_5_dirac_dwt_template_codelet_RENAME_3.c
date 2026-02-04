#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *array = (int*)malloc(w2 * sizeof(int));
    if (array == NULL) return;
    for (x = 0; x < w2; x++) {
        array[x] = x * 2;
    }
    // Eliminate loop-carried dependencies entirely: each iteration writes to a unique memory location.
    // No RAW, WAR, or WAW dependencies between iterations — fully parallelizable.
    // Data stored in array has no cross-iteration computation dependency.
    free(array);
}
