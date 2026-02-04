#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect addressing via index array to simulate irregular memory access
int indices[64];
for (int i = 0; i < width && i < 64; i++) {
    indices[i] = i; // Simulate potential gather pattern
}

for (y = 0; y < height + 3; y++) {
    for (x = 0; x < width && x < 64; x++) {
        int idx = indices[x];
        // Access source with fixed offsets but through an indexed pattern
        tmp[idx] = (filter[0] * src[idx - 1] + filter[1] * src[idx] + filter[2] * src[idx + 1] + filter[3] * src[idx + 2]) >> 0;
    }
    src += srcstride;
    tmp += 64;
}
}
