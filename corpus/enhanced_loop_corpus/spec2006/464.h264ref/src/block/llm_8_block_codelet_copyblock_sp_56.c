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
    for (i = 0; i < 4; i++) {
        i1 = 3 - i;
        m5[i] = predicted_block[i][j] + predicted_block[i1][j];
    }
    predicted_block[0][j] = m5[0] + m5[3];
    predicted_block[1][j] = m5[1] + m5[2];
    predicted_block[2][j] = m5[0] - m5[3];
    predicted_block[3][j] = m5[1] - m5[2];
}
}
