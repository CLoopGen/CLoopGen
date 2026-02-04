#include <stdio.h>

#include <inttypes.h>

extern  char *m1;
extern  char *m2;
extern char bdiff[81];
extern size_t i;
extern unsigned int diff;
extern  size_t j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t unroll_factor = 4;
    size_t limit = j - (j % unroll_factor);
    for (; i < limit; i += unroll_factor) {
        // Unrolled: four comparisons per iteration
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
        if (m1[i+1] == m2[i+1]) {
            bdiff[i+1] = ' ';
        } else {
            bdiff[i+1] = '^';
            diff = 1;
        }
        if (m1[i+2] == m2[i+2]) {
            bdiff[i+2] = ' ';
        } else {
            bdiff[i+2] = '^';
            diff = 1;
        }
        if (m1[i+3] == m2[i+3]) {
            bdiff[i+3] = ' ';
        } else {
            bdiff[i+3] = '^';
            diff = 1;
        }
    }
    // Handle remaining elements
    for (; i < j; i++) {
        if (m1[i] == m2[i]) {
            bdiff[i] = ' ';
        } else {
            bdiff[i] = '^';
            diff = 1;
        }
    }
}
