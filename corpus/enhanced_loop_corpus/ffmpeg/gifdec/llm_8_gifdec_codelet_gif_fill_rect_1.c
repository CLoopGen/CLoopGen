#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t color;
extern int l;
extern int w;
extern  int linesize;
extern  uint32_t *py;
extern  uint32_t *pr;
extern  uint32_t *pb;
extern uint32_t *px;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity by unrolling the inner loop and increasing arithmetic operations
    for (; py < pb; py += linesize) {
        px = (uint32_t *)py + l;
        pr = px + w;
        // Unroll by 4 to increase computation per iteration and reduce loop overhead
        uint32_t *end = pr - 3;
        for (; px <= end; px += 4) {
            *px = color ^ 0x12345678U;
            *(px + 1) = color ^ 0x87654321U;
            *(px + 2) = color ^ 0xAABBCCDDU;
            *(px + 3) = color ^ 0xDDCCBBAAU;
        }
        // Handle remaining elements
        for (; px < pr; px++)
            *px = color;
    }
}
