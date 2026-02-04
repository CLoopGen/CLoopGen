#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern int len;
extern int i;
extern double sum0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum0 = 0.0;
    for (i = 0; i < len; i++) {
        if (*dp1 != 0.0 && *dp2 != 0.0) {
            sum0 += (*dp1) * (*dp2);
        }
        dp1++;
        dp2++;
    }
}
