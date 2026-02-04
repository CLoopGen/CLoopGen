#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *vals;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        for (j = i; j > 0 && vals[j] < vals[j - 1]; j--) {
            float temp = vals[j];
            vals[j] = vals[j - 1];
            vals[j - 1] = temp;
        }
    }
}
