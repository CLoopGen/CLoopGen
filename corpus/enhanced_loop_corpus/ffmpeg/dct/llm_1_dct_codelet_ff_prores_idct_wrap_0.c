#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*qmat);
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        qmat[i * 4 + 0] = 4;
        qmat[i * 4 + 1] = 4;
        qmat[i * 4 + 2] = 4;
        qmat[i * 4 + 3] = 4;
    }
}
