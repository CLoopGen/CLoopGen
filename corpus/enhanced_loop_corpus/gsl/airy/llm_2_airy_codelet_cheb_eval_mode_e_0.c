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
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing cs->c[j] directly in descending order, we simulate a strided access
    // by introducing a stride variable (e.g., stride = 2) and adjusting the index accordingly.
    // We ensure j still iterates correctly by stepping with the stride and bounds checking.
    int stride = 2;
    for (j = eval_order; j >= 1; j -= stride) {
        double temp = d;
        d = y2 * d - dd + cs->c[j];
        dd = temp;

        // Handle intermediate index if stride allows and within bounds
        if (j - 1 >= 1) {
            temp = d;
            d = y2 * d - dd + cs->c[j - 1];
            dd = temp;
        }
    }
}
