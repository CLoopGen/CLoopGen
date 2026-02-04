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
    int local_x = x + i * stride; // Remove loop-carried dependency on x by computing directly
    for (i = 0; i < r; i++) {
        int offset_index = (local_x + i * stride) / (bits == 8 ? 1 : 2);
        if (bits == 8) {
            ((uint8_t *)(dst))[offset_index] = Ra;
        } else {
            ((uint16_t *)(dst))[offset_index] = Ra;
        }
    }
}
