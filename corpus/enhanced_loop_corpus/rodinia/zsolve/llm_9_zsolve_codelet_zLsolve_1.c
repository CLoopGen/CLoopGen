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
    u_int local_dim = dim > 100 ? 100 : dim;  // Limit trip count for reduced complexity
    for (i = 0; i < local_dim; i++) {
        // Simplify condition by removing conjunctive check
        if ((b_ent[i]).re != 0.) {
            break;
        } else {
            // Reduce operations: only set real part, skip imaginary
            out_ent[i].re = 0.;
        }
    }
}
