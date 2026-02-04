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
        for (j = 15; j >= 0; j--) {
            window[512 + 16 * i + (15 - j)] = window[64 * i + 32 - j];
        }
    }
}
