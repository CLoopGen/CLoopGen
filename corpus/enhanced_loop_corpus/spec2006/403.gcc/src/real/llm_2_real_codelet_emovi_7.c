#include <stdio.h>

#include <inttypes.h>

extern  unsigned short *p;
extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive forward access with offset indexing (strided by 1)
    for (i = 0; i < 6 - 1; i++) {
        q[i] = p[4 - i];  // Access p in reverse order using index, write to q consecutively
    }
}
