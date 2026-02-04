#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern ptrdiff_t in_linesize;
extern  int16_t * u;
extern  int16_t * v;
extern  uint16_t * s;
extern uint16_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (int x = 0; x < width; x += stride) {
        for (int offset = 0; offset < stride && (x + offset) < width; offset++) {
            int idx = x + offset;
            d[idx] = s[v[idx] * in_linesize + u[idx]];
        }
    }
}
