#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 8; j++) {
    int base = j << 3;
    int d0 = diff[base];
    int d1 = diff[base + 1];
    int d2 = diff[base + 2];
    int d3 = diff[base + 3];
    int d4 = diff[base + 4];
    int d5 = diff[base + 5];
    int d6 = diff[base + 6];
    int d7 = diff[base + 7];

    m2[j][0] = d0 + d4;
    m2[j][1] = d1 + d5;
    m2[j][2] = d2 + d6;
    m2[j][3] = d3 + d7;
    m2[j][4] = d0 - d4;
    m2[j][5] = d1 - d5;
    m2[j][6] = d2 - d6;
    m2[j][7] = d3 - d7;

    int m20 = m2[j][0], m21 = m2[j][1], m22 = m2[j][2], m23 = m2[j][3];
    int m24 = m2[j][4], m25 = m2[j][5], m26 = m2[j][6], m27 = m2[j][7];

    m1[j][0] = m20 + m22;
    m1[j][1] = m21 + m23;
    m1[j][2] = m20 - m22;
    m1[j][3] = m21 - m23;
    m1[j][4] = m24 + m26;
    m1[j][5] = m25 + m27;
    m1[j][6] = m24 - m26;
    m1[j][7] = m25 - m27;

    int m10 = m1[j][0], m11 = m1[j][1], m12 = m1[j][2], m13 = m1[j][3];
    int m14 = m1[j][4], m15 = m1[j][5], m16 = m1[j][6], m17 = m1[j][7];

    m2[j][0] = m10 + m11;
    m2[j][1] = m10 - m11;
    m2[j][2] = m12 + m13;
    m2[j][3] = m12 - m13;
    m2[j][4] = m14 + m15;
    m2[j][5] = m14 - m15;
    m2[j][6] = m16 + m17;
    m2[j][7] = m16 - m17;
}
}
