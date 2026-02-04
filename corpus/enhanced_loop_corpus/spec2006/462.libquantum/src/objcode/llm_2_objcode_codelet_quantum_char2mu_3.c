#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern int size;
extern unsigned long long mu;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, backward traversal)
    for (i = size - 1; i >= 0; i -= 2) {
        mu += buf[i] * ((unsigned long long)1 << (8 * (size - i - 1)));
        if (i > 0) {
            mu += buf[i - 1] * ((unsigned long long)1 << (8 * (size - (i - 1) - 1)));
        }
    }
}
