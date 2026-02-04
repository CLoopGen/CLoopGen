#include <stdio.h>

extern double ablock[5][5];
extern double bblock[5][5];
extern double cblock[5][5];
extern int j;



void loop(){
    for (j = 0; j < 5; j++) {
        double temp_a[5][5];
        double temp_b[5][5];
        double temp_c[5][5];

        // Transpose ablock and bblock to enable consecutive access in inner dimension
        for (int k = 0; k < 5; k++) {
            for (int i = 0; i < 5; i++) {
                temp_a[i][k] = ablock[k][i];
                temp_b[i][k] = bblock[k][i];
            }
        }

        // Use transposed data for more cache-friendly access
        for (int i = 0; i < 5; i++) {
            double sum = cblock[i][j];
            sum -= temp_a[0][i] * temp_b[j][0];
            sum -= temp_a[1][i] * temp_b[j][1];
            sum -= temp_a[2][i] * temp_b[j][2];
            sum -= temp_a[3][i] * temp_b[j][3];
            sum -= temp_a[4][i] * temp_b[j][4];
            cblock[i][j] = sum;
        }
    }
}
