#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern int i;
extern int j;
extern int _usr_j1;
extern int M4[4][4];
extern int M5[4];
extern Boolean lossless_qpprime;

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 4 && !lossless_qpprime; i++) {
    int idxs[4] = {0, 1, 2, 3};  // Indirect access indices
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        M5[idxs[j]] = M4[i][idxs[j]] + M4[i][idxs[j1]];
        M5[idxs[j1]] = M4[i][idxs[j]] - M4[i][idxs[j1]];
    }
    M4[i][idxs[0]] = (M5[idxs[0]] + M5[idxs[1]]) >> 1;
    M4[i][idxs[2]] = (M5[idxs[0]] - M5[idxs[1]]) >> 1;
    M4[i][idxs[1]] = (M5[idxs[3]] + M5[idxs[2]]) >> 1;
    M4[i][idxs[3]] = (M5[idxs[3]] - M5[idxs[2]]) >> 1;
}
}
