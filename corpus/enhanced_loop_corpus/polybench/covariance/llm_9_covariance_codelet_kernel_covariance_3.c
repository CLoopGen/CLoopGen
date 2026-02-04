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
for (i = 0; i < m; i += 2) {
    for (j = i; j < m; j++) {
        double sum1 = 0., sum2 = 0.;
        int k;
        for (k = 0; k < n; k++) {
            sum1 += data[k][i] * data[k][j];
            if (i + 1 < m)
                sum2 += data[k][i+1] * data[k][j];
        }
        cov[i][j] = sum1 / (float_n - 1.);
        cov[j][i] = cov[i][j];
        if (i + 1 < m) {
            cov[i+1][j] = sum2 / (float_n - 1.);
            cov[j][i+1] = cov[i+1][j];
        }
    }
}
}
