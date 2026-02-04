#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int nthreads = 4;
int th_count[4];
int temp;

void init_vars() {
    i = 0;
    temp = 0;
}