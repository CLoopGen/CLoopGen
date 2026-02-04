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
for (y = 0; y < height + 3; y++) {
    uint16_t *src_row = src;
    int16_t *tmp_row = tmp;
    for (x = 0; x < width; x += 4) {
        // Unrolled with consecutive access to improve spatial locality
        if (x + 0 < width) tmp_row[x + 0] = (filter[0] * src_row[x - 1 + 0] + filter[1] * src_row[x + 0] + filter[2] * src_row[x + 1 + 0] + filter[3] * src_row[x + 2]) >> 2;
        if (x + 1 < width) tmp_row[x + 1] = (filter[0] * src_row[x - 1 + 1] + filter[1] * src_row[x + 1] + filter[2] * src_row[x + 1 + 1] + filter[3] * src_row[x + 2 + 1]) >> 2;
        if (x + 2 < width) tmp_row[x + 2] = (filter[0] * src_row[x - 1 + 2] + filter[1] * src_row[x + 2] + filter[2] * src_row[x + 1 + 2] + filter[3] * src_row[x + 2 + 2]) >> 2;
        if (x + 3 < width) tmp_row[x + 3] = (filter[0] * src_row[x - 1 + 3] + filter[1] * src_row[x + 3] + filter[2] * src_row[x + 1 + 3] + filter[3] * src_row[x + 2 + 3]) >> 2;
    }
    src += srcstride;
    tmp += 64;
}
}
