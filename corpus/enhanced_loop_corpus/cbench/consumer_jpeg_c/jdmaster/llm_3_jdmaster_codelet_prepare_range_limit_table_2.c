#include <stdio.h>

#include <inttypes.h>

typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with increasing stride (non-unit, power-of-2 spacing)
    int limit = 2 * (255 + 1);
    for (i = 128; i < limit; i++) {
        int index = 128 + ((i - 128) * 2); // Map to higher addresses with stride 2
        if (index < limit) {
            table[index] = 255;
        }
    }
}
