#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint16_t *src;
extern  uint16_t *f1;
extern  uint16_t *f2;
extern uint16_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (access arrays from end to start)
    for (int x = w - 1; x >= 0; x--) {
        dst[x] = ((src[x] - f2[x]) >= 0 ? (src[x] - f2[x]) : (-(src[x] - f2[x]))) > 
                 ((src[x] - f1[x]) >= 0 ? (src[x] - f1[x]) : (-(src[x] - f1[x]))) ? f2[x] : f1[x];
    }
}
