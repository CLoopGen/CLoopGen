#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4 * 21 * 4 * 21; ii++) {
    dfa_p[ii] = 3;
    if (ii == 4 * 21 * 4 * 21 / 2)
        ii += 10;  // Skip a few iterations halfway through
}
}
