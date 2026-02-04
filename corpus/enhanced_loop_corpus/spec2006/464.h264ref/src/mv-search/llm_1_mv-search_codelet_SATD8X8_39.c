#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int m1[8][8];
extern int m2[8][8];
extern int m3[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8; ++i) {
        int temp_m3[8], temp_m1[8];
        for (int k = 0; k < 4; ++k) {
            temp_m3[k]     = m2[k][i] + m2[k+4][i];
            temp_m3[k+4]   = m2[k][i] - m2[k+4][i];
        }
        for (int k = 0; k < 4; ++k) {
            temp_m1[k]     = temp_m3[k] + temp_m3[k+2];
            temp_m1[k+4]   = temp_m3[k+4] + temp_m3[k+6];
            if (k < 2) {
                temp_m1[k+2] = temp_m3[k] - temp_m3[k+2];
                temp_m1[k+6] = temp_m3[k+4] - temp_m3[k+6];
            }
        }
        for (int k = 0; k < 8; k += 2) {
            m2[k][i]   = temp_m1[k] + temp_m1[k+1];
            m2[k+1][i] = temp_m1[k] - temp_m1[k+1];
        }
    }
}
