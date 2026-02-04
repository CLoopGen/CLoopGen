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
    for (i = 0; i < r; i += 2) {
        if (bits == 8) {
            ((uint8_t *)(dst))[x] = Ra;
            if (i + 1 < r) ((uint8_t *)(dst))[x + stride] = Ra;
        } else {
            ((uint16_t *)(dst))[x] = Ra;
            if (i + 1 < r) ((uint16_t *)(dst))[x + stride] = Ra;
        }
        x += 2 * stride;
    }
}
