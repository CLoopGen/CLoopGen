#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double count[100];
double edge[100];
int i;

void init_vars() {
    for (int idx = 0; idx < 100; idx++) {
        count[idx] = (double)(idx * 7 % 13);
        edge[idx] = (double)(idx * 11 % 17);
    }
}