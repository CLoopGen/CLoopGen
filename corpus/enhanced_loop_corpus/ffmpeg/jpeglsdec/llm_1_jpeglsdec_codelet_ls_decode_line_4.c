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
    if (r > 0) {
        i = 0;
        do {
            (bits == 8 ? (((uint8_t *)(dst))[x] = Ra) : (((uint16_t *)(dst))[x] = Ra));
            x += stride;
            i++;
        } while (i < r);
    }
}
