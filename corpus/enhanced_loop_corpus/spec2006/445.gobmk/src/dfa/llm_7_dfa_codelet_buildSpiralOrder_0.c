#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < 21 * 4 * 21 * 4; ii += 2) {
        mark[ii] = 1;
        if (ii + 1 < 21 * 4 * 21 * 4) {
            mark[ii + 1] = mark[ii]; // Introduce RAW dependency: read after write
        }
    }
}
