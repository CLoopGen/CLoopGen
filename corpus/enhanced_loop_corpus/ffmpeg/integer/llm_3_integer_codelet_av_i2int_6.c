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
    // Variant 2: Consecutive forward access with reversed index mapping
    out = 0;  // Initialize to avoid undefined behavior
    for (i = 0; i <= (8 - 2); i++) {
        int rev_idx = (8 - 2) - i;  // Reverse the access order: descending logical index
        out = (out << 16) + a.v[rev_idx];
    }
}
