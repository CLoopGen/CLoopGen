#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ii = 0; ii < (19 + 1) * (19 + 1); ii += 2) {
        working[ii] = 0;
        if (ii + 1 < (19 + 1) * (19 + 1)) {
            working[ii + 1] = 0;
        }
    }
}
