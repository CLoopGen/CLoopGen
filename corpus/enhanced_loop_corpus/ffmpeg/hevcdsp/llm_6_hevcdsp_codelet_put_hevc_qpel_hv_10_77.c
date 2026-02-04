#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint16_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int8_t *filter_local = filter;
    uint16_t *src_local = src;
    int16_t *tmp_local = tmp;
    for (y = 0; y < height + 7; y++) {
        int sum0, sum1, sum2, sum3;
        for (x = 0; x < width - 3; x += 4) {
            // Introduce temporal reuse and modify RAW dependencies by unrolling and reusing filter loads
            sum0 = filter_local[0] * src_local[x - 3] + filter_local[1] * src_local[x - 2] +
                   filter_local[2] * src_local[x - 1] + filter_local[3] * src_local[x] +
                   filter_local[4] * src_local[x + 1] + filter_local[5] * src_local[x + 2] +
                   filter_local[6] * src_local[x + 3] + filter_local[7] * src_local[x + 4];
            sum1 = filter_local[0] * src_local[x - 2] + filter_local[1] * src_local[x - 1] +
                   filter_local[2] * src_local[x]     + filter_local[3] * src_local[x + 1] +
                   filter_local[4] * src_local[x + 2] + filter_local[5] * src_local[x + 3] +
                   filter_local[6] * src_local[x + 4] + filter_local[7] * src_local[x + 5];
            sum2 = filter_local[0] * src_local[x - 1] + filter_local[1] * src_local[x] +
                   filter_local[2] * src_local[x + 1] + filter_local[3] * src_local[x + 2] +
                   filter_local[4] * src_local[x + 3] + filter_local[5] * src_local[x + 4] +
                   filter_local[6] * src_local[x + 5] + filter_local[7] * src_local[x + 6];
            sum3 = filter_local[0] * src_local[x]     + filter_local[1] * src_local[x + 1] +
                   filter_local[2] * src_local[x + 2] + filter_local[3] * src_local[x + 3] +
                   filter_local[4] * src_local[x + 4] + filter_local[5] * src_local[x + 5] +
                   filter_local[6] * src_local[x + 6] + filter_local[7] * src_local[x + 7];

            tmp_local[x]     = sum0 >> 2;
            tmp_local[x+1]   = sum1 >> 2;
            tmp_local[x+2]   = sum2 >> 2;
            tmp_local[x+3]   = sum3 >> 2;
        }
        // Handle remaining elements if width is not multiple of 4
        for (; x < width; x++) {
            tmp_local[x] = (filter_local[0] * src_local[x - 3] + filter_local[1] * src_local[x - 2] +
                            filter_local[2] * src_local[x - 1] + filter_local[3] * src_local[x] +
                            filter_local[4] * src_local[x + 1] + filter_local[5] * src_local[x + 2] +
                            filter_local[6] * src_local[x + 3] + filter_local[7] * src_local[x + 4]) >> 2;
        }
        src_local += srcstride;
        tmp_local += 64;
    }
}
