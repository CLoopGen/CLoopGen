#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *temp_top_row = (uint16_t*)malloc(width * sizeof(uint16_t));
    uint16_t *temp_bottom_row = (uint16_t*)malloc(width * sizeof(uint16_t));
    if (!temp_top_row || !temp_bottom_row) return;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp_top_row[j] = top[j];
            temp_bottom_row[j] = bottom[j];
        }

        for (j = 0; j < width; j++) {
            uint16_t t = temp_top_row[j];
            uint16_t b = temp_bottom_row[j];
            int32_t residual = 1023 - t - b;
            int32_t abs_residual = residual >= 0 ? residual : -residual;
            int32_t result = t + (abs_residual - t) * opacity;
            dst[j] = (uint16_t)(result >= 0 ? (result < 1024 ? result : 1023) : 0);
        }

        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }

    free(temp_top_row);
    free(temp_bottom_row);
}
