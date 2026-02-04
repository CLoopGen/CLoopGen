#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int nthreads;
int th_count[4];
int temp;

void init_vars() {
    nthreads = 4;
    temp = 0;
}