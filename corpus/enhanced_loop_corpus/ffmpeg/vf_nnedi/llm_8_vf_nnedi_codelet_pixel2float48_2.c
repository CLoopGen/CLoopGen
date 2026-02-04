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
    for (y = 0; y < 4; y++) {
        int base_p = y * 12;
        int base_t = y * pitch * 2;
        for (x = 0; x < 12; x += 3) {
            p[base_p + x] = t[base_t + x];
            if (x + 1 < 12) p[base_p + x + 1] = t[base_t + x + 1];
            if (x + 2 < 12) p[base_p + x + 2] = t[base_t + x + 2];
        }
    }
}
