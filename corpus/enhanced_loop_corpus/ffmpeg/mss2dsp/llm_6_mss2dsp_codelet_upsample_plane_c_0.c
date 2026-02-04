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
    for (i = w - 1; i > 0; i -= 2) {
        uint8_t temp_a = p[i >> 1];
        uint8_t temp_b = p[(i + 1) >> 1];
        p[i] = (3 * temp_a + temp_b + 1) >> 2;
        if (i > 1) {
            p[i - 1] = p[(i - 1) >> 1];
        }
        if (i > 2) {
            p[i - 2] = (temp_a + 3 * temp_b + 1) >> 2;
        }
    }
    if (w > 0) {
        p[0] = p[0];
    }
}
}
