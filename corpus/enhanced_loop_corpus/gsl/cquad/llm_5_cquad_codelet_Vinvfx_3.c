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
    c[0] = 0.0;
    for (i = 0; i <= 32; i++) {
        if (i > 0)
            c[i] = 0.0;
        for (j = 0; j <= 32; j++) {
            if (!(i == 16 && j == 16)) // Skip the center element
                c[i] += V4inv[i * 33 + j] * fx[j];
        }
    }
}
