#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int byte_abs_range;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with forward traversal
    int limit = byte_abs_range / 2;
    for (i = 1; i < limit; i++) {
        byte_abs[i] = i;
        byte_abs[i + limit] = i;  // Use consecutive higher region instead of negative index
    }
}
