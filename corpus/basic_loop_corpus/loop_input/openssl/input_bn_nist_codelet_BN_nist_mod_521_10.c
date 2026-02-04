#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define DATA_SIZE (1024 * 128) // 128 KB of data

int top;
unsigned long t_d[9];
int ii;
unsigned long *src;

void init_vars() {
    // Set top such that the loop runs with a meaningful number of iterations
    // We want to ensure: ii < top - ((521 + 63) / 64 - 1)
    // Which simplifies: (521 + 63) / 64 = 584 / 64 = 9.125 -> integer division gives 9, so subtract 1 => 8
    // So loop condition becomes: ii < top - 8
    // We want at least 9 elements in t_d? But t_d is only size 9.
    // To avoid out-of-bounds on t_d[ii], we must have: ii < 9
    // Therefore: top - 8 >= 9  => top >= 17
    // But also we are reading from src[ii], so src must have at least (top - 8) elements.

    // Let's set top = 17 so that loop runs for ii = 0 to 8 (9 iterations), which fits t_d[9]
    top = 17;

    // Initialize t_d with known values
    for (int i = 0; i < 9; i++) {
        t_d[i] = 0xDEADBEEFDEADBEEFULL ^ i;
    }

    // Allocate and initialize src with sufficient size: at least (top - 8) = 9 elements
    src = (unsigned long*)malloc(DATA_SIZE);
    if (!src) {
        // In case malloc fails, fallback to minimal static allocation
        static unsigned long fallback_src[9];
        src = fallback_src;
        top = 17; // still valid
    } else {
        // Initialize src with data
        size_t count = DATA_SIZE / sizeof(unsigned long);
        for (size_t i = 0; i < count; i++) {
            src[i] = 0xCAFEBABECAFEBABEULL ^ i;
        }
    }
}