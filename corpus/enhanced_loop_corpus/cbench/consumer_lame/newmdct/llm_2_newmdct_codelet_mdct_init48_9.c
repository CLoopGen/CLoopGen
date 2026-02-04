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
    int idx = i * 2; // Strided access with step 2
    FLOAT8 w = wp[idx];
    mmax[i] = w / max;
    mmax[30 - i] = w / max;
    for (k = 0; k < 15; k++) {
        int src_idx = idx + k + 1; // Consecutive read after strided base
        wr[idx * 15 + k] = wp[src_idx] / w;
    }
}
}
