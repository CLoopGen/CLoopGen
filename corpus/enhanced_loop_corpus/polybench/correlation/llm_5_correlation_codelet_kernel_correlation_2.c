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
        corr[i][j] = 0.;
        for (k = 0; k < n; k++) {
            if (data[k][i] == 0.0 || data[k][j] == 0.0) 
                continue;
            corr[i][j] += (data[k][i] * data[k][j]);
        }
        corr[j][i] = corr[i][j];
    }
}
}
