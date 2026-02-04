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



void loop(){
    for (j = h - 1; j >= 0; j--) {
        p = plane + plane_stride * j;
        for (i = w - 1; i >= 0; i--) {
            if ((i & 1) == 0) {
                p[i] = p[i >> 1];
            } else if (i > 1) {
                a = p[(i - 1) >> 1];
                b = p[(i + 1) >> 1];
                p[i] = (a + 3 * b + 1) >> 2;
                p[i - 1] = (3 * a + b + 1) >> 2;
                i--; // Skip next since we've processed two elements
            }
        }
    }
}
