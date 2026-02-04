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
    double prev_d = d;
    double prev_dd = dd;
    double new_d, new_dd;
    for (j = eval_order; j >= 1; j--) {
        new_d = y2 * prev_d - prev_dd + cs->c[j];
        new_dd = prev_d;
        prev_d = new_d;
        prev_dd = new_dd;
    }
    d = new_d;
    dd = new_dd;
}
