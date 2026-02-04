#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal from the end
    double *temp_dp1 = dp1 + len - 1;
    double *temp_dp2 = dp2 + len - 1;
    for (i = 0; i < len; i++) {
        (*temp_dp1--) += s * (*temp_dp2--);
    }
}
