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
        if (bits == 8) {
            ((uint8_t *)(dst))[x] = temp;
        } else {
            ((uint16_t *)(dst))[x] = temp;
        }
        temp = temp + 1; // Introduce WAW dependency: each iteration writes updated temp used in next
        x += stride;
    }
}
