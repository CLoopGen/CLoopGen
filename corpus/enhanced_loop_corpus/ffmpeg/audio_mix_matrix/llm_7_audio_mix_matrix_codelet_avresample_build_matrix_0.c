#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t in_layout;
extern uint64_t out_layout;
extern int i;
extern double matrix[64][64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        int j;
        matrix[i][i] = 0.; // WAW dependency: potential overwriting in same location across iterations (though not carried here due to unique i)
        if (in_layout & out_layout & (1ULL << i)) {
            for (j = 0; j < 1; j++) { // Artificial inner loop to create intra-iteration data flow (RAW: read after write of matrix[i][i])
                matrix[i][i] += 1.;   // Read-modify-write pattern introduces RAW dependency on the previous assignment
            }
        }
    }
}
