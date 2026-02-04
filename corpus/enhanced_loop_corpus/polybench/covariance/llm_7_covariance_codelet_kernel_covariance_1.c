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
        mean[j] = 0.0;
        #pragma unroll
        for (i = 0; i < n - (n % 4); i += 4) {
            mean[j] += data[i][j] + data[i+1][j] + data[i+2][j] + data[i+3][j];
        }
        for (; i < n; i++) {
            mean[j] += data[i][j];
        }
        mean[j] /= float_n;
    }
}
