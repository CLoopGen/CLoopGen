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
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        if (M4[i][j] >= M4[i][j1]) {
            M5[j] = M4[i][j] + M4[i][j1];
            M5[j1] = M4[i][j] - M4[i][j1];
        } else {
            M5[j] = M4[i][j1] + M4[i][j];
            M5[j1] = M4[i][j1] - M4[i][j];
        }
    }
    M4[i][0] = (M5[0] + M5[1]) >> 1;
    M4[i][2] = (M5[0] - M5[1]) >> 1;
    M4[i][1] = (M5[3] + M5[2]) >> 1;
    M4[i][3] = (M5[3] - M5[2]) >> 1;
}
}
