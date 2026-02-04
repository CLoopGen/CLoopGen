#include <stdio.h>

#include <inttypes.h>

extern int ii;
extern int working[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (19 + 1) * (19 + 1);
    for (ii = 0; ii < limit; ii++) {
        working[ii] = (ii * ii + 3 * ii + 2) % 100;
    }
}
