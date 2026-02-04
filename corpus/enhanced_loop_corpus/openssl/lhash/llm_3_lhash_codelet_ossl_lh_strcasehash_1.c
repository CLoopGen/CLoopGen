#include <stdio.h>

#include <inttypes.h>

extern  char *c;
extern unsigned long ret;
extern long n;
extern unsigned long v;
extern int r;
extern  long case_adjust;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (simulated using offset array)
    long indices[256]; // Simulated index map for indirect access
    long len = 0;
    char *temp_c = c;

    // Precompute a non-trivial access pattern (reverse order in chunks up to 256)
    while (temp_c[len] != '\x00' && len < 255) len++;
    for (long i = 0; i < len; i++) {
        indices[i] = len - 1 - i; // Reverse indexing
    }

    // Use indirect access through the indices array
    for (n = 256, len = 0; c[len] != '\x00'; n += 256) {
        char current_char = c[indices[len % 256]]; // Indirect access
        v = n | (case_adjust & current_char);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        len++;
    }
}
