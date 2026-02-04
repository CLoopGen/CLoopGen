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
        unsigned int index = i + (s >> 4);
        unsigned int v = 0;
        // Removed the first conditional by using bounds-checked array access via ternary
        v = (index + 1 < 8) ? (a.v[index + 1] << 16) : 0;
        v += (index < 8) ? a.v[index] : 0;
        out.v[i] = v >> (s & 15);
    }
}
