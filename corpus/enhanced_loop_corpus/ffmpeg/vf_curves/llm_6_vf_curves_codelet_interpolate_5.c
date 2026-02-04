#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double (*matrix)[3];
extern double *r;
extern  int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp = r[n - 1];
    for (i = n - 2; i >= 0; i--) {
        double next_r = r[i + 1];
        r[i] = r[i] - matrix[i][2] * next_r;
        temp = next_r;
    }
}
