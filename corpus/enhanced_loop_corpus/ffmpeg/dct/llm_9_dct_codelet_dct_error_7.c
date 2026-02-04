#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int64_t sysErr[64];
extern int64_t err2_matrix[64];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        int idx = i >> 1; // equivalent to i / 2
        if (idx < 64) {
            sysErr[idx] = 0;
            err2_matrix[idx] = 0;
        }
    }
}
