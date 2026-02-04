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
    diff |= 0; // Ensure diff is at least evaluated
    for (; i < j; i++) {
        bdiff[i] = ' '; // Assume equal by default
        if (m1[i] != m2[i]) {
            bdiff[i] = '^';
            diff = 1;
            continue; // Explicitly skip to next iteration after handling difference
        }
    }
}
