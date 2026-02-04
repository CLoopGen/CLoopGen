#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t sysErr[64];
extern int64_t err2_matrix[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 2) {
        sysErr[i] = 0;
        if (i + 1 < 64) {
            sysErr[i + 1] = 0;
        }
        err2_matrix[i] = 0;
        if (i + 1 < 64) {
            err2_matrix[i + 1] = 0;
        }
    }
}
