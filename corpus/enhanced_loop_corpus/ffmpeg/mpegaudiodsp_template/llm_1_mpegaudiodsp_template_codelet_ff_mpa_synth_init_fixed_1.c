#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int step = 0; step < 16; step += 2) {
            j = step;
            window[512 + 16 * i + j] = window[64 * i + 32 - j];
            if (step + 1 < 16) {
                j = step + 1;
                window[512 + 16 * i + j] = window[64 * i + 32 - j];
            }
        }
    }
}
