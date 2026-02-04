#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; ++i) {
        r[i] = 1 & (a[i >> 3] >> ((i & 7) ^ ((i >> 2) & 1)));
    }
}
