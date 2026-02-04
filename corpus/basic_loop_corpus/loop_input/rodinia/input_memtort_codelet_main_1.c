#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    int dim;
    int fix_dim;
    double (*a)[10];
} FOO_1;

int i;
int j;

double (*alloc_a)[10];
FOO_1 *foo_1;

void init_vars() {
    foo_1 = (FOO_1*)malloc(sizeof(FOO_1));
    foo_1->dim = 20000;      
    foo_1->fix_dim = 10;     

    alloc_a = (double(*)[10])calloc(foo_1->dim, sizeof(double[10]));
    foo_1->a = alloc_a;
}