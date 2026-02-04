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
for (i = 0; i < m - 1; i += 2) {
    if (i < m) {
        corr[i][i] = 1.;
        for (j = i + 1; j < m; j++) {
            corr[i][j] = 0.;
            for (k = 0; k < n; k++) {
                corr[i][j] += data[k][i] * data[k][j];
            }
            corr[j][i] = corr[i][j];
        }
    }
    if (i + 1 < m) {
        corr[i+1][i+1] = 1.;
        for (j = i + 2; j < m; j++) {
            corr[i+1][j] = 0.;
            for (k = 0; k < n; k++) {
                corr[i+1][j] += data[k][i+1] * data[k][j];
            }
            corr[j][i+1] = corr[i+1][j];
        }
    }
}
}
