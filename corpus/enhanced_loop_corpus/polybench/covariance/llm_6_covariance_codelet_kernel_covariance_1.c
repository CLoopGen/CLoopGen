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
        double temp_mean = 0.0;
        for (i = 0; i < n; i++) {
            temp_mean += data[i][j];
        }
        mean[j] = temp_mean / float_n;
    }
}
