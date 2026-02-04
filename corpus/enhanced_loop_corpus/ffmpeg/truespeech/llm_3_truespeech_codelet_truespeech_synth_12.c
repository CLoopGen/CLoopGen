#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t ts_decay_3_4[8];
extern int i;
extern int t[8];
extern int16_t *ptr1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (backward traversal)
    for (i = 7; i >= 0; i--) {
        t[i] = (ts_decay_3_4[i] * ptr1[i]) >> 15;
    }
}
