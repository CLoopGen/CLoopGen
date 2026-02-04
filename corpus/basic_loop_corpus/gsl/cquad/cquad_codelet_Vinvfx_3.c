#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V4inv[1089];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i <= 32; i++) {
    c[i] = 0.;
    for (j = 0; j <= 32; j++)
        c[i] += V4inv[i * 33 + j] * fx[j];
}

}
