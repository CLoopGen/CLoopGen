#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MPA_INT;

extern MPA_INT *window;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; i++) {
        for (int step = 0; step < 16; step += 4) {
            for (j = step; j < step + 4 && j < 16; j++) {
                window[512 + 128 + 16 * i + j] = window[64 * i + 48 - j];
            }
        }
    }
}
