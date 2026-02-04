#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *a;
extern  float *b;
extern int length;
extern float sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (length > 0) {
        i = 0;
        for (; i < length; i++) {
            sum += a[i] * b[i];
        }
    }
}
