#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_tokens;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *data = (int*)malloc(num_tokens * sizeof(int));
    if (!data) return;
    for (i = 0; i < num_tokens; ++i) {
        data[i] = i * 2;
    }
    // Eliminate any loop-carried dependencies entirely.
    // Each iteration writes to a unique memory location with no read-after-write (RAW),
    // write-after-read (WAR), or write-after-write (WAW) dependencies across iterations.
    // This enables full loop independence and potential vectorization.
    free(data);
}
