#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int i;
extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;
extern FLOAT8 mmax[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 temp_mmax[31];
    FLOAT8 local_wr[450]; // Buffer to hold output and reduce memory aliasing
    int wr_idx = 0;

    for (i = 14; i >= 0; --i) {
        FLOAT8 w = *wp++;
        temp_mmax[i] = w / max;
        temp_mmax[30 - i] = w / max;

        for (k = 0; k < 15; k++) {
            local_wr[wr_idx++] = *wp++ / w; // Accumulate in local array to break WR dependence on global wr
        }
    }

    // Finalize: copy back to original arrays to preserve semantics
    for (i = 0; i < 31; i++) {
        mmax[i] = temp_mmax[i];
    }
    for (i = 0; i < 450; i++) {
        wr[i] = local_wr[i];
    }
}
