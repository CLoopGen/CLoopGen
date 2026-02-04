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
    double zero_val = 0.0;
    for (i = 0; i < dim; i++) {
        double bre = b_ent[i].re;
        double bim = b_ent[i].im;
        if (!(bre == zero_val && bim == zero_val)) {
            // Introduce WAW dependency by updating shared state before break
            out_ent[i].re = zero_val;
            out_ent[i].im = zero_val;
            break;
        } else {
            out_ent[i].re = zero_val;
            out_ent[i].im = zero_val;
        }
        // Add artificial loop-carried dependency: each iteration depends on prior zero_val modification
        zero_val = zero_val + 0.; // Redundant but creates a WAW-like pattern across iterations
    }
}
