#include <stdio.h>

#include <inttypes.h>

extern unsigned short c[];
extern unsigned short p[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing
    int start = 2;
    int count = 7 - 2;
    for (int j = 0; j < count; j++) {
        c[start + j] = p[start + j];
    }
}
