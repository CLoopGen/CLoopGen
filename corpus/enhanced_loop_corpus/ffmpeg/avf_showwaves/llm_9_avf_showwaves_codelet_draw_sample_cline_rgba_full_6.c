#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *buf;
extern int linesize;
extern  uint8_t color[4];
extern int k;
extern  int start;
extern  int end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations using pointer arithmetic and loop strength reduction
    // Precompute base pointer and increment by linesize to eliminate multiplication
    uint8_t *ptr = &buf[start * linesize];
    int i;
    for (i = start; i < end; i++) {
        ptr[0] = color[0];
        ptr[1] = color[1];
        ptr[2] = color[2];
        ptr[3] = color[3];
        ptr += linesize; // Move to next row
    }
}
