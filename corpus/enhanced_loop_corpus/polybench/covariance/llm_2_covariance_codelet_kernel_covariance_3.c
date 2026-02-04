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
for (i = 0; i < m; i++)
    for (j = i; j < m; j++) {
        cov[i][j] = 0.;
        double temp = 0.;
        for (k = 0; k < n; k++)
            temp += data[k][i] * data[k][j];
        cov[i][j] = temp / (float_n - 1.);
        cov[j][i] = cov[i][j];
    }
}
