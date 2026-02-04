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
    // Variant 1: Strided memory access with stride of 2 (forward wrapping via modulo)
    for (i = 0; i < 8; i++) {
        int idx = (i * 2) % 8;  // Strided access: 0, 2, 4, 6, 0, 2, 4, 6
        t[idx] = (ts_decay_3_4[idx] * ptr1[idx]) >> 15;
    }
}
