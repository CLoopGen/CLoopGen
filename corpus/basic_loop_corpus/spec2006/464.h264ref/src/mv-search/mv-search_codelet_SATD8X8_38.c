#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < 8; j++) {
    m2[j][0] = diff[(j << 3)] + diff[(j << 3) + 4];
    m2[j][1] = diff[(j << 3) + 1] + diff[(j << 3) + 5];
    m2[j][2] = diff[(j << 3) + 2] + diff[(j << 3) + 6];
    m2[j][3] = diff[(j << 3) + 3] + diff[(j << 3) + 7];
    m2[j][4] = diff[(j << 3)] - diff[(j << 3) + 4];
    m2[j][5] = diff[(j << 3) + 1] - diff[(j << 3) + 5];
    m2[j][6] = diff[(j << 3) + 2] - diff[(j << 3) + 6];
    m2[j][7] = diff[(j << 3) + 3] - diff[(j << 3) + 7];
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
