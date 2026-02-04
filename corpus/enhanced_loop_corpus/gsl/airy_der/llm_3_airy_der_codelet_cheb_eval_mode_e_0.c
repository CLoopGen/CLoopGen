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

extern double y2;
extern int eval_order;
extern  cheb_series *cs;
extern int j;
extern double d;
extern double dd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive forward array access using reversed indexing via offset
    // Reorder loop to go forward but access coefficients in reverse order consecutively
    double *coeffs = cs->c;
    for (j = 1; j <= eval_order; j++) {
        double temp = d;
        // Access coefficients from last to first (reverse order), but loop forward
        d = y2 * d - dd + coeffs[eval_order - j + 1];
        dd = temp;
    }
}
