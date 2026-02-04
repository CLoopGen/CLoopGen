#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t1;
extern int half_size;
extern  uint8_t *t2;
extern uint8_t *s;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indexing (instead of pointer arithmetic)
    for (i = 0; i < half_size; i++) {
        s[2*i]     = t1[i];
        s[2*i + 1] = t2[i];
    }
}
