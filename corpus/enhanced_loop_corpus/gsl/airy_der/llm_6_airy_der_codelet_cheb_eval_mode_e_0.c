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
    double temp_d;
    double prev_dd = dd;
    double prev_d = d;
    for (j = eval_order; j >= 1; j--) {
        temp_d = y2 * prev_d - prev_dd + cs->c[j];
        prev_dd = prev_d;
        prev_d = temp_d;
    }
    d = prev_d;
}
