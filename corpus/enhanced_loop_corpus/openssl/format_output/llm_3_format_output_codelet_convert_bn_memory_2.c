#include <stdio.h>

#include <inttypes.h>

extern int n;
extern int i;
extern char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive bulk initialization using array indexing
    // Access memory in large chunks via index arithmetic, simulate wide store pattern
    char buffer[32];
    int stride = 32;
    for (i = 0; i < n; i += stride) {
        // Fill a local buffer to reduce pointer updates
        for (int j = 0; j < stride && i + j < n; j++) {
            buffer[j] = ' ';
        }
        // Flush buffer to destination memory consecutively
        for (int j = 0; j < stride && i + j < n; j++) {
            p[j] = buffer[j];
        }
        p += stride;
        // Insert extra space every 16th iteration boundary (originally every 16th index)
        if ((i + stride) % 16 == 0 && i + stride < n) {
            *p++ = ' ';
        }
    }
}
