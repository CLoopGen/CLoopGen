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
    // Variant 1: Increased computational intensity with unrolled operations and reduced trip count
    // Unroll by factor of 2: process two iterations per loop cycle, reducing total iterations
    int j;
    double temp;
    for (j = eval_order; j >= 2; j -= 2) {
        // First iteration of unrolled pair
        temp = d;
        d = y2 * d - dd + cs->c[j];
        dd = temp;

        // Second iteration
        temp = d;
        d = y2 * d - dd + cs->c[j-1];
        dd = temp;
    }
    // Handle leftover iteration if eval_order is odd
    if (j == 1) {
        temp = d;
        d = y2 * d - dd + cs->c[1];
        dd = temp;
    }
}
