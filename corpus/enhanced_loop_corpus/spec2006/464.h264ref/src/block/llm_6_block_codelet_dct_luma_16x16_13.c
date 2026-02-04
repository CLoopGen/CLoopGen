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
    int temp_M5[4];
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        temp_M5[i] = M4[i][j] + M4[i1][j];
        temp_M5[i1] = M4[i][j] - M4[i1][j];
    }
    M4[0][j] = temp_M5[0] + temp_M5[1];
    M4[2][j] = temp_M5[0] - temp_M5[1];
    M4[1][j] = temp_M5[3] + temp_M5[2];
    M4[3][j] = temp_M5[3] - temp_M5[2];
}
}
