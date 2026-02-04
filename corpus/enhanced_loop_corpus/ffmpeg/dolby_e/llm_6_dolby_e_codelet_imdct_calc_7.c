#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float *res = result;
    int nn = n;
    for (i = 0; i < n2; i++) {
        res[i] = -res[nn - i - 1];
    }
}
