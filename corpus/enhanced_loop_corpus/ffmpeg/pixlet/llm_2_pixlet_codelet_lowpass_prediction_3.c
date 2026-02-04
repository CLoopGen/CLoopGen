#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *pred;
extern int width;
extern int height;
extern ptrdiff_t stride;
extern int16_t val;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    int16_t *dst_row = &dst[i * stride];
    int16_t *pred_row = &pred[i * stride];
    val = pred_row[0] + dst_row[0];
    dst_row[0] = pred_row[0] = val;
    for (j = 1; j < width; j++) {
        val = pred_row[j] + dst_row[j];
        dst_row[j] = pred_row[j] = val;
        dst_row[j] += dst_row[j - 1];
    }
}
}
