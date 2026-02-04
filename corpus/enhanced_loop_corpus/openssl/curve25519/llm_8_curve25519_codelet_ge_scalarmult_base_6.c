#include <stdio.h>

#include <inttypes.h>

extern  uint8_t *a;
extern signed char e[64];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; ++i) {
    int idx = i >> 1;
    int shift = (i & 1) << 2;
    e[i] = (a[idx] >> shift) & 15;
}
}
