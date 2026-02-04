#include <stdio.h>

#include <inttypes.h>

extern int qsz;
extern char *base;
extern char c;
extern char *i;
extern char *j;
extern char *hi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This variant processes elements at even indices only, swapping in a strided pattern
    for (i = base, hi = base + qsz; i < hi; i += 2, j += 2) {
        if (j >= hi) break;
        c = *j;
        *j = *i;
        *i = c;
    }
}
