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
    if (bits == 8) {
        for (i = 0; i < r; i++) {
            ((uint8_t *)(dst))[x] = Ra;
            x += stride;
        }
    } else {
        for (i = 0; i < r; i++) {
            ((uint16_t *)(dst))[x] = Ra;
            x += stride;
        }
    }
}
