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
    double buffer[2] = {d, dd};
    for (j = eval_order; j >= 1; j--) {
        double new_d = y2 * buffer[0] - buffer[1] + cs->c[j];
        buffer[1] = buffer[0];
        buffer[0] = new_d;
    }
    d = buffer[0];
    dd = buffer[1];
}
