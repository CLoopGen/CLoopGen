#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *plane;
extern ptrdiff_t plane_stride;
extern int w;
extern int h;
extern uint8_t *p;
extern uint8_t a;
extern uint8_t b;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int stride_offset = (h - 1) * plane_stride;
    for (j = h - 1; j >= 0; j--, stride_offset -= plane_stride) {
        p = plane + stride_offset;
        for (i = w - 1; i >= 2; i -= 4) {
            int i1 = i, i2 = i - 1, i3 = i - 2, i4 = i - 3;
            uint8_t a1 = p[i1 >> 1], b1 = p[(i1 + 1) >> 1];
            uint8_t a2 = p[i3 >> 1], b2 = p[(i3 + 1) >> 1];

            p[i1] = (3 * a1 + b1 + 1) >> 2;
            p[i1 + 1] = (a1 + 3 * b1 + 1) >> 2;
            p[i2] = (3 * b1 + a2 + 1) >> 2;

            if (i3 > 0) {
                p[i3] = (3 * a2 + b2 + 1) >> 2;
                p[i3 + 1] = (a2 + 3 * b2 + 1) >> 2;
            }
        }
        if (i == 1) {
            p[i] = p[i >> 1];
        }
    }
}
