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
        for (i = w - 1; i >= 1; i -= 2) {
            if (i == w - 1) {
                p[i] = p[i >> 1];
            }
            if (i > 1) {
                a = p[i >> 1];
                b = p[(i + 1) >> 1];
                p[i] = (3 * a + b + 1) >> 2;
                p[i + 1] = (a + 3 * b + 1) >> 2;
            }
        }
    }
}
