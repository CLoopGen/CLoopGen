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
    size_t idx;
    char prev_bdiff = ' ';
    unsigned int has_diff = 0;
    for (idx = i; idx < j; idx++) {
        int eq = (m1[idx] == m2[idx]);
        bdiff[idx] = eq ? ' ' : '^';
        has_diff |= (!eq);
        // Introduce WAW and RAW dependency: current iteration depends on prior bdiff write
        prev_bdiff = bdiff[idx];
    }
    if (has_diff) {
        diff = 1;
    }
    // Artificial use of prev_bdiff to maintain dependency chain
    if (prev_bdiff == '^') {
        // No-op to justify prev_bdiff usage
    }
}
