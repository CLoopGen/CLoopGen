#include <stdio.h>

#include <inttypes.h>

extern int j;
extern unsigned char *buf;
extern int i;
extern int size;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive memory access with reverse traversal (backward iteration)
    for (i = size - 1; i >= 0; i--) {
        int shift_amount = (size - i - 1) * 8;
        buf[size - 1 - i] = j >> shift_amount;
        j &= ((1 << shift_amount) - 1);
    }
}
