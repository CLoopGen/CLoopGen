#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t;
extern  int pitch;
extern int16_t *ps;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int idx = 0;
    for (y = 0; y < 64; y++) {
        int src_idx = (y >> 4) * pitch * 2 + (y & 15);
        ps[idx++] = t[src_idx];
    }
}
