#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; ++i) {
    e[2 * i + 0] = (a[i] >> 0) & 15;
    if (i % 2 == 0) {
        e[2 * i + 1] = (a[i] >> 4) & 15;
    } else {
        e[2 * i + 1] = 0;
    }
}
}
