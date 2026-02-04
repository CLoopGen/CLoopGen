#include <stdio.h>

#include <inttypes.h>

extern char *source;
extern size_t bytes;
extern long value;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access in ascending order (reversed iteration direction)
    // We reverse the index traversal to go from 0 to bytes-1, adjusting logic accordingly.
    value = 0;
    for (i = 0; i < (int)bytes; i++)
        value = value * 256 + (source[i] & (i == ((int)bytes - 1) ? 127 : 255));
}
