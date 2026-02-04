#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t length;
extern unsigned char *nonce;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access (stride of 2, backward traversal)
    // We traverse from the end with a step size of 2, handling even and odd lengths.
    ssize_t start = (ssize_t)(length - 1);
    for (i = start; i >= 0; i -= 2) {
        nonce[i]++;
        if (nonce[i] != 0)
            return;
    }
    // Handle carry propagation in second pass for strided elements
    for (i = start - 1; i >= 0; i -= 2) {
        nonce[i]++;
        if (nonce[i] != 0)
            return;
    }
}
