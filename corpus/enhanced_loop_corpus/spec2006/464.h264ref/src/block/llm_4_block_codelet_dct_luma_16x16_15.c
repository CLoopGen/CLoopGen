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
for (j = 0; j < 4 && !lossless_qpprime; j++) {
    if (j % 2 == 0) {
        for (i = 0; i < 4; i++)
            M5[i] = M4[i][j];
        M6[0] = M5[0] + M5[2];
        M6[1] = M5[0] - M5[2];
        M6[2] = M5[1] - M5[3];
        M6[3] = M5[1] + M5[3];
        for (i = 0; i < 2; i++) {
            i1 = 3 - i;
            M4[i][j] = M6[i] + M6[i1];
            M4[i1][j] = M6[i] - M6[i1];
        }
    } else {
        continue;
    }
}
}
