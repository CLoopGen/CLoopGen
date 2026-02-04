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
    for (int x = 0; x < width; x += 2) {
        d[x] = s[v[x] * in_linesize + u[x]];
        if (x + 1 < width) {
            d[x + 1] = s[v[x + 1] * in_linesize + u[x + 1]];
        }
    }
}
