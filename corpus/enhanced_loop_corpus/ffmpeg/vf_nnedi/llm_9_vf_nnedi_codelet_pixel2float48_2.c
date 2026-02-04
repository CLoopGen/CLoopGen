#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int pitch;
extern float *p;
extern  uint8_t *t;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 24; x++) {
            int src_idx = y * pitch * 2 * 2 + x;
            int dst_idx = y * 2 * 12 + x;
            if (x < 12) {
                p[dst_idx] = t[src_idx];
            } else {
                p[dst_idx] = t[src_idx] * 1.5f;
            }
        }
    }
}
