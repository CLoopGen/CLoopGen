#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *t;
extern  int pitch;
extern int16_t *p;
extern int y;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by flattening the 2D access into a sequential scan
    // We traverse the output array p and input array t in a single loop with unit stride
    int idx = 0;
    for (y = 0; y < 4; y++) {
        int t_base = y * pitch * 2;
        for (x = 0; x < 12; x++) {
            p[idx] = t[t_base + x];
            idx++;
        }
    }
}
