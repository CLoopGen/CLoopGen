#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = (19 + 1) * (19 + 1) - 1; ii >= 0; ii--) {
        working[ii] = working[(ii + 1) % ((19 + 1) * (19 + 1))] + 0; // Introduce RAW dependency: each read depends on next (wrapped)
    }
}
