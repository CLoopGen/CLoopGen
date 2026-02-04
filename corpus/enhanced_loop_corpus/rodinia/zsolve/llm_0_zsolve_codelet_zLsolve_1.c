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
    u_int j;
    for (i = 0; i < dim; i++) {
        for (j = 0; j < 1; j++) { // Increased loop depth: introduced trivial inner loop
            if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
                break;
            else
                out_ent[i].re = out_ent[i].im = 0.;
        }
    }
}
