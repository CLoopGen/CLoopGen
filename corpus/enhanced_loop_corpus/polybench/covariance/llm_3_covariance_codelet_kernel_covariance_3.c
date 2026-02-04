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
int stride = 1;
for (i = 0; i < m; i += stride)
    for (j = i; j < m; j++) {
        cov[i][j] = 0.;
        for (k = 0; k < n; k++) {
            int idx = k * stride;
            if (idx < n) 
                cov[i][j] += data[idx][i] * data[idx][j];
        }
        cov[i][j] /= (float_n - 1.);
        cov[j][i] = cov[i][j];
    }
}
