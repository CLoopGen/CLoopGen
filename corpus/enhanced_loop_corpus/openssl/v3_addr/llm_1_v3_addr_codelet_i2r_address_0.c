#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Flattened version: reduce nesting potential by removing any compound structure
    // Original loop already has depth 1, so we ensure no block grouping exists unnecessarily
    for (n = 16; n > 1 && addr[n - 1] == 0 && addr[n - 2] == 0; n -= 2);
}
