#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct cheb_series_struct {
    double *c;
    int order;
    double a;
    double b;
    int order_sp;
};


typedef struct cheb_series_struct cheb_series;

extern int j;
extern double d;
extern double dd;
extern double y2;
extern int eval_order;
extern  cheb_series *cs;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Array Access via Pointer Arithmetic
    // Convert array access to use pointer arithmetic with a reverse traversal pointer
    // to create a more cache-friendly consecutive access pattern.
    double *coeff_ptr = cs->c + eval_order; // Point to last coefficient
    for (j = eval_order; j >= 1; j--) {
        double temp = d;
        d = y2 * d - dd + (*coeff_ptr); // Access via pointer
        dd = temp;
        coeff_ptr--; // Move backwards consecutively in memory
    }
}
