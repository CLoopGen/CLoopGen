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
    // Variant 1: Consecutive memory access by flattening the 2D access into a sequential stride
    int idx = 0;
    for (y = 0; y < 4; y++) {
        int base_src = y * pitch * 2;
        for (x = 0; x < 12; x++) {
            p[idx] = t[base_src + x];
            idx++;
        }
    }
}
