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
extern complex *b_ent;
extern complex *out_ent;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, traversing backwards)
    for (i = ((dim - 1) | 1); i >= 0; i -= 2) {
        if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.)) {
            break;
        } else {
            out_ent[i].re = out_ent[i].im = 0.;
        }
        // Handle the intermediate element if within bounds
        if (i > 0) {
            if (!((b_ent[i-1]).re == 0. && (b_ent[i-1]).im == 0.)) {
                i++; // Adjust index so loop condition breaks correctly after decrement
                break;
            } else {
                out_ent[i-1].re = out_ent[i-1].im = 0.;
            }
        }
    }
    // Resume linear cleanup from the point of break if needed
    for (; i >= 0; i--) {
        if (!((b_ent[i]).re == 0. && (b_ent[i]).im == 0.))
            break;
        else
            out_ent[i].re = out_ent[i].im = 0.;
    }
}
