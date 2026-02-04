#include <stdio.h>

#include <inttypes.h>

typedef unsigned char DES_cblock[8];

extern  char *str;
extern DES_cblock *key1;
extern DES_cblock *key2;
extern int i;
extern size_t length;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Simulate indirect access by precomputing an index permutation array.
    // Here we use a simple indirect pattern: reverse traversal order.
    // This changes memory access to be non-consecutive and data-dependent.

    int idx[256]; // Assume max length is 256 for simplicity; could be dynamic in practice
    int n = (length > 256) ? 256 : (int)length;

    // Precompute reversed indices
    for (int k = 0; k < n; k++) {
        idx[k] = n - 1 - k;
    }

    for (i = 0; i < n; i++) {
        int actual_i = idx[i]; // Indirect access index
        register unsigned char j = str[actual_i];
        int mod32 = actual_i % 32;
        int mod16 = actual_i % 16;
        int mod8 = actual_i % 8;

        if (mod32 < 16) {
            if (mod16 < 8)
                (*key1)[mod8] ^= (j << 1);
            else
                (*key2)[mod8] ^= (j << 1);
        } else {
            j = ((j << 4) & 240) | ((j >> 4) & 15);
            j = ((j << 2) & 204) | ((j >> 2) & 51);
            j = ((j << 1) & 170) | ((j >> 1) & 85);
            if (mod16 < 8)
                (*key1)[7 - mod8] ^= j;
            else
                (*key2)[7 - mod8] ^= j;
        }
    }
}
