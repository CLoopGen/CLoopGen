#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 4 * 21 * 4 * 21; ii += 2) {
        dfa_p[ii] = 3;
        if (ii + 1 < 4 * 21 * 4 * 21) {
            dfa_p[ii + 1] = dfa_p[ii]; // Introduce RAW dependency: read what was just written
        }
    }
}
