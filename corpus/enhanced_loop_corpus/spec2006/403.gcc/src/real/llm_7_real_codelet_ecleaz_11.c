#include <stdio.h>

#include <inttypes.h>

extern unsigned short *xi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned short local_buffer[9];
    for (i = 0; i < (6 + 3); i++) {
        local_buffer[i] = 0;  // Eliminate all loop-carried dependencies; no writes to global xi yet
    }
    // Strip-mined store: remove data dependencies during computation phase
    for (i = 0; i < (6 + 3); i++) {
        *xi++ = local_buffer[i];  // Final independent stores with no intra-loop dependency
    }
}
