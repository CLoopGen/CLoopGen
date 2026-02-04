#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *p;
extern int buf_size;
extern int cc_count;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (unrolled stride of 1 instead of 6)
    for (i = 5; i + 1 < buf_size && ((p[i] & 254) == 254); i++)
        cc_count++;
}
