#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*qmat);
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t val = 1;
    for (i = 0; i < 16; i++) {
        qmat[i * 4] = val;
        qmat[i * 4 + 1] = val + 1;
        qmat[i * 4 + 2] = val + 2;
        qmat[i * 4 + 3] = val + 3;
    }
}
