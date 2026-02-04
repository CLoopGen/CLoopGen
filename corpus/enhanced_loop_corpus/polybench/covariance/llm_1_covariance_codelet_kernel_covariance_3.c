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
    for (j = 0; j < m; j++) {
        if (j < i) continue;
        cov[i][j] = 0.;
        for (k = 0; k < n; k++)
            cov[i][j] += data[k][i] * data[k][j];
        cov[i][j] /= (float_n - 1.);
        if (i != j)
            cov[j][i] = cov[i][j];
    }
}
