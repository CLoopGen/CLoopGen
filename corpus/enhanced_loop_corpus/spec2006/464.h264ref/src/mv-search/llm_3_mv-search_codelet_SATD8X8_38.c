#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; j++) {
    int idx[8];
    for (int k = 0; k < 8; k++) {
        idx[k] = (j << 3) + k;
    }
    m2[j][0] = diff[idx[0]] + diff[idx[4]];
    m2[j][1] = diff[idx[1]] + diff[idx[5]];
    m2[j][2] = diff[idx[2]] + diff[idx[6]];
    m2[j][3] = diff[idx[3]] + diff[idx[7]];
    m2[j][4] = diff[idx[0]] - diff[idx[4]];
    m2[j][5] = diff[idx[1]] - diff[idx[5]];
    m2[j][6] = diff[idx[2]] - diff[idx[6]];
    m2[j][7] = diff[idx[3]] - diff[idx[7]];
    m1[j][0] = m2[j][0] + m2[j][2];
    m1[j][1] = m2[j][1] + m2[j][3];
    m1[j][2] = m2[j][0] - m2[j][2];
    m1[j][3] = m2[j][1] - m2[j][3];
    m1[j][4] = m2[j][4] + m2[j][6];
    m1[j][5] = m2[j][5] + m2[j][7];
    m1[j][6] = m2[j][4] - m2[j][6];
    m1[j][7] = m2[j][5] - m2[j][7];
    m2[j][0] = m1[j][0] + m1[j][1];
    m2[j][1] = m1[j][0] - m1[j][1];
    m2[j][2] = m1[j][2] + m1[j][3];
    m2[j][3] = m1[j][2] - m1[j][3];
    m2[j][4] = m1[j][4] + m1[j][5];
    m2[j][5] = m1[j][4] - m1[j][5];
    m2[j][6] = m1[j][6] + m1[j][7];
    m2[j][7] = m1[j][6] - m1[j][7];
}
}
