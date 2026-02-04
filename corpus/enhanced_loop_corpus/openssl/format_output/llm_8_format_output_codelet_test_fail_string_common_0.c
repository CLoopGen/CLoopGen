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
    size_t step = 2;
    for (; i < j; i += step) {
        if (i + 1 < j) {
            // Process two elements per iteration
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
        } else {
            // Handle last element if j is odd
            if (m1[i] == m2[i]) {
                bdiff[i] = ' ';
            } else {
                bdiff[i] = '^';
                diff = 1;
            }
        }
    }
}
