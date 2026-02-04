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
    if (n <= 1) return;
    for (i = n - 2; i >= 0; i--) {
        double temp = matrix[i][2] * r[i + 1];
        r[i] -= temp;
    }
}
