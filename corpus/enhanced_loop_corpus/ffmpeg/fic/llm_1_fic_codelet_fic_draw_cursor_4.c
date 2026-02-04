#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t planes[4][1024];
extern uint8_t chroma[3][256];
extern int i;
extern int j;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i += 2)
    for (j = 0; j < 32; j += 2)
        for (p = 0; p < 3; p++) {
            int idx = 16 * (i / 2) + j / 2;
            int base = 32 * i + j;
            chroma[p][idx] = (planes[p + 1][base] + planes[p + 1][base + 1] +
                              planes[p + 1][base + 32] + planes[p + 1][base + 33]) / 4;
        }
}
