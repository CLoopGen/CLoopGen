#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int i1;
extern int j2;
extern int n2;
extern int n1;
extern int _usr_j1;
extern int mb_y;
extern int m5[4];
extern int predicted_chroma_block[8][8];

// Variable name mappings to avoid conflicts with system symbols
#define j1 _usr_j1



void loop(){
for (n2 = 0; n2 <= 4; n2 += 4) {
    for (n1 = 0; n1 <= 4; n1 += 4) {
        // Change memory access to consecutive row-major processing using local cache
        int temp_block[4][4];
        // Preload 4x4 block into local array for spatial locality
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                temp_block[i][j] = predicted_chroma_block[n1 + i][n2 + j];
            }
        }
        // First pass: transform rows
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 2; i++) {
                i1 = 3 - i;
                m5[i] = temp_block[i][j] + temp_block[i1][j];
                m5[i1] = temp_block[i][j] - temp_block[i1][j];
            }
            temp_block[0][j] = (m5[0] + m5[1]);
            temp_block[2][j] = (m5[0] - m5[1]);
            temp_block[1][j] = m5[3] * 2 + m5[2];
            temp_block[3][j] = m5[3] - m5[2] * 2;
        }
        // Second pass: transform columns
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 2; j++) {
                j2 = 3 - j;
                m5[j] = temp_block[i][j] + temp_block[i][j2];
                m5[j2] = temp_block[i][j] - temp_block[i][j2];
            }
            temp_block[i][0] = (m5[0] + m5[1]);
            temp_block[i][2] = (m5[0] - m5[1]);
            temp_block[i][1] = m5[3] * 2 + m5[2];
            temp_block[i][3] = m5[3] - m5[2] * 2;
        }
        // Store back transformed block
        for (j = 0; j < 4; j++) {
            for (i = 0; i < 4; i++) {
                predicted_chroma_block[n1 + i][n2 + j] = temp_block[i][j];
            }
        }
    }
}
}
