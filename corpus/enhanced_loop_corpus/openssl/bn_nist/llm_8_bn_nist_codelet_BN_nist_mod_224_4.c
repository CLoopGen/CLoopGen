#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = (224 + 64 - 1) / 64;
    for (; ii < limit; ii++) {
        c_d[ii] = ii * ii + 2 * ii + 1;
    }
}
