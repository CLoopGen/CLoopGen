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
        p[y * 12 + 0] = t[y * pitch * 2 + 0];
        p[y * 12 + 1] = t[y * pitch * 2 + 1];
        p[y * 12 + 2] = t[y * 12 + 2];
        p[y * 12 + 3] = t[y * pitch * 2 + 3];
        p[y * 12 + 4] = t[y * pitch * 2 + 4];
        p[y * 12 + 5] = t[y * pitch * 2 + 5];
        p[y * 12 + 6] = t[y * pitch * 2 + 6];
        p[y * 12 + 7] = t[y * pitch * 2 + 7];
        p[y * 12 + 8] = t[y * pitch * 2 + 8];
        p[y * 12 + 9] = t[y * pitch * 2 + 9];
        p[y * 12 + 10] = t[y * pitch * 2 + 10];
        p[y * 12 + 11] = t[y * pitch * 2 + 11];
    }
}
