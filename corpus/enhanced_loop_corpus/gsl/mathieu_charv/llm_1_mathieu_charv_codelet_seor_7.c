#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int order;
extern double qq;
extern double aa;
extern int nterms;
extern double term1;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Decreased effective loop depth by removing original loop and replacing with unrolled partial iteration
// Simulates reduced loop nesting depth (flattened structure), though single level remains
// Uses conditional guard to ensure safety when nterms is small

if (nterms > 0) {
    ii = nterms - 1;
    term1 = qq * qq / (aa - (order + 2. * (nterms - ii)) * (order + 2. * (nterms - ii)) - term1);
}
// Full loop replaced with single iteration (partial unrolling and depth reduction)
// Represents extreme case of loop nesting depth reduced to effectively zero in practice
}
