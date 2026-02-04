#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *a;
extern  uint8_t *b;
extern  uint8_t *c;
extern int w;
extern int x;
extern int ret;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    for (x = 0; x < w; x += 2) {
        if (x + 1 >= w) break;
        int v1 = (*(a + x) + *(c + x)) - 2 * *(b + x);
        int v2 = (*(a + x + 1) + *(c + x + 1)) - 2 * *(b + x + 1);
        ret += ((v1) >= 0 ? (v1) : (-(v1)));
        ret += ((v2) >= 0 ? (v2) : (-(v2)));
    }
}
