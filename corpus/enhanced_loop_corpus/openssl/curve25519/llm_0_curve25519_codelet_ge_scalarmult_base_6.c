#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; ++i) {
        e[4 * i + 0] = (a[i] >> 0) & 15;
        e[4 * i + 1] = (a[i] >> 4) & 15;
        e[4 * i + 2] = (a[i + 16] >> 0) & 15;
        e[4 * i + 3] = (a[i + 16] >> 4) & 15;
    }
}
