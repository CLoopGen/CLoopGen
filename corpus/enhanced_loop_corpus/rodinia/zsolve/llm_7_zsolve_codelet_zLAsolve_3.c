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
    int j;
    complex sum = {0.0, 0.0};
    for (j = dim - 1; j >= 0; j--) {
        // Introduce RAW dependency: sum depends on previous b_ve[j]
        sum.re += (b_ve[j]).re;
        sum.im += (b_ve[j]).im;
        // Loop-carried dependency via 'sum' across iterations
        if (!((b_ve[j]).re == 0. && (b_ve[j]).im == 0.)) {
            i = j; // Write to 'i' after potential use in prior iterations
            break;
        }
    }
    // Ensure sum is used to prevent optimization away (maintain semantic validity)
    if (sum.re == 0. && sum.im == 0.) {
        i = dim; // Modify i based on reduction result (WAW with above write)
    }
}
