#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _RectangleInfo {
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
} RectangleInfo;

extern  RectangleInfo *clahe_info;
extern  RectangleInfo *tile_info;
extern  unsigned short *lut;
extern size_t *histogram;
extern  unsigned short *p;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < (ssize_t)tile_info->height; i++) {
        const unsigned short *q = p + tile_info->width;
        for (; p < q; p++) {
            size_t index = lut[*p];
            histogram[index] += 1;
        }
        const unsigned short *next_q = q + (ptrdiff_t)clahe_info->width;
        p = next_q - tile_info->width;
    }
}
