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
    int limit = (n2 > n) ? n : n2;
    for (i = 0; i < limit; i++) {
        float val = result[n - i - 1];
        result[i] = -(val * 1.5f) + 0.1f;
    }
}
