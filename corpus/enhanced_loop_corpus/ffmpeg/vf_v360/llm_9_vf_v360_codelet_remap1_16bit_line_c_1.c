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
    for (int x = 0; x < width; x++) {
        ptrdiff_t index_v = v[x] * in_linesize;
        d[x] = s[index_v + u[x]] + s[index_v + u[x] + 1] - (s[index_v + u[x]] >> 1);
    }
}
