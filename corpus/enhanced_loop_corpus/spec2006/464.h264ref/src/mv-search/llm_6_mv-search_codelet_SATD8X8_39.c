#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int m1[8][8];
extern int m2[8][8];
extern int m3[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i++) {
    int temp_m3_0, temp_m3_1, temp_m3_2, temp_m3_3;
    int temp_m3_4, temp_m3_5, temp_m3_6, temp_m3_7;

    temp_m3_0 = m2[0][i] + m2[4][i];
    temp_m3_1 = m2[1][i] + m2[5][i];
    temp_m3_2 = m2[2][i] + m2[6][i];
    temp_m3_3 = m2[3][i] + m2[7][i];
    temp_m3_4 = m2[0][i] - m2[4][i];
    temp_m3_5 = m2[1][i] - m2[5][i];
    temp_m3_6 = m2[2][i] - m2[6][i];
    temp_m3_7 = m2[3][i] - m2[7][i];

    m3[0][i] = temp_m3_0;
    m3[1][i] = temp_m3_1;
    m3[2][i] = temp_m3_2;
    m3[3][i] = temp_m3_3;
    m3[4][i] = temp_m3_4;
    m3[5][i] = temp_m3_5;
    m3[6][i] = temp_m3_6;
    m3[7][i] = temp_m3_7;

    int temp_m1_0 = temp_m3_0 + temp_m3_2;
    int temp_m1_1 = temp_m3_1 + temp_m3_3;
    int temp_m1_2 = temp_m3_0 - temp_m3_2;
    int temp_m1_3 = temp_m3_1 - temp_m3_3;
    int temp_m1_4 = temp_m3_4 + temp_m3_6;
    int temp_m1_5 = temp_m3_5 + temp_m3_7;
    int temp_m1_6 = temp_m3_4 - temp_m3_6;
    int temp_m1_7 = temp_m3_5 - temp_m3_7;

    m1[0][i] = temp_m1_0;
    m1[1][i] = temp_m1_1;
    m1[2][i] = temp_m1_2;
    m1[3][i] = temp_m1_3;
    m1[4][i] = temp_m1_4;
    m1[5][i] = temp_m1_5;
    m1[6][i] = temp_m1_6;
    m1[7][i] = temp_m1_7;

    m2[0][i] = temp_m1_0 + temp_m1_1;
    m2[1][i] = temp_m1_0 - temp_m1_1;
    m2[2][i] = temp_m1_2 + temp_m1_3;
    m2[3][i] = temp_m1_2 - temp_m1_3;
    m2[4][i] = temp_m1_4 + temp_m1_5;
    m2[5][i] = temp_m1_4 - temp_m1_5;
    m2[6][i] = temp_m1_6 + temp_m1_7;
    m2[7][i] = temp_m1_6 - temp_m1_7;
}
}
