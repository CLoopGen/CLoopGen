#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int i1;
extern int m5[4];
extern int predicted_block[4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j += 2) {
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        int temp1 = predicted_block[i][j] + predicted_block[i1][j];
        int temp2 = predicted_block[i][j] - predicted_block[i1][j];
        m5[i] = temp1 + temp2;
        m5[i1] = temp1 - temp2;
    }
    predicted_block[0][j]   = m5[0] + m5[1] + m5[2];
    predicted_block[2][j]   = m5[0] - m5[1];
    predicted_block[1][j]   = m5[3] + m5[2];
    predicted_block[3][j]   = m5[3] - m5[2];
    if (j + 1 < 4) {
        predicted_block[0][j+1] = m5[0] * 2;
        predicted_block[1][j+1] = m5[1] * 2;
        predicted_block[2][j+1] = m5[2] * 2;
        predicted_block[3][j+1] = m5[3] * 2;
    }
}
}
