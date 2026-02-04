#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 4; j++) {
    for (int offset = 0; offset < 2; offset++) {
        int idx = j * 2 + offset;
        m2[idx][0] = diff[(idx << 3)] + diff[(idx << 3) + 4];
        m2[idx][1] = diff[(idx << 3) + 1] + diff[(idx << 3) + 5];
        m2[idx][2] = diff[(idx << 3) + 2] + diff[(idx << 3) + 6];
        m2[idx][3] = diff[(idx << 3) + 3] + diff[(idx << 3) + 7];
        m2[idx][4] = diff[(idx << 3)] - diff[(idx << 3) + 4];
        m2[idx][5] = diff[(idx << 3) + 1] - diff[(idx << 3) + 5];
        m2[idx][6] = diff[(idx << 3) + 2] - diff[(idx << 3) + 6];
        m2[idx][7] = diff[(idx << 3) + 3] - diff[(idx << 3) + 7];

        m1[idx][0] = m2[idx][0] + m2[idx][2];
        m1[idx][1] = m2[idx][1] + m2[idx][3];
        m1[idx][2] = m2[idx][0] - m2[idx][2];
        m1[idx][3] = m2[idx][1] - m2[idx][3];
        m1[idx][4] = m2[idx][4] + m2[idx][6];
        m1[idx][5] = m2[idx][5] + m2[idx][7];
        m1[idx][6] = m2[idx][4] - m2[idx][6];
        m1[idx][7] = m2[idx][5] - m2[idx][7];

        m2[idx][0] = m1[idx][0] + m1[idx][1];
        m2[idx][1] = m1[idx][0] - m1[idx][1];
        m2[idx][2] = m1[idx][2] + m1[idx][3];
        m2[idx][3] = m1[idx][2] - m1[idx][3];
        m2[idx][4] = m1[idx][4] + m1[idx][5];
        m2[idx][5] = m1[idx][4] - m1[idx][5];
        m2[idx][6] = m1[idx][6] + m1[idx][7];
        m2[idx][7] = m1[idx][6] - m1[idx][7];
    }
}
}
