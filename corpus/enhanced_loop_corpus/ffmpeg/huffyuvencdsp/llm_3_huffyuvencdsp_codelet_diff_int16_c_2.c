#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern int w;
extern long i;
extern unsigned long pw_lsb;
extern unsigned long pw_msb;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive half-width access using uint16_t instead of long, processing each 16-bit element
    for (i = 0; i < w; i++) {
        uint16_t a = src1[i];
        uint16_t b = src2[i];
        dst[i] = ((a | (uint16_t)pw_msb) - (b & (uint16_t)pw_lsb)) ^ ((a ^ b ^ (uint16_t)pw_msb) & (uint16_t)pw_msb);
    }
}
