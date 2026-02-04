#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int m1[8][8];
extern int m2[8][8];
extern int m3[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int j = i % 8;
    m3[0][j] = m2[0][j] + m2[4][j];
    m3[1][j] = m2[1][j] + m2[5][j];
    m3[2][j] = m2[2][j] + m2[6][j];
    m3[3][j] = m2[3][j] + m2[7][j];
    m3[4][j] = m2[0][j] - m2[4][j];
    m3[5][j] = m2[1][j] - m2[5][j];
    m3[6][j] = m2[2][j] - m2[6][j];
    m3[7][j] = m2[3][j] - m2[7][j];

    m1[0][j] = m3[0][j] + m3[2][j];
    m1[1][j] = m3[1][j] + m3[3][j];
    m1[2][j] = m3[0][j] - m3[2][j];
    m1[3][j] = m3[1][j] - m3[3][j];
    m1[4][j] = m3[4][j] + m3[6][j];
    m1[5][j] = m3[5][j] + m3[7][j];
    m1[6][j] = m3[4][j] - m3[6][j];
    m1[7][j] = m3[5][j] - m3[7][j];

    m2[0][j] = m1[0][j] + m1[1][j];
    m2[1][j] = m1[0][j] - m1[1][j];
    m2[2][j] = m1[2][j] + m1[3][j];
    m2[3][j] = m1[2][j] - m1[3][j];
    m2[4][j] = m1[4][j] + m1[5][j];
    m2[5][j] = m1[4][j] - m1[5][j];
    m2[6][j] = m1[6][j] + m1[7][j];
    m2[7][j] = m1[6][j] - m1[7][j];

    if (i >= 8) {
        m3[0][j] *= 2;
        m1[0][j] *= 2;
        m2[0][j] *= 2;
    }
}
}
