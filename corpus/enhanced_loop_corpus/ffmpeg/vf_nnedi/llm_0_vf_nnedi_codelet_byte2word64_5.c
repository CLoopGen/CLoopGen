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
    for (y = 0; y < 4; y++) {
        int base_src = y * pitch * 2;
        int base_dst = y * 16;
        for (x = 0; x < 16; x++) {
            ps[base_dst + x] = t[base_src + x];
        }
    }
}
