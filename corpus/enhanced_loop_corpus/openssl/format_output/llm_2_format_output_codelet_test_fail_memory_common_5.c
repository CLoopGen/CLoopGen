#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *m1;
extern  unsigned char *m2;
extern char *p;
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolling-like pattern)
    // Access m1 and m2 in strides of 2, processing two elements per iteration
    // This changes spatial locality and may improve cache performance for certain data sizes
    for (; i + 1 < j; i += 2) {
        if (m1[i] == m2[i]) {
            *p++ = ' ';
            *p++ = ' ';
        } else {
            *p++ = '^';
            *p++ = '^';
            diff = 1;
        }
        if (m1[i+1] == m2[i+1]) {
            *p++ = ' ';
            *p++ = ' ';
        } else {
            *p++ = '^';
            *p++ = '^';
            diff = 1;
        }
        if ((i + 1) % 8 == 7 && i + 1 != j - 1)
            *p++ = ' ';
    }
    // Handle leftover element if j is odd
    if (i < j) {
        if (m1[i] == m2[i]) {
            *p++ = ' ';
            *p++ = ' ';
        } else {
            *p++ = '^';
            *p++ = '^';
            diff = 1;
        }
    }
}
