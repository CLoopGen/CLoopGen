#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

extern JSAMPLE *table;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulated with reverse order access)
    int indices[256];
    for (int j = 0; j <= 255; j++) {
        indices[j] = 255 - j; // Reverse mapping: write from end to start
    }
    for (i = 0; i <= 255; i++) {
        int idx = indices[i];
        table[idx] = (JSAMPLE)(255 - idx);
    }
}
