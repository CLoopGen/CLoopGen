#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned int shift;
extern uint32_t *src32;
extern  uint32_t mask;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint32_t *ptr = src32;
    for (i = 0; i < len; i += 8) {
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
        *ptr = (*ptr << shift) & mask; ptr++;
    }
}
