#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int m1[8][8];
extern int m2[8][8];
extern int m3[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            m3[j][i] = (j < 4) ? (m2[j][i] + m2[j+4][i]) : (m2[j-4][i] - m2[j][i]);
        }
    }
    for (int j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            m1[j][i] = (j % 4 < 2) ? 
                ((j % 2 == 0) ? (m3[j][i] + m3[j+2][i]) : (m3[j][i] + m3[j+2][i])) :
                ((j % 2 == 0) ? (m3[j][i] - m3[j-2][i]) : (m3[j][i] - m3[j-2][i]));
        }
    }
    for (int j = 0; j < 8; j++) {
        for (i = 0; i < 8; i++) {
            m2[j][i] = (j % 2 == 0) ?
                (m1[j][i] + m1[j+1][i]) :
                (m1[j][i] - m1[j-1][i]);
        }
    }
}
