#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int i1;
extern int M4[4][4];
extern int M5[4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        M5[i] = M4[i][j] + M4[i1][j];
        M5[i1] = M4[i][j] - M4[i1][j];
    }
    // Unroll the final assignments to eliminate temporary symmetry
    M4[0][j] = (M4[0][j] + M4[3][j]) + (M4[1][j] + M4[2][j]);
    M4[2][j] = (M4[0][j] - M4[3][j]) + (M4[1][j] - M4[2][j]);  // Reuse updated values not possible, so precompute
    M4[1][j] = (M4[1][j] - M4[2][j]) + (M4[0][j] - M4[3][j]);
    M4[3][j] = (M4[1][j] - M4[2][j]) - (M4[0][j] - M4[3][j]);
}
}
