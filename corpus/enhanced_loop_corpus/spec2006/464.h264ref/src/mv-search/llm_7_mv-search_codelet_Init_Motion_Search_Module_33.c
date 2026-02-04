#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int i;
extern int byte_abs_range;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 1; i < byte_abs_range / 2; i++) {
        byte_abs[i] = i;
        if (i > 1) {
            byte_abs[-(i-1)] = i - 1;
        }
    }
    // Handle last index for symmetry
    if (byte_abs_range > 2) {
        byte_abs[-(byte_abs_range / 2 - 1)] = byte_abs[byte_abs_range / 2 - 1];
    }
}
