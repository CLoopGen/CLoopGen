#include <stdio.h>

#include <inttypes.h>

extern  char *m1;
extern  char *m2;
extern char bdiff[81];
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2)
    size_t stride = 2;
    size_t limit = j - (j % stride);  // Make sure we don't overflow
    for (; i < limit; i += stride) {
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
    }
    // Handle remaining elements if any
    for (; i < j; i++) {
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
    }
}
