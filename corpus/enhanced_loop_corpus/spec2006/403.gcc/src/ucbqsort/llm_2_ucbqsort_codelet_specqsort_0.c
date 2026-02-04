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
    // Variant 1: Strided memory access with step size of 2
    for (i = base, hi = base + qsz; i < hi; i += 2, j += 2) {
        if (i + 1 >= hi) break;
        c = *(j + 1);
        *(j + 1) = *i;
        *i = c;
    }
}
