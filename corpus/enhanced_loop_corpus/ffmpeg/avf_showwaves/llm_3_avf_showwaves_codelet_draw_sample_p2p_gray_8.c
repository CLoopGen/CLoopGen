#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern int start;
extern int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Memory Access with Offset Unrolling
    // Reinterpret the buffer as a linear array and perform consecutive writes
    // by precomputing the target addresses in a sequential pattern
    uint8_t *ptr = &buf[(start + 1) * linesize];
    int distance = end - start - 1;
    for (k = 0; k < distance; k++)
        ptr[k * linesize] += color[0];
}
