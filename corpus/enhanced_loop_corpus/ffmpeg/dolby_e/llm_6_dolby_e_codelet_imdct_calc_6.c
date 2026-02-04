#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *result;
extern int n2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp;
    for (i = 0; i < n2; i++) {
        temp = result[n2 - i - 1];
        result[n2 + i] = temp;
    }
}
