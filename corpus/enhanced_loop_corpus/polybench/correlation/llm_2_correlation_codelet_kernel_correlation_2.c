#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double data[1400][1200];
extern double corr[1200][1200];
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < m - 1; i++) {
    corr[i][i] = 1.;
    for (j = i + 1; j < m; j++) {
        double sum = 0.;
        for (k = 0; k < n; k += 2) {
            if (k + 1 < n) {
                sum += (data[k][i] * data[k][j]) + (data[k+1][i] * data[k+1][j]);
            } else {
                sum += (data[k][i] * data[k][j]);
            }
        }
        corr[i][j] = sum;
        corr[j][i] = sum;
    }
}
}
