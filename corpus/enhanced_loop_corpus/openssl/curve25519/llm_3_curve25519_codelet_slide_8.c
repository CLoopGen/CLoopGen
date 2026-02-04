#include <stdio.h>

#include <inttypes.h>

extern signed char *r;
extern  uint8_t *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive byte-wise access with unrolled bit extraction
    // Instead of scattering bit accesses across a[], process a[] consecutively and unpack all 8 bits at once
    int idx = 0;
    for (i = 0; i < 32; ++i) {  // a has at least 32 elements to cover 256 bits
        uint8_t byte = a[i];
        r[idx + 0] = (byte >> 0) & 1;
        r[idx + 1] = (byte >> 1) & 1;
        r[idx + 2] = (byte >> 2) & 1;
        r[idx + 3] = (byte >> 3) & 1;
        r[idx + 4] = (byte >> 4) & 1;
        r[idx + 5] = (byte >> 5) & 1;
        r[idx + 6] = (byte >> 6) & 1;
        r[idx + 7] = (byte >> 7) & 1;
        idx += 8;
    }
}
