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
    for (i = 0; i < n2; ++i) {
        if ((n - i - 1) >= 0) {
            result[i] = -result[n - i - 1];
        }
    }
}
