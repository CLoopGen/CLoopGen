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
        int local_sum_1[4][4], local_diff_1[4][4];
        for (j = 0; j < 4; j++) {
            mb_y = n2 + j;
            for (i = 0; i < 2; i++) {
                i1 = 3 - i;
                local_sum_1[i][j] = predicted_chroma_block[i + n1][mb_y] + predicted_chroma_block[i1 + n1][mb_y];
                local_diff_1[i][j] = predicted_chroma_block[i + n1][mb_y] - predicted_chroma_block[i1 + n1][mb_y];
            }
            m5[0] = local_sum_1[0][j]; m5[1] = local_sum_1[1][j];
            m5[2] = local_diff_1[1][j]; m5[3] = local_diff_1[0][j];
            predicted_chroma_block[n1][mb_y] = (m5[0] + m5[1]);
            predicted_chroma_block[n1 + 2][mb_y] = (m5[0] - m5[1]);
            predicted_chroma_block[n1 + 1][mb_y] = m5[3] * 2 + m5[2];
            predicted_chroma_block[n1 + 3][mb_y] = m5[3] - m5[2] * 2;
        }
        int local_sum_2[4][2], local_diff_2[4][2];
        for (i = 0; i < 4; i++) {
            j1 = n1 + i;
            for (j = 0; j < 2; j++) {
                j2 = 3 - j;
                local_sum_2[i][j] = predicted_chroma_block[j1][n2 + j] + predicted_chroma_block[j1][n2 + j2];
                local_diff_2[i][j] = predicted_chroma_block[j1][n2 + j] - predicted_chroma_block[j1][n2 + j2];
            }
            m5[0] = local_sum_2[i][0]; m5[1] = local_sum_2[i][1];
            m5[2] = local_diff_2[i][1]; m5[3] = local_diff_2[i][0];
            predicted_chroma_block[j1][n2 + 0] = (m5[0] + m5[1]);
            predicted_chroma_block[j1][n2 + 2] = (m5[0] - m5[1]);
            predicted_chroma_block[j1][n2 + 1] = m5[3] * 2 + m5[2];
            predicted_chroma_block[j1][n2 + 3] = m5[3] - m5[2] * 2;
        }
    }
}
}
