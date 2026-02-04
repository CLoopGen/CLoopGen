#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint8_t *src;
extern uint8_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base pointer and using direct sequential indexing
    uint8_t *src_base = src - 1;
    for (i = 0; i < size; i++) {
        left[i] = src_base[stride * i];
    }
}
