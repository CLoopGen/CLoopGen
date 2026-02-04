#include <stdio.h>

#include <inttypes.h>

extern unsigned short *p;
extern unsigned short *q;
extern unsigned short i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset indexing (forward traversal)
    for (i = 0; i < 4; i++) {
        q[i] = p[i];
    }
}
