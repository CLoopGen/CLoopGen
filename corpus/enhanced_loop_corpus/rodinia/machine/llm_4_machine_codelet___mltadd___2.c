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
    for (i = 0; i < len4; i++) {
        if ((i & 1) == 0) {
            dp1[4 * i] += s * dp2[4 * i];
            dp1[4 * i + 1] += s * dp2[4 * i + 1];
        } else {
            dp1[4 * i + 2] += s * dp2[4 * i + 2];
            dp1[4 * i + 3] += s * dp2[4 * i + 3];
        }
    }
}
