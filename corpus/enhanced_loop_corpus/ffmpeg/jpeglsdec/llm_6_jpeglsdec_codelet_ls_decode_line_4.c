#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *dst;
extern int stride;
extern int bits;
extern int i;
extern int x;
extern int Ra;
extern int r;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = Ra;
    for (i = 0; i < r; i++) {
        temp += i; // Introduce loop-carried dependency on temp
        (bits == 8 ? (((uint8_t *)(dst))[x] = temp) : (((uint16_t *)(dst))[x] = temp));
        x += stride;
        temp = temp & 0xFF; // Maintain bounded value for realism
    }
}
