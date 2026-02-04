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
            uint8_t val1 = planes[p + 1][32 * i + j];
            uint8_t val2 = planes[p + 1][32 * i + j + 1];
            uint8_t val3 = planes[p + 1][32 * (i + 1) + j];
            uint8_t val4 = planes[p + 1][32 * (i + 1) + j + 1];
            chroma[p][16 * (i / 2) + j / 2] = (val1 + val2 + val3 + val4) / 4;
        }
}
