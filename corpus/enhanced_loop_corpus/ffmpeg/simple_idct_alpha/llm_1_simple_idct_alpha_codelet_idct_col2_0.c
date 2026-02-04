#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *col;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx = j + i * 4;
            if (idx < 8) {
                int a0 = col[idx] + (1 << (20 - 1)) / 16383;
                a0 *= 16383;
                col[idx] = a0 >> 20;
            }
        }
    }
}
