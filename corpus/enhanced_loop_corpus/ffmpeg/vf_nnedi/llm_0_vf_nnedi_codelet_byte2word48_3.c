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
    for (y = 0; y < 4; y++) {
        int base_t = y * pitch * 2;
        int base_p = y * 12;
        for (x = 0; x < 12; x++) {
            p[base_p + x] = t[base_t + x];
        }
    }
}
