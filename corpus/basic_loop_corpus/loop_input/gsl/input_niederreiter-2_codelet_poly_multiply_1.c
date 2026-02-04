#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int k;
int pt_degree = 50;

int pc[51];
int pt[51];

void init_vars() {
    for (int i = 0; i <= pt_degree; i++) {
        pt[i] = rand() % 1000;
    }
}