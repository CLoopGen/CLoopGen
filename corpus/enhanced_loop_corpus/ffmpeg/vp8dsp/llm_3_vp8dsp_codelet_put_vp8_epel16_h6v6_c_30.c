#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use consecutive memory layout by preloading a local buffer to change access pattern
uint8_t local_src[20]; // Extended to cover required neighborhood
for (y = 0; y < h + 6 - 1; y++) {
    // Load a contiguous block of src into local array with adjusted bounds
    for (int i = -2; i < 16 + 3; i++) {
        local_src[i + 2] = src[i];
    }
    for (x = 0; x < 16; x++) {
        tmp[x] = cm[(filter[2] * local_src[x + 2 + 0] - filter[1] * local_src[x + 2 - 1] + 
                     filter[0] * local_src[x + 2 - 2] + filter[3] * local_src[x + 2 + 1] - 
                     filter[4] * local_src[x + 2 + 2] + filter[5] * local_src[x + 2 + 3] + 64) >> 7];
    }
    tmp += 16;
    src += srcstride;
}
}
