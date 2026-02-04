#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t size1;
extern  size_t size2;
extern size_t i;
extern size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t* buffer = (int64_t*)malloc(size1 * sizeof(int64_t));
    if (!buffer) return;

    for (i = 0; i < size1; i++) {
        buffer[i] = i + 1; // Write to distinct memory location - no loop-carried dep
        for (j = 0; j < size2; j++) {
            buffer[i] *= 2; // WAW dependence removed by privatizing per 'i'
        }
    }

    free(buffer);
}
