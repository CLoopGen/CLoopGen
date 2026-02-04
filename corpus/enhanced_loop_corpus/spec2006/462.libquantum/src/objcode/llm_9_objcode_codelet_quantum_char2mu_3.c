#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Reduce trip count by processing two elements per iteration
    for (i = size - 1; i >= 1; i -= 2) {
        int offset1 = size - i - 1;
        int offset2 = size - (i - 1) - 1;
        mu += buf[i] * ((unsigned long long)1 << (8 * offset1));
        mu += buf[i - 1] * ((unsigned long long)1 << (8 * offset2));
    }
    // Handle remaining element if size is odd
    if (i == 0) {
        mu += buf[0] * ((unsigned long long)1 << (8 * (size - 0 - 1)));
    }
}
