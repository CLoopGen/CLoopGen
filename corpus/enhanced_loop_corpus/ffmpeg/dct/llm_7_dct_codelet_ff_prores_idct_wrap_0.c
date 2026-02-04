#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*qmat);
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        qmat[i] = 4;
        if (i > 0) {
            qmat[i] += qmat[i-1] - qmat[i-1]; // Introduces RAW and WAW loop-carried dependency, though value unchanged
        }
    }
}
