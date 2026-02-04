#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern int i;
extern complex *b_ve;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = dim - 1; i >= 0; i -= 2) {
        if (i < dim && !((b_ve[i]).re == 0. && (b_ve[i]).im == 0.))
            break;
        if (i > 0 && !((b_ve[i-1]).re == 0. && (b_ve[i-1]).im == 0.)) {
            i--; 
            break;
        }
    }
}
