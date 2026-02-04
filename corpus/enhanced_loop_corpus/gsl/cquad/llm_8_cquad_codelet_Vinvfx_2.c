#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double V3inv[289];
extern  double *fx;
extern double *c;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 16; i += 2) {
        c[i] = 0.;
        if (i + 1 <= 16) c[i + 1] = 0.;
        for (j = 0; j <= 16; j++) {
            c[i] += V3inv[i * 17 + j] * fx[j * 2];
            if (i + 1 <= 16) {
                c[i + 1] += V3inv[(i + 1) * 17 + j] * fx[j * 2];
            }
        }
    }
}
