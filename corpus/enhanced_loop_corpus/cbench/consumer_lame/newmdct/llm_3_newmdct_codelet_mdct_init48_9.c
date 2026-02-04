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
// Use indirect addressing via index mapping arrays (simulated with simple arithmetic)
int indices[15];
for (int temp = 0; temp < 15; temp++) {
    indices[temp] = 14 - temp; // Reverse order indices
}
for (i = 14; i >= 0; --i) {
    int rev_i = indices[i]; // Indirect access using reverse mapping
    FLOAT8 w = wp[rev_i];
    mmax[i] = mmax[30 - i] = w / max;
    for (k = 0; k < 15; k++) {
        int wr_idx = i * 15 + k;
        int wp_idx = rev_i + k + 1; // Forward consecutive from reversed base
        wr[wr_idx] = wp[wp_idx] / w;
    }
}
}
