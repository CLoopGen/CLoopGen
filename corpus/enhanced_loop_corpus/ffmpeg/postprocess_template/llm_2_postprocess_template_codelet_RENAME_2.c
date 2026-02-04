#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int y;
extern int s[10];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in a modified range)
    for (y = 2; y < 8; y += 2) {
        int t = s[y - 2] & s[y] & s[y + 2];
        t |= t >> 16;
        s[y - 2] = t;
    }
}
