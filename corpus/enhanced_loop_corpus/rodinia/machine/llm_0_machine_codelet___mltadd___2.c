#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int i;
extern int len4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < len4; j += 2) {
        for (i = j; i < j + 2 && i < len4; i++) {
            dp1[4 * i] += s * dp2[4 * i];
            dp1[4 * i + 1] += s * dp2[4 * i + 1];
            dp1[4 * i + 2] += s * dp2[4 * i + 2];
            dp1[4 * i + 3] += s * dp2[4 * i + 3];
        }
    }
}
