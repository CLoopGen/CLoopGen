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
for (n2 = 0; n2 <= 6; n2 += 2) {
    for (n1 = 0; n1 <= 6; n1 += 2) {
        if (n2 >= 8 || n1 >= 8) continue;
        for (j = 0; j < 2; j++) {
            mb_y = n2 + j;
            int vals_i[4];
            for (i = 0; i < 4; i++) {
                vals_i[i] = predicted_chroma_block[i + n1][mb_y];
            }
            m5[0] = vals_i[0] + vals_i[3];
            m5[3] = vals_i[0] - vals_i[3];
            m5[1] = vals_i[1] + vals_i[2];
            m5[2] = vals_i[1] - vals_i[2];
            predicted_chroma_block[n1 + 0][mb_y] = m5[0] + m5[1];
            predicted_chroma_block[n1 + 2][mb_y] = m5[0] - m5[1];
            predicted_chroma_block[n1 + 1][mb_y] = m5[3] + m5[2] * 2;
            predicted_chroma_block[n1 + 3][mb_y] = m5[3] * 2 - m5[2];
        }
        for (i = 0; i < 2; i++) {
            j1 = n1 + i;
            int vals_j[4];
            for (j = 0; j < 4; j++) {
                vals_j[j] = predicted_chroma_block[j1][n2 + j];
            }
            m5[0] = vals_j[0] + vals_j[3];
            m5[3] = vals_j[0] - vals_j[3];
            m5[1] = vals_j[1] + vals_j[2];
            m5[2] = vals_j[1] - vals_j[2];
            predicted_chroma_block[j1][n2 + 0] = m5[0] + m5[1];
            predicted_chroma_block[j1][n2 + 2] = m5[0] - m5[1];
            predicted_chroma_block[j1][n2 + 1] = m5[3] + m5[2] * 2;
            predicted_chroma_block[j1][n2 + 3] = m5[3] * 2 - m5[2];
        }
    }
}
}
