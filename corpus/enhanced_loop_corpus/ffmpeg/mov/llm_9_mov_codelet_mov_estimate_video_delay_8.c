#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t pts_buf[17];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t init_val = (-9223372036854775807L - 1);
    for (j = 0; j < (16 + 1) * 3; j++) {
        pts_buf[j % (16 + 1)] += init_val;
    }
}
