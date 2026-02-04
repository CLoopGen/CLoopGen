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
    double temp_d, temp_dd;
    temp_d = d;
    temp_dd = dd;
    for (j = eval_order; j >= 1; j--) {
        double c_val = cs->c[j];
        temp_dd = temp_d;
        temp_d = y2 * temp_d - temp_dd + c_val;
    }
    d = temp_d;
    dd = temp_dd;
}
