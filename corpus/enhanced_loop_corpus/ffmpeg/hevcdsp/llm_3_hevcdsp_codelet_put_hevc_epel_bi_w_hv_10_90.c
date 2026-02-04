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
ptrdiff_t stride_scaled = srcstride / sizeof(uint16_t);
uint16_t **src_rows = (uint16_t**)alloca((height + 3) * sizeof(uint16_t*));
for (int i = 0; i < height + 3; i++) {
    src_rows[i] = src + i * stride_scaled;
}

for (y = 0; y < height + 3; y++) {
    uint16_t *current_row = src_rows[y];
    for (x = 0; x < width; x++) {
        tmp[x] = (filter[0] * current_row[x - 1] +
                  filter[1] * current_row[x] +
                  filter[2] * current_row[x + 1] +
                  filter[3] * current_row[x + 2]) >> 2;
    }
    tmp += 64;
}
}
