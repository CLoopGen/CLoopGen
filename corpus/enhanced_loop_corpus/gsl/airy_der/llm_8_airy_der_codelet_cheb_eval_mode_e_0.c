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
    int stride = 2;
    for (j = eval_order; j >= 1; j -= stride) {
        double temp1 = d;
        d = y2 * d - dd + cs->c[j];
        dd = temp1;
        if (j - 1 >= 1) {
            double temp2 = d;
            d = y2 * d - dd + cs->c[j-1];
            dd = temp2;
        }
    }
}
