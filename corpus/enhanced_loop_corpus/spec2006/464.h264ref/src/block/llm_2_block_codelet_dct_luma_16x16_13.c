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
    int idx[4] = {0, 1, 2, 3}; // Direct index mapping for consecutive access
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        M5[idx[i]] = M4[idx[i]][j] + M4[idx[i1]][j];
        M5[idx[i1]] = M4[idx[i]][j] - M4[idx[i1]][j];
    }
    M4[0][j] = M5[0] + M5[1];
    M4[2][j] = M5[0] - M5[1];
    M4[1][j] = M5[3] + M5[2];
    M4[3][j] = M5[3] - M5[2];
}
}
