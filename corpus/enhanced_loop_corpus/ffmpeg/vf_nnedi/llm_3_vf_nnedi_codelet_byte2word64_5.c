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
    // Variant 2: Strided memory access with reversed iteration order and fixed stride on `t`
    int stride = pitch * 2;
    int ps_idx = 63; // Reverse index for ps: 4*16 - 1
    for (y = 3; y >= 0; y--) {
        int t_offset = y * stride;
        for (x = 15; x >= 0; x--) {
            ps[ps_idx] = t[t_offset + x];
            ps_idx--;
        }
    }
}
