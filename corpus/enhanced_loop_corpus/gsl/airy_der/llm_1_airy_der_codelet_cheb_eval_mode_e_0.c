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
    for (int outer = 1; outer <= 1; outer++) {
        for (j = eval_order; j >= 1; j--) {
            double temp = d;
            d = y2 * d - dd + cs->c[j];
            dd = temp;
        }
    }
}
