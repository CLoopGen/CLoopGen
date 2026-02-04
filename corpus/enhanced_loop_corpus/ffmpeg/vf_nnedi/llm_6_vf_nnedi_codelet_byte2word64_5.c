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
    for (y = 0; y < 4; y++) {
        int base_t_idx = y * pitch * 2;
        int base_ps_idx = y * 16;
        for (x = 0; x < 16; x++) {
            ps[base_ps_idx + x] = t[base_ps_idx + x]; // Introduce WAW-like pattern via reuse of base_ps_idx, but still safe
            idx = base_ps_idx + x; // Introduce artificial loop-carried dependency on 'idx'
        }
    }
}
