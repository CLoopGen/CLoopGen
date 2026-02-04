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
    int idx = 0;
    for (y = 0; y < 48; y++) {
        p[y] = t[(y / 12) * pitch * 2 + (y % 12)];
    }
}
