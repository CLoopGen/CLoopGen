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
    // Variant 2: Reduced arithmetic density with extended trip count and simplified per-iteration work
    size_t extended_order = cs->order * 2;  // Double the trip count for higher loop overhead

    for (i = extended_order; i >= 1; i--) {
        if (i % 2 == 1) {
            // Only perform original logic on odd steps, simulating lower compute density
            double temp = d1;
            d1 = y2 * d1 - d2;
            d2 = temp;
        } else {
            // On even steps, incorporate coefficient using alternate indexing
            size_t idx = (extended_order - i) / 2 + 1;
            if (idx <= cs->order) {
                d1 = d1 + cs->c[idx]; // Add coefficient in a staggered way
            }
        }
    }
}
