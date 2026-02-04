#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_cheb_series_struct {
    double *c;
    size_t order;
    double a;
    double b;
    size_t order_sp;
    double *f;
};


typedef struct gsl_cheb_series_struct gsl_cheb_series;

extern  gsl_cheb_series *cs;
extern size_t i;
extern double d1;
extern double d2;
extern double y2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations and increased trip count via expanded iterations
    size_t expanded_order = cs->order * 2;
    for (i = expanded_order; i >= 1; i--) {
        if (i % 2 == 1) {
            // Every odd step updates d1 with a simplified dependency
            d1 = y2 * d1 + cs->c[(i + 1) / 2];
        } else {
            // Every even step updates d2 using delayed dependency
            double temp = d1;
            d1 = d1 - d2;
            d2 = temp;
        }
    }
}
