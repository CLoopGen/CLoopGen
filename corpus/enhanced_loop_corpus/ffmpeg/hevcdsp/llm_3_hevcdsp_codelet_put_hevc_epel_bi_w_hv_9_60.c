#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern  int8_t *filter;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
const int8_t *f_base = filter;
for (y = 0; y < height + 3; y++) {
    uint16_t *src_offset = (uint16_t *)((char *)src - 1);
    for (x = 0; x < width; x++) {
        int16_t sum = 0;
        for (int k = 0; k < 4; k++) {
            sum += f_base[k] * src_offset[x + k];
        }
        tmp[x] = sum >> 1;
    }
    src += srcstride;
    tmp += 64;
}
}
