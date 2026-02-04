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
        int base_offset = y * pitch * 2;
        int dst_offset = y * 16;
        for (x = 0; x < 16; x++) {
            if (x < pitch / 2 + 1) {
                ps[dst_offset + x] = t[base_offset + x];
            }
        }
    }
}
