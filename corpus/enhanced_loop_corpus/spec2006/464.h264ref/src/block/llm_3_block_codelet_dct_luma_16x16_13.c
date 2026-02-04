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
for (j = 0; j < 4 && !lossless_qpprime; j += 2) { // Strided access: j increases by 2
    int j2 = j + 1;
    if (j2 >= 4) break;
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        // Process two columns at once using strided memory access pattern
        M5[i] = M4[i][j] + M4[i1][j];
        M5[i1] = M4[i][j] - M4[i1][j];
        M5[(i + 2) % 4] = M4[i][j2] + M4[i1][j2];   // Stride-2 access in j dimension
        M5[(i1 + 2) % 4] = M4[i][j2] - M4[i1][j2];
    }
    // Update both columns with computed values
    M4[0][j] = M5[0] + M5[1];
    M4[2][j] = M5[0] - M5[1];
    M4[1][j] = M5[3] + M5[2];
    M4[3][j] = M5[3] - M5[2];

    M4[0][j2] = M5[2] + M5[3];
    M4[2][j2] = M5[2] - M5[3];
    M4[1][j2] = M5[1] + M5[0];
    M4[3][j2] = M5[1] - M5[0];
}
}
