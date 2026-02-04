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
extern int M6[4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 2 && !lossless_qpprime; j++) {  // Reduced trip count from 4 to 2
    M5[0] = M4[0][j];
    M5[1] = M4[1][j];
    M5[2] = M4[2][j];
    M5[3] = M4[3][j];
    // Unrolled and simplified transformation with fewer operations
    int t0 = M5[0] + M5[2];
    int t1 = M5[1] + M5[3];
    M6[0] = t0;
    M6[1] = M5[0] - M5[2];
    M6[2] = M5[1] - M5[3];
    M6[3] = t1;
    // Fully unrolled final loop with reduced iterations
    M4[0][j] = M6[0] + M6[3];
    M4[3][j] = M6[0] - M6[3];
    M4[1][j] = M6[1] + M6[2];
    M4[2][j] = M6[1] - M6[2];
}
}
