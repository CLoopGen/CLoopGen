#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern ptrdiff_t in_linesize;
extern  int16_t * u;
extern  int16_t * v;
extern  uint8_t * s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int x = 0; x < width; x++) {
        if (u[x] >= 0 && v[x] >= 0) {
            d[x] = s[v[x] * in_linesize + u[x]];
        }
    }
}
