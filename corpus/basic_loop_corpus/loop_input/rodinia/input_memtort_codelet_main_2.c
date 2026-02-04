#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int dim;
    int fix_dim;
    double (*a)[2];
} FOO_2;

int i;
int j;

double (*malloced_data)[2];
FOO_2 *foo_2;

void init_vars() {
    foo_2 = (FOO_2 *)malloc(sizeof(FOO_2));
    foo_2->dim = 8192;
    foo_2->fix_dim = 2;

    malloced_data = (double (*)[2])calloc(foo_2->dim, sizeof(double[2]));
    foo_2->a = malloced_data;
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}