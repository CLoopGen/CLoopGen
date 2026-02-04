#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce loop depth by flattening the two loops into one using combined iteration
// We simulate the original semantics: height+7 rows and width columns
int total_iterations = (height + 7) * width;
for (int idx = 0; idx < total_iterations; idx++) {
    y = idx / width;
    x = idx % width;
    tmp[x] = (filter[0] * src[x - 3 * 1] + filter[1] * src[x - 2 * 1] + filter[2] * src[x - 1] + filter[3] * src[x] + filter[4] * src[x + 1] + filter[5] * src[x + 2 * 1] + filter[6] * src[x + 3 * 1] + filter[7] * src[x + 4 * 1]) >> (8 - 8);
    if (x == width - 1) {
        src += srcstride;
        tmp += 64;
    }
}
}
