#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern short *extrema;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ssize_t j = 0; j <= 255; j += 16) {
        for (ssize_t i = j; i < j + 16 && i <= 255; i++) {
            extrema[i] = 0;
        }
    }
}
