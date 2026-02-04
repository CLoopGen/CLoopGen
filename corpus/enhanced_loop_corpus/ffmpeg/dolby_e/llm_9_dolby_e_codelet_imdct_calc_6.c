#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < n2 * 2; i++) {
        j = i / 2;
        if (i % 2 == 0) {
            result[n2 + j] = result[n2 - j - 1] * 1.5f;
        } else {
            result[n2 + j] = (result[n2 + j] + result[n2 - j - 1]) * 0.5f;
        }
    }
}
