#include <stdio.h>

#include <inttypes.h>

extern int *diff;
extern int j;
extern int m1[8][8];
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 8; j++) {
    for (int k = 0; k < 4; k++) {
        m2[j][k] = diff[(j << 3) + k] + diff[(j << 3) + k + 4];
        m2[j][k + 4] = diff[(j << 3) + k] - diff[(j << 3) + k + 4];
    }
    for (int k = 0; k < 4; k += 2) {
        m1[j][k]     = m2[j][k] + m2[j][k + 1];
        m1[j][k + 1] = m2[j][k] - m2[j][k + 1];
    }
    for (int k = 0; k < 8; k += 2) {
        m2[j][k]     = m1[j][k] + m1[j][k + 1];
        m2[j][k + 1] = m1[j][k] - m1[j][k + 1];
    }
}
}
