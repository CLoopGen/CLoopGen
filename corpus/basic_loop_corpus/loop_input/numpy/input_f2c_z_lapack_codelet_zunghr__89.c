#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef int integer;
typedef double doublereal;

typedef struct {
    doublereal r;
    doublereal i;
} doublecomplex;

integer *n;
doublecomplex *a;
integer a_dim1;
integer i__1;
integer i__2;
integer i__3;
integer i__;
integer j;

void init_vars() {
    const int target_time_ms = 10;
    double cpu_frequency_giga = 3.0;
    double operations_per_cycle = 1.0;
    double estimated_ops_per_inner_loop = 5.0;
    size_t total_operations = (size_t)(cpu_frequency_giga * 1e9 * target_time_ms / 1e3 / estimated_ops_per_inner_loop);

    int n_val = (int)sqrt((double)total_operations);
    if (n_val < 100) n_val = 100;
    n_val = (n_val + 63) & ~63;

    n = (integer*)malloc(sizeof(integer));
    *n = n_val;

    a_dim1 = *n;
    i__1 = *n;

    size_t a_size = (*n + 1) * (size_t)(*n + 1);
    a = (doublecomplex*)calloc(a_size, sizeof(doublecomplex));

    i__ = 1;
    j = 1;
    i__2 = 1;
    i__3 = 1;
}