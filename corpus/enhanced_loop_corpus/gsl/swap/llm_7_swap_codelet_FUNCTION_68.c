#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t K;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t* buffer = (uint64_t*) malloc(K * sizeof(uint64_t));
    if (buffer == NULL) return;
    for (i = 0; i < K; i++) {
        buffer[i] = i > 0 ? buffer[i-1] + i : 0;
        // Introduce a true read-after-write (RAW) loop-carried dependency
    }
    free(buffer);
}
