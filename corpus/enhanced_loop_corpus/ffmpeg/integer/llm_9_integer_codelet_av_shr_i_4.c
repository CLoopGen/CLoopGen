#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern int s;
extern AVInteger out;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    unsigned int index = (i << 1) + (s >> 4);
    unsigned int v = 0;
    if (index + 2 < 8) {
        v = (a.v[index + 2] << 16) | (a.v[index + 1] << 8);
    }
    if (index < 8) {
        v += a.v[index];
    }
    out.v[i & 7] ^= v >> ((s + i) & 15);
}
}
