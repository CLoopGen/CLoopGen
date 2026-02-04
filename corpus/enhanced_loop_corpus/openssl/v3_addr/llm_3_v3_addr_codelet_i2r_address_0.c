#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive forward traversal with offset indexing
    // Start from beginning and scan forward with consecutive pair checks
    // Simulates prefetching-friendly access pattern
    int i;
    for (i = 0; i < 15 && addr[i] == 0 && addr[i + 1] == 0; i += 2)
        ;
    n = 16 - i; // Adjust final value of n to reflect remaining non-zero segment length
}
