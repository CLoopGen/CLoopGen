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
    // Variant 1: Strided Memory Access (access every 2nd character, then handle remainder)
    long step = 2;
    long i;
    char *c_start = c;

    // First pass: strided access with step size 2
    for (n = 256; c[0] != '\x00' && c[step] != '\x00'; n += 256) {
        v = n | (case_adjust & c[0]);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c += step;
    }

    // Second pass: process remaining characters sequentially if needed
    while (c[0] != '\x00') {
        v = n | (case_adjust & *c);
        r = (int)((v >> 2) ^ v) & 15;
        ret = (ret << r) | (unsigned long)((uint64_t)ret >> (32 - r));
        ret &= 4294967295L;
        ret ^= v * v;
        c++;
    }

    c = c_start; // Reset pointer if necessary for consistency (though not strictly required)
}
