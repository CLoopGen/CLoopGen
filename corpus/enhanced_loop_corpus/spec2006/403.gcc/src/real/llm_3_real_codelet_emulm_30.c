#include <stdio.h>

#include <inttypes.h>

extern unsigned short equot[9];
extern unsigned short b[];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access — process array from last to first
    int n = 6 + 3;
    for (i = n - 1; i >= 0; i--) {
        b[i] = equot[i];
    }
}
