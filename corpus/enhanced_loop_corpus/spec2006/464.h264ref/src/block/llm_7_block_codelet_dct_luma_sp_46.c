#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int _usr_j1;
extern int m5[4];
extern int predicted_block[4][4];

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (i = 0; i < 4; i++) {
    int m5_local[4];
    m5_local[0] = predicted_block[i][0] + predicted_block[i][3];
    m5_local[1] = predicted_block[i][1] + predicted_block[i][2];
    m5_local[3] = predicted_block[i][0] - predicted_block[i][3];
    m5_local[2] = predicted_block[i][1] - predicted_block[i][2];

    predicted_block[i][0] = (m5_local[0] + m5_local[1]);
    predicted_block[i][2] = (m5_local[0] - m5_local[1]);
    predicted_block[i][1] = m5_local[3] * 2 + m5_local[2];
    predicted_block[i][3] = m5_local[3] - m5_local[2] * 2;
}
}
