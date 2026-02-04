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
    for (y = 0; y < 4; ++y) {
        for (x = 0; x < 12; ++x) {
            if (y >= 1 && y < 3) {
                p[y * 12 + x] = t[y * pitch * 2 + x];
            } else {
                p[y * 12 + x] = 0.0f;
            }
        }
    }
}
