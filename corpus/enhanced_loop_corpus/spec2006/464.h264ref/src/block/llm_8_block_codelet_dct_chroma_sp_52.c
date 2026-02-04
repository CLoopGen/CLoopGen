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
        for (j = 0; j < 4; j++) {
            mb_y = n2 + j;
            for (i = 0; i < 2; i++) {
                i1 = 3 - i;
                int temp_add = predicted_chroma_block[i + n1][mb_y] + predicted_chroma_block[i1 + n1][mb_y];
                int temp_sub = predicted_chroma_block[i + n1][mb_y] - predicted_chroma_block[i1 + n1][mb_y];
                m5[i] = temp_add;
                m5[i1] = temp_sub;
            }
            int sum_01 = m5[0] + m5[1];
            int diff_01 = m5[0] - m5[1];
            int comb_23_a = m5[3] * 2 + m5[2];
            int comb_23_b = m5[3] - m5[2] * 2;
            predicted_chroma_block[n1][mb_y] = sum_01;
            predicted_chroma_block[n1 + 2][mb_y] = diff_01;
            predicted_chroma_block[n1 + 1][mb_y] = comb_23_a;
            predicted_chroma_block[n1 + 3][mb_y] = comb_23_b;
        }
        for (i = 0; i < 4; i++) {
            j1 = n1 + i;
            for (j = 0; j < 2; j++) {
                j2 = 3 - j;
                int val_j = predicted_chroma_block[j1][n2 + j];
                int val_j2 = predicted_chroma_block[j1][n2 + j2];
                m5[j] = val_j + val_j2;
                m5[j2] = val_j - val_j2;
            }
            int sum_m5 = m5[0] + m5[1];
            int diff_m5 = m5[0] - m5[1];
            int comb_m5_23a = m5[3] * 2 + m5[2];
            int comb_m5_23b = m5[3] - m5[2] * 2;
            predicted_chroma_block[j1][n2 + 0] = sum_m5;
            predicted_chroma_block[j1][n2 + 2] = diff_m5;
            predicted_chroma_block[j1][n2 + 1] = comb_m5_23a;
            predicted_chroma_block[j1][n2 + 3] = comb_m5_23b;
        }
    }
}
}
