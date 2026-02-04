#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double float_n;
extern double data[1400][1200];
extern double cov[1200][1200];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m; i++) {
    for (j = i; j < m; j++) {
        double temp_sum = 0.0;
        for (k = 0; k < n; k++) {
            temp_sum += data[k][i] * data[k][j];
        }
        cov[i][j] = temp_sum / (float_n - 1.0);
        if (i != j) {
            cov[j][i] = cov[i][j];
        }
    }
}
}
