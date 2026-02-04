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
    int idx[4] = {0, 1, 2, 3}; // Direct indexing array to enable indirect access pattern
    for (j = 0; j < 2; j++) {
        j1 = 3 - j;
        m5[idx[j]] = predicted_block[i][idx[j]] + predicted_block[i][idx[j1]];
        m5[idx[j1]] = predicted_block[i][idx[j]] - predicted_block[i][idx[j1]];
    }
    predicted_block[i][idx[0]] = (m5[0] + m5[1]);
    predicted_block[i][idx[2]] = (m5[0] - m5[1]);
    predicted_block[i][idx[1]] = m5[3] * 2 + m5[2];
    predicted_block[i][idx[3]] = m5[3] - m5[2] * 2;
}
}
