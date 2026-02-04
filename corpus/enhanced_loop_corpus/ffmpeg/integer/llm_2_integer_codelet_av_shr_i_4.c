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
for (i = 0; i < 8; i++) {
    unsigned int index = (s >> 4) + i;
    unsigned int v = 0;
    // Change to strided access by accessing every second element in a wrapped manner
    int stride = 2;
    int pos1 = (index + 1) * stride;
    int pos0 = index * stride;
    if (pos1 < 16 && (pos1 / stride) < 8)
        v = a.v[pos1 / stride] << 16;
    if (pos0 < 16 && (pos0 / stride) < 8)
        v += a.v[pos0 / stride];
    out.v[i] = v >> (s & 15);
}
}
