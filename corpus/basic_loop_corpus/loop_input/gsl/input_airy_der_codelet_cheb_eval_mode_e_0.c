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

double y2 = 1.5;
int eval_order = 1000000;
cheb_series *cs;
int j;
double d = 0.0;
double dd = 0.0;

void init_vars() {
    cs = (cheb_series*)malloc(sizeof(cheb_series));
    cs->order = eval_order;
    cs->a = -1.0;
    cs->b = 1.0;
    cs->order_sp = eval_order;
    cs->c = (double*)malloc((eval_order + 1) * sizeof(double));
    for (int i = 0; i <= eval_order; i++) {
        cs->c[i] = (double)(i % 100) / 100.0;
    }
}