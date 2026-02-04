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
        for (x = 0; x < 16; x++) {
            if ((y * 16 + x) % 5 != 0) {
                ps[y * 16 + x] = t[y * pitch * 2 + x];
            }
        }
    }
}
