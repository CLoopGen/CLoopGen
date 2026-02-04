#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src1;
extern  uint16_t *src2;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Consecutive forward traversal using pointer arithmetic for tighter memory access
    uint16_t *d = dst;
    uint16_t *s1 = src1;
    uint16_t *s2 = src2;
    for (i = 0; i + 3 < w; i += 4) {
        d[0] = (s1[0] - s2[0]) & mask;
        d[1] = (s1[1] - s2[1]) & mask;
        d[2] = (s1[2] - s2[2]) & mask;
        d[3] = (s1[3] - s2[3]) & mask;
        d += 4;
        s1 += 4;
        s2 += 4;
    }
}
