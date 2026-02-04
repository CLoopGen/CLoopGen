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
    if (eval_order <= 0) return;
    double temp;
    for (j = eval_order; j >= 1; j--) {
        temp = d;
        d = y2 * d - dd + cs->c[j];
        dd = temp;
    }
}
