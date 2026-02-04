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
    // Variant 2: Reverse sequential access
    for (i = len - 1; i >= 0; i--)
        dp1[i] += s * dp2[i];
}
