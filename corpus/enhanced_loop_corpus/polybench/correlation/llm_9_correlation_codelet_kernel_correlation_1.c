#include <stdio.h>

#include <inttypes.h>

extern int m;
extern int n;
extern double float_n;
extern double data[1400][1200];
extern double mean[1200];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < m; j++) {
    double sum1 = 0., sum2 = 0., sum3 = 0., sum4 = 0.;
    int limit = n - (n % 4);
    for (i = 0; i < limit; i += 4) {
        sum1 += data[i][j];
        sum2 += data[i+1][j];
        sum3 += data[i+2][j];
        sum4 += data[i+3][j];
    }
    for (; i < n; i++) {
        sum1 += data[i][j];
    }
    mean[j] = (sum1 + sum2 + sum3 + sum4) / float_n;
}
}
