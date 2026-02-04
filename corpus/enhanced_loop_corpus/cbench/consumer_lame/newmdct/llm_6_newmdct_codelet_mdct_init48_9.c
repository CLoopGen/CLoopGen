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
    for (i = 14; i >= 0; --i) {
        FLOAT8 w = wp[i]; // Removed pointer arithmetic side effect, eliminate RAW dependency on *wp++
        mmax[i] = w / max;
        mmax[30 - i] = w / max; // Split the write to remove WAW dependency in same iteration
        for (k = 0; k < 15; k++) {
            int src_idx = 15 + i * 15 + k; // Precompute index to remove cumulative wr/wp updates
            wr[src_idx] = wp[src_idx] / w; // Eliminate loop-carried dependency via direct indexing
        }
    }
}
