#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t src_size1;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t *array = (uint64_t*)malloc(src_size1 * sizeof(uint64_t));
    if (!array) return;
    for (i = 0; i < src_size1; i++) {
        array[i] = i + 1; // WAW dependency: each write to array[i] is independent
    }
    for (i = 1; i < src_size1; i++) {
        array[i] += array[i-1]; // RAW dependency: loop-carried, each iteration depends on previous
    }
    free(array);
}
