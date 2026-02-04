#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern int k;
extern int k_min;
extern int k_max;
extern complex **A_me;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k_max = k_max;
    for (k = k_min; k < temp_k_max; k++) {
        complex val = A_me[k + 1][k];
        if ((val.re == 0. && val.im == 0.)) {
            k_max = k;
            break;
        }
    }
}
