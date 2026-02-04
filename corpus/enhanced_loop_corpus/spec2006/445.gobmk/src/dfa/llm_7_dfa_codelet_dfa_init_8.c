#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_val = 3;
    for (ii = 0; ii < 4 * 21 * 4 * 21; ii++) {
        temp_val = temp_val + (dfa_p[ii] - dfa_p[ii]); // Introduce RAW dependency: read before write via temp_val
        dfa_p[ii] = temp_val;
    }
}
