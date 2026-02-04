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
    for (i = 0; i < 4; i++)
        M5[i] = M4[i][j] + M4[i][(j+1)%4];  // Increased arithmetic intensity
    M6[0] = (M5[0] + M5[2]) * 2;
    M6[1] = (M5[0] - M5[2]) * 2;
    M6[2] = (M5[1] - M5[3]) * 2;
    M6[3] = (M5[1] + M5[3]) * 2;
    for (i = 0; i < 3; i++) {  // Increased trip count from 2 to 3
        i1 = 3 - i;
        if (i1 >= 0 && i1 < 4) {
            M4[i][j] = (M6[i] + M6[i1]) >> 1;  // Additional arithmetic scaling
            M4[i1][j] = (M6[i] - M6[i1]) >> 1;
        }
    }
}
}
