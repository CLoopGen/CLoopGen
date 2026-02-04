#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct SwsVector {
    double *coeff;
    int length;
} SwsVector;

extern SwsVector *a;
extern int i;
extern double min;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (a->length > 0) {
        i = 0;
        for (; i < a->length; i++) {
            if (a->coeff[i] < min)
                min = a->coeff[i];
        }
    }
}
