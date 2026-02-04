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
        if (i % 2 == 0) {
            for (j = 0; j < 16; j++) {
                window[512 + 16 * i + j] = window[64 * i + 32 - j];
            }
        } else {
            for (j = 0; j < 16; j += 2) {
                window[512 + 16 * i + j] = window[64 * i + 32 - j];
            }
        }
    }
}
