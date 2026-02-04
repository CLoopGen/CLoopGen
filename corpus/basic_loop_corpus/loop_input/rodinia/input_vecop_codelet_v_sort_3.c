#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

double *x_ve;
double tmp;
double v;
int i;
int j;
int l;
int r;
int tmp_i;
int stack[60];
int sp;

PERM *order;

static double *x_ve_data;
static u_int *perm_data;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB for x_ve (1M doubles), balances runtime to ~0.01s

    x_ve_data = (double*)calloc(data_size, sizeof(double));
    perm_data = (u_int*)malloc(data_size * sizeof(u_int));

    if (!x_ve_data || !perm_data) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        x_ve_data[idx] = drand48() * 1000.0;
        perm_data[idx] = (u_int)idx;
    }

    x_ve = x_ve_data;

    order = (PERM*)malloc(sizeof(PERM));
    if (!order) {
        exit(1);
    }
    order->size = (u_int)data_size;
    order->max_size = (u_int)data_size;
    order->pe = perm_data;

    l = 0;
    r = (int)(data_size - 1);
    sp = 0;
    tmp = 0.0;
    v = 0.0;
    i = 0;
    j = 0;
    tmp_i = 0;
}