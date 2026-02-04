#include <stdio.h>

extern double ten[1037][2];
extern int j1[1037][2];
extern int j2[1037][2];
extern int j3[1037][2];
extern int m;
extern int ind;
extern double temp;
extern int i;
extern int j_temp;



void loop(){
    // Variant 1: Consecutive Memory Access with Array Base Offset
    double *ten_col = &ten[0][ind];
    int *j1_col = &j1[0][ind];
    int *j2_col = &j2[0][ind];
    int *j3_col = &j3[0][ind];

    for (i = 0; i < m - 1; i++) {
        if (ten_col[i] < ten_col[i + 1]) {
            temp = ten_col[i + 1];
            ten_col[i + 1] = ten_col[i];
            ten_col[i] = temp;

            j_temp = j1_col[i + 1];
            j1_col[i + 1] = j1_col[i];
            j1_col[i] = j_temp;

            j_temp = j2_col[i + 1];
            j2_col[i + 1] = j2_col[i];
            j2_col[i] = j_temp;

            j_temp = j3_col[i + 1];
            j3_col[i + 1] = j3_col[i];
            j3_col[i] = j_temp;
        } else {
            return;
        }
    }
}
