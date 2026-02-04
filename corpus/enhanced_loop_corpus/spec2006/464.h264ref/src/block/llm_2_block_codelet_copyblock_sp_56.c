#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int i1;
extern int m5[4];
extern int predicted_block[4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < 4; j++) {
    for (i = 0; i < 2; i++) {
        i1 = 3 - i;
        // Change memory access pattern to use consecutive indexing via pointer arithmetic
        int *pred_col = &predicted_block[0][j];
        m5[i] = pred_col[i] + pred_col[i1];
        m5[i1] = pred_col[i] - pred_col[i1];
    }
    int *pred_col = &predicted_block[0][j];
    pred_col[0] = (m5[0] + m5[1]);
    pred_col[2] = (m5[0] - m5[1]);
    pred_col[1] = m5[3] * 2 + m5[2];
    pred_col[3] = m5[3] - m5[2] * 2;
}
}
