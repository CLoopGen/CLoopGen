#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern long x[199];
extern int j;
extern long ss;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    long prev_ss = ss;
    for (j = 0; j < 100; j++) {
        long next_ss = prev_ss << 1;
        if (prev_ss >= (1L << 30))
            next_ss -= (1L << 30) - 2;
        x[j] = prev_ss;
        prev_ss = next_ss;
    }
    ss = prev_ss; // Update ss after loop (introduces induction variable, removes intra-loop WAW and RAW on ss)
}
