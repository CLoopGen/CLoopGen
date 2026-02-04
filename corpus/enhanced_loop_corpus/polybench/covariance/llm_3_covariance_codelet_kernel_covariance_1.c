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
int index;
for (j = 0; j < m; j++) {
    mean[j] = 0.;
    for (index = j; index < n * 1200; index += 1200)
        mean[j] += data[index % 1400][j];
    mean[j] /= float_n;
}
}
