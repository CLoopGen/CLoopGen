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
for (i = 0; i < 2; i++) {
    for (int j = 0; j < 4; j++) {
        int flat_index = i * 4 + j;
        if (flat_index < 8) {
            unsigned int index = flat_index + (s >> 4);
            unsigned int v = 0;
            if (index + 1 < 8)
                v = a.v[index + 1] << 16;
            if (index < 8)
                v += a.v[index];
            out.v[flat_index] = v >> (s & 15);
        }
    }
}
}
