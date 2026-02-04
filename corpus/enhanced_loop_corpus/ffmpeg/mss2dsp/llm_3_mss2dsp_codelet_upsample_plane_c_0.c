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
    uint8_t *row_start;
    for (j = h - 1; j >= 0; j--) {
        row_start = plane + plane_stride * j;
        for (i = w - 1; i > 0; i--) {
            int src_idx1 = i >> 1;
            int src_idx2 = (i + 1) >> 1;
            p = row_start;
            if (i == w - 1) {
                p[i] = p[src_idx1];
            } else {
                a = p[src_idx1];
                b = p[src_idx2];
                p[i] = (3 * a + b + 1) >> 2;
                p[i + 1] = (a + 3 * b + 1) >> 2;
            }
        }
        // Handle the last iteration manually to avoid duplication
        if (w >= 1) {
            p = row_start;
            i = 0;
            p[i] = p[i >> 1];
        }
    }
}
