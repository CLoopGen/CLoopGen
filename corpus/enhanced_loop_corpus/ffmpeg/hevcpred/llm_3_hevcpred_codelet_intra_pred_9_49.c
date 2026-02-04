#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int size;
extern ptrdiff_t stride;
extern uint16_t *src;
extern uint16_t *left;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided output with consecutive input access
    uint16_t *src_consec = src - 1;
    for (i = 0; i < size; i++) {
        left[stride * i] = src_consec[i];
    }
}
