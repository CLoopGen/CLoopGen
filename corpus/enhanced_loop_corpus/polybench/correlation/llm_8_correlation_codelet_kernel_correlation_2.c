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
for (i = 0; i < m; i++) {
    corr[i][i] = 1.;
    for (j = i + 1; j < m; j++) {
        double sum = 0.;
        for (k = 0; k < n; k += 4) {
            sum += data[k][i] * data[k][j];
            if (k + 1 < n) sum += data[k+1][i] * data[k+1][j];
            if (k + 2 < n) sum += data[k+2][i] * data[k+2][j];
            if (k + 3 < n) sum += data[k+3][i] * data[k+3][j];
        }
        corr[i][j] = sum;
        corr[j][i] = sum;
    }
}
}
