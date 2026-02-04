#include <stdio.h>

#include <inttypes.h>

extern char *swap;
extern int nbytes;
extern int x;
extern char byte;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided Memory Access (process two elements at a time with stride 2)
    int step = 2;
    for (x = 0; x < nbytes / 2; x += step) {
        // Process current and next element if within bounds
        for (int s = 0; s < step && (x + s) < nbytes / 2; s++) {
            int idx = x + s;
            byte = swap[nbytes - idx - 1];
            swap[nbytes - idx - 1] = swap[idx];
            swap[idx] = byte;
        }
    }
}
