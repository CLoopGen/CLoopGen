#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern uint32_t magnitude;
extern char bits[33];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal (original access pattern is already consecutive, but we reverse the index order to create a different access pattern)
    int idx;
    for (i = 0; i < width; i++) {
        idx = i; // Access bits consecutively from start
        bits[idx] = (magnitude >> (width - i - 1)) & 1 ? '1' : '0';
    }
}
