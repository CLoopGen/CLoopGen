#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int i1;
extern int m5[4];
extern int predicted_block[4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    int temp[4];
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        temp[i] = predicted_block[i][j] + predicted_block[i1][j];
        temp[i1] = predicted_block[i][j] - predicted_block[i1][j];
    }
    m5[0] = temp[0]; m5[1] = temp[1]; m5[2] = temp[2]; m5[3] = temp[3];
    predicted_block[0][j] = (m5[0] + m5[1]);
    predicted_block[2][j] = (m5[0] - m5[1]);
    predicted_block[1][j] = m5[3] * 2 + m5[2];
    predicted_block[3][j] = m5[3] - m5[2] * 2;
}
}
