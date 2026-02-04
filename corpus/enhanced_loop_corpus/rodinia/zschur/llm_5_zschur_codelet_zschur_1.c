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
    for (k = k_min; k < k_max; k++) {
        double re_val = (A_me[k + 1][k]).re;
        double im_val = (A_me[k + 1][k]).im;
        if (!(re_val == 0. && im_val == 0.)) {
            k_max = k + 1;
        } else {
            k_max = k;
            break;
        }
    }
}
