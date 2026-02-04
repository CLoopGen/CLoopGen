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
    for (i = 0; i < len - 1; i++) {
        float temp = vals[i + 1];
        for (j = i; j >= 0 && vals[j] > temp; j--) {
            vals[j + 1] = vals[j];
        }
        vals[j + 1] = temp;
    }
}
