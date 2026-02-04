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
for (i = 0; i < (r + 1) / 2; i++) {
    int offset = x + i * stride;
    (bits == 8 ? (((uint8_t *)(dst))[offset] = Ra) : (((uint16_t *)(dst))[offset] = Ra));
    if (i * 2 + 1 < r) {
        offset = x + (i * 2 + 1) * stride;
        (bits == 8 ? (((uint8_t *)(dst))[offset] = Ra) : (((uint16_t *)(dst))[offset] = Ra));
    }
}
}
