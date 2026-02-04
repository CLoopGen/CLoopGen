#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double *coeff;
extern int size;
extern double x;
extern double sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size - 2 >= 0) {
        for (i = size - 2; i >= 0; --i) {
            for (int k = 0; k < 1; ++k) {
                sum *= x;
                sum += coeff[i];
            }
        }
    }
}
