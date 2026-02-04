#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVInteger {
    uint16_t v[8];
} AVInteger;

extern AVInteger a;
extern int i;
extern int64_t out;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    out = 0;  // Initialize to avoid undefined behavior
    for (i = (8 - 2); i >= 0; i -= 2) {
        int idx = i % 8;
        out = (out << 16) + a.v[idx];
    }
    // Handle remaining element if stride skips any during reverse traversal
    if ((8 - 2) % 2 == 1) {
        out = (out << 16) + a.v[0];
    }
}
