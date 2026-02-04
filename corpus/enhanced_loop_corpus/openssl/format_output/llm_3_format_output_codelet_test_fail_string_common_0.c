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
    // Variant 2: Consecutive forward traversal with local blocking (unrolled by 4)
    size_t remainder = j % 4;
    size_t unroll_limit = j - remainder;

    // Unrolled main loop for consecutive access with improved spatial locality
    for (; i + 3 < unroll_limit; i += 4) {
        // Process 4 elements consecutively
        if (m1[i] == m2[i]) bdiff[i] = ' '; else { bdiff[i] = '^'; diff = 1; }
        if (m1[i+1] == m2[i+1]) bdiff[i+1] = ' '; else { bdiff[i+1] = '^'; diff = 1; }
        if (m1[i+2] == m2[i+2]) bdiff[i+2] = ' '; else { bdiff[i+2] = '^'; diff = 1; }
        if (m1[i+3] == m2[i+3]) bdiff[i+3] = ' '; else { bdiff[i+3] = '^'; diff = 1; }
    }
    // Tail handling for leftover elements
    for (; i < j; i++) {
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
    }
}
