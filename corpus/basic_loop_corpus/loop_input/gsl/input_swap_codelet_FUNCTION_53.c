#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

size_t K;
size_t i;
size_t j;

void init_vars() {
    double estimated_ops = 1e7;
    K = (size_t)(sqrt(estimated_ops) * 1.5);
}