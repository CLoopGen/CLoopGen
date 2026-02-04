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
    // Variant 1: Consecutive memory access by reordering computation to access `t` and `ps` in sequential strides
    int idx = 0;
    for (y = 0; y < 4; y++) {
        int t_base = y * pitch * 2;
        for (x = 0; x < 16; x++) {
            ps[idx] = t[t_base + x];
            idx++;
        }
    }
}
