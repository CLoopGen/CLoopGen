#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int pa[51];
int pb[51];
int j;
int k;
int pt[51];
int pt_degree;

void init_vars() {
    pt_degree = 50;
    for (int i = 0; i <= pt_degree; i++) {
        pa[i] = rand() % 2;
        pb[i] = rand() % 2;
        pt[i] = 0;
    }
    j = 0;
    k = 0;
}