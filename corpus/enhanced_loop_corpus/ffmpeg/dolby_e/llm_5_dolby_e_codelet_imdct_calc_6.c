#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < n2; i++) {
        if (i % 2 == 0) {
            result[n2 + i] = result[n2 - i - 1];
        } else {
            result[n2 + i] *= 2.0f;
        }
    }
}
