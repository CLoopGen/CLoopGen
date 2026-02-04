#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    double re;
    double im;
} complex;

extern u_int dim;
extern u_int i;
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    u_int outer_i;
    for (outer_i = 0; outer_i < dim; outer_i++) {
        i = outer_i; // Maintain use of global 'i' as in original
        if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
            break;
        else
            out_ent[i].re = out_ent[i].im = 0.;
    }
}
