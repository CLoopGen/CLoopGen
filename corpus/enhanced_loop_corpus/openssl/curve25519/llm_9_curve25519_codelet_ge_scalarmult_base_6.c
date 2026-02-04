#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; ++i) {
    uint8_t val0 = a[2*i];
    uint8_t val1 = a[2*i + 1];
    e[4*i + 0] = (val0 >> 0) & 15;
    e[4*i + 1] = (val0 >> 4) & 15;
    e[4*i + 2] = (val1 >> 0) & 15;
    e[4*i + 3] = (val1 >> 4) & 15;
}
}
