#include <stdio.h>

#include <inttypes.h>

extern int dfa_p[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = 0; ii < 4 * 21 * 4 * 21; ii++) {
    if (ii % 2 == 0)
        continue;
    dfa_p[ii] = 3;
}
}
