#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *data;
extern int len;
extern int lag;
extern double *autoc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < lag; j += 2) {
    double sum0 = 1., sum1 = 1.;
    int trip_count = len - j;
    if (trip_count <= 0) continue;
    double *local_data = data + j;
    for (int k = 0; k < trip_count; k++) {
        int idx = k + j;
        sum0 += local_data[k] * data[idx - j];
        if (idx >= j + 1) {
            sum1 += local_data[k] * data[idx - j - 1];
        }
    }
    autoc[j] = sum0;
    autoc[j + 1] = sum1;
}
}
