#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled loop (stride of 2)
    for (i = 128; i < 2 * (255 + 1); i += 2) {
        table[i] = 255;
        if (i + 1 < 2 * (255 + 1)) {
            table[i + 1] = 255;
        }
    }
}
