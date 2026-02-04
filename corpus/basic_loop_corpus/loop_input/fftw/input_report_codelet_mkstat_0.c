#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

struct stats {
    double min;
    double max;
    double avg;
    double median;
};

struct stats *a;
int i;
double *t;
int st;

void init_vars() {
    st = 10000000;  // 10 million elements, ~76MB for double array

    t = (double *)malloc(st * sizeof(double));
    if (!t) {
        exit(1);
    }

    a = (struct stats *)malloc(sizeof(struct stats));
    if (!a) {
        exit(1);
    }

    a->min = 1e300;
    a->max = -1e300;
    a->avg = 0.0;
    a->median = 0.0;

    for (int j = 0; j < st; ++j) {
        t[j] = (double)(rand() % 100000) / 10.0;
    }
}