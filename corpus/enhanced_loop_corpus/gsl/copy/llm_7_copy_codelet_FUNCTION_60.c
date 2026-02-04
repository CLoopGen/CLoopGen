#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t M;
extern  size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile int64_t *array = (volatile int64_t*)malloc(((M) < (N) ? (M) : (N)) * sizeof(int64_t));
    size_t limit = (M < N) ? M : N;
    for (i = 0; i < limit; i++) {
        array[i] = i;  // Write access - introduces potential WAW if reused
        if (i > 0) {
            array[i] += array[i-1];  // RAW dependency: current depends on previous
        }
    }
    free((void*)array);
}
