#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct YuvPixel {
    int8_t y;
    int8_t v;
    int8_t u;
} YuvPixel;

extern YuvPixel *p;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
ptrdiff_t stride = 2;
for (i = 0; i < 31; ++i) {
    for (j = 31; j > i; --j) {
        ptrdiff_t idx1 = j * stride;
        ptrdiff_t idx2 = (j - 1) * stride;
        if (idx1 >= 0 && idx1 <= 62 && idx2 >= 0 && idx2 <= 62)
            if (!(p[idx1].u | p[idx1].v | p[idx1].y))
                p[idx1] = p[idx2];
    }
    for (j = 0; j < 31 - i; ++j) {
        ptrdiff_t idx1 = j * stride;
        ptrdiff_t idx2 = (j + 1) * stride;
        if (idx1 >= 0 && idx1 <= 62 && idx2 >= 0 && idx2 <= 62)
            if (!(p[idx1].u | p[idx1].v | p[idx1].y))
                p[idx1] = p[idx2];
    }
}
}
